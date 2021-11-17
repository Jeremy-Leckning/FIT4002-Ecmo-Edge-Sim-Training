/* ecmo_api
 * api for ecmo
 * version 0.13
 */

##################################################
# provider
##################################################
provider "aws" {
  profile = "ecmo_provisioner"
  region = var.aws_region
}

##################################################
# local variable declaration
##################################################
locals {
  computed_ecmo_api_apigatewayv2_api_integrations = [
    for integration in var.ecmo_api_apigatewayv2_api_integrations : {
      "integration_method"  = "POST"
      "integration_uri"     = module.crud_lambda.invoke_arn[0]
      "integration_type"    = "AWS_PROXY"
      "method"              = lookup(integration, "method", "ANY")
      "resource_path"       = lookup(integration, "resource_path", "/")
    }
  ]
}

##################################################
# resource naming
##################################################
module "resource_naming" {
  source = "../../modules/resource_naming"
  # resource_naming (toggle) - module for generating resource names and tags
  enabled                 = var.enable_resource_naming
  # resource_naming (variables) - module for generating resource names and tags
  app_name                = var.app_name
  environment             = var.environment
  attributes              = []
  # resource_naming (tagging) - module for generating resource names and tags
  tags                    = {}
  additional_tag_map_list = []
  label_order             = ["app_name", "environment"]
}

##################################################
# ecmo api gateway
##################################################
module "apigatewayv2_api" {
  source = "../../modules/api_gateway"
  create_apigatewayv2_api         = var.create_apigatewayv2_api
  apigatewayv2_api_name           = "${module.resource_naming.id}-http-api"
  apigatewayv2_api_description    = "${module.resource_naming.id}-http-api"
  apigatewayv2_api_protocol_type  = var.ecmo_api_apigatewayv2_api_protocol_type
  apigatewayv2_api_integrations   = local.computed_ecmo_api_apigatewayv2_api_integrations
  tags  = module.resource_naming.tags
}

module "crud_lambda" {
  source = "../../modules/lambda"

  # crud api (meta-arguments) - lambda function
  aws_region      = var.aws_region
  aws_account_id  = var.aws_account_id
  tags            = module.resource_naming.tags

  # crud api (function) - lambda function
  create_lambda_function            = var.create_lambda_function
  lambda_function_name              = "${module.resource_naming.id}-lambda-function"
  lambda_function_description       = "${module.resource_naming.id}-lambda-function"
  lambda_function_handler           = var.ecmo_api_lambda_function_handler
  lambda_function_runtime           = var.ecmo_api_lambda_function_runtime
  lambda_function_source_code_path  = var.lambda_function_source_code_path

  # crud api (execution role) - lambda function execution role
  create_lambda_execution_role    = var.create_lambda_execution_role
  lambda_execution_role_name      = "${module.resource_naming.id}-lambda-execution-role"
  trust_policy_custom_statements  = var.ecmo_api_lambda_execution_role_trust_policy_custom_statements
}

module "crud_lambda_dynamo_policy" {
  source = "../../modules/iam_policy"

  # crud api (dynamo_policy) - lambda function
  create_iam_policy     = var.create_crud_lambda_dynamo_policy   
  iam_policy_name       = var.crud_lambda_dynamo_policy_name      
  policy_file_path      = var.crud_lambda_dynamo_policy_file_path
  policy_file_variables = {
    aws_region            = var.aws_region
    aws_account_id        = var.aws_account_id
    lambda_function_name  = "${module.resource_naming.id}-lambda-function"
    api_id                = module.apigatewayv2_api.id[0]
  } 
  attach_policy         = var.attach_crud_lambda_dynamo_policy        
  target_iam_role_name  = module.crud_lambda.execution_role_name[0]
}

resource "aws_lambda_permission" "crud_lambda_permission" {
  statement_id  = "AllowCrudApiInvocation"
  action        = "lambda:InvokeFunction"
  function_name = "${module.resource_naming.id}-lambda-function"
  principal     = "apigateway.amazonaws.com"

  source_arn = "${module.apigatewayv2_api.execution_arn[0]}/*/*/*"
}

##################################################
# ecmo dynamo tables
##################################################
module "ecmo_textbook_dynamo_table" {
  source = "../../modules/dynamo_table_provisioned"
  # ecmo dynamo tables (textbook) - tables for storing data in dynamo db
  create_dynamodb_table         = var.create_ecmo_dynamo_tables
  dynamodb_table_name           = "${module.resource_naming.id}-textbook-dynamo-table"  
  dynamodb_table_read_capacity  = var.ecmo_textbook_dynamo_table_read_capacity
  dynamodb_table_write_capacity = var.ecmo_textbook_dynamo_table_write_capacity
  dynamodb_table_hash_key       = var.ecmo_textbook_dynamo_table_hash_key

  tags                          = module.resource_naming.tags
}

module "ecmo_scenario_dynamo_table" {
  source = "../../modules/dynamo_table_provisioned"
  # ecmo dynamo tables (sceanrio) - tables for storing data in dynamo db
  create_dynamodb_table         = var.create_ecmo_dynamo_tables
  dynamodb_table_name           = "${module.resource_naming.id}-scenario-dynamo-table"  
  dynamodb_table_read_capacity  = var.ecmo_scenario_dynamo_table_read_capacity
  dynamodb_table_write_capacity = var.ecmo_scenario_dynamo_table_write_capacity
  dynamodb_table_hash_key       = var.ecmo_scenario_dynamo_table_hash_key

  tags                          = module.resource_naming.tags
}
