/* ecmo_api
 * api for ecmo
 * version 0.13
 */

##################################################
# provider
##################################################
aws_account_id = "038872011293"
aws_region     = "ap-southeast-2"

##################################################
# resource naming
##################################################
# resource_naming (toggle) - module for generating resource names and tags
enable_resource_naming  = "true"
# resource_naming (variables) - module for generating resource names and tags
app_name                = "ecmo-api"
environment             = "dev"

##################################################
# ecmo api gateway
##################################################
create_apigatewayv2_api                 = true
ecmo_api_apigatewayv2_api_protocol_type = "HTTP"
ecmo_api_apigatewayv2_api_integrations  = [
  {
    method              = "GET"
    resource_path       = "/textbook/chapters"
  },
  {
    method              = "PUT"
    resource_path       = "/textbook/chapters"
  },
  {
    method              = "GET"
    resource_path       = "/textbook/chapters/{id}"
  },
  {
    method              = "POST"
    resource_path       = "/textbook/chapters"
  },
  {
    method              = "DELETE"
    resource_path       = "/textbook/chapters/{id}"
  },
  {
    method              = "GET"
    resource_path       = "/textbook/pages"
  },
  {
    method              = "PUT"
    resource_path       = "/textbook/pages"
  },
  {
    method              = "GET"
    resource_path       = "/textbook/pages/{id}"
  },
  {
    method              = "POST"
    resource_path       = "/textbook/pages"
  },
  {
    method              = "DELETE"
    resource_path       = "/textbook/pages/{id}"
  },
  {
    method              = "GET"
    resource_path       = "/scenario"
  },
  {
    method              = "PUT"
    resource_path       = "/scenario"
  },
  {
    method              = "GET"
    resource_path       = "/scenario/{id}"
  },
  {
    method              = "DELETE"
    resource_path       = "/scenario/{id}"
  }
]
# crud api (function) - lambda function
create_lambda_function            = true
ecmo_api_lambda_function_handler  = "index.handler"
ecmo_api_lambda_function_runtime  = "nodejs14.x"
lambda_function_source_code_path  = "assets/ecmo_api_lambdav2_package.zip"
# crud api (execution role) - lambda function execution role
create_lambda_execution_role      = true
ecmo_api_lambda_execution_role_trust_policy_custom_statements = <<EOF
{
  "Sid": "APIGatewayAssumption",
  "Action": "sts:AssumeRole",
  "Principal": {
    "Service": "apigateway.amazonaws.com"
  },
  "Effect": "Allow"    
}
EOF
# crud api (dynamo_policy) - lambda function
create_crud_lambda_dynamo_policy          = true
crud_lambda_dynamo_policy_name            = "ecmo-api-dev-lambda-dynamo-policy"
crud_lambda_dynamo_policy_file_path       = "templates/ecmo_api_lambda_dynamo_policy.json"
attach_crud_lambda_dynamo_policy          = true

##################################################
# ecmo dynamo tables
##################################################
create_ecmo_dynamo_tables                 = true
# ecmo dynamo tables (textbook) - tables for storing data in dynamo db
ecmo_textbook_dynamo_table_read_capacity  = 5
ecmo_textbook_dynamo_table_write_capacity = 5
ecmo_textbook_dynamo_table_hash_key       = {
  name  = "id"
  type  = "S"
}
# ecmo dynamo tables (sceanrio) - tables for storing data in dynamo db
ecmo_scenario_dynamo_table_read_capacity  = 20
ecmo_scenario_dynamo_table_write_capacity = 20
ecmo_scenario_dynamo_table_hash_key       = {
  name  = "id"
  type  = "S"
}
