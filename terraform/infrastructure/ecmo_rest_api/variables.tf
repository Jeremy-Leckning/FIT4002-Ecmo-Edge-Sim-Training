/* ecmo_pulse_engine_build
 * version 0.13
 */

##################################################
# provider
##################################################
variable "aws_region" {
  description = "AWS region for resource to be provisioned in. Please refer to `https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/Concepts.RegionsAndAvailabilityZones.html` for a complete list of regions." 
  type        = string
  default     = "ap-southeast-2"
}

variable "aws_account_id" {
  description = "AWS account id."
  type        = string
  default     = ""
}


##################################################
# resource naming
##################################################
# resource_naming (toggle) - module for generating resource names and tags
variable "enable_resource_naming" {
  description = "Toggle to enable or disable resource naming module. Allowed values: true | false"
  type        = string
  default     = "true"
}

# resource_naming (variables) - module for generating resource names and tags
variable "app_name" {
  description = "Name of application name for infrastructure provisioned by this Terraform code."
  type        = string
  default     = "ecmo-sim-api"
}

variable "environment" {
  description = "Name of environment provisioned by this Terraform code."
  type        = string
  default     = "dev"
}

##################################################
# ecmo api gateway
##################################################
variable "create_apigatewayv2_api" {
  description = "Boolean value to determine whether or not the api resource is created."
  type        = bool
  default     = true 
}

variable "ecmo_api_apigatewayv2_api_protocol_type" {
  description = "The API protocol. Valid values: HTTP, WEBSOCKET."
  type        = string
  default     = "HTTP" 
}

variable "ecmo_api_apigatewayv2_api_integrations" {
  description = "List of maps for storing details of API integrations and route details"
  type        = list(map(string))
  default     = []
}

variable "create_lambda_function" {
  description = "Boolean value to determine whether or not the lambda function is created."
  type        = bool
  default     = true 
}

variable "create_lambda_execution_role" {
  description = "Boolean value to determine whether or not the execution role is created."
  type        = bool
  default     = true 
}

variable "ecmo_api_lambda_function_handler" {
  description = "Function entrypoint in function code."
  type        = string
  default     = "index.handler" 
}

variable "ecmo_api_lambda_function_runtime" {
  description = "Identifier of the function's runtime. This value may be: nodejs | nodejs4.3 ... see https://docs.aws.amazon.com/lambda/latest/dg/lambda-runtimes.html"
  type        = string
  default     = "nodejs14.x" 
}

variable "lambda_function_source_code_path" {
  description = "Path to lambda function code package"
  type        = string
  default     = "ecmo_api_lambda_package.zip" 
}

variable "ecmo_api_lambda_execution_role_trust_policy_custom_statements" {
  description = "Additional policy statements for execution role trust policy"
  type        = string
  default     = "" 
}

# crud api (dynamo_policy) - lambda function
variable "create_crud_lambda_dynamo_policy" {
  description = "Boolean value to determine whether or not the lambda function is created."
  type        = bool
  default     = true 
}

variable "crud_lambda_dynamo_policy_name" {
  description = "Unique name for iam_policy"
  type        = string
  default     = ""
}

variable "crud_lambda_dynamo_policy_file_path" {
  description = "Region for where lambda function is to be created."
  type        = string
  default     = null
}

variable "crud_lambda_dynamo_policy_file_variables" {
  description = "AWS account id."
  type        = map
  default     = {}
}

variable "attach_crud_lambda_dynamo_policy" {
  description = "Boolean value to determine whether or not the lambda function is created."
  type        = bool
  default     = false 
}

##################################################
# ecmo dynamo tables
##################################################
variable "create_ecmo_dynamo_tables" {
  description = "Boolean value to determine whether or not the dynamo tables are created."
  type        = bool
  default     = true 
}

# ecmo dynamo tables (textbook) - tables for storing data in dynamo db
variable "ecmo_textbook_dynamo_table_read_capacity" {
  description = "Number representing the read capacity for the dynamo table"
  type        = number
  default     = 1
}

variable "ecmo_textbook_dynamo_table_write_capacity" {
  description = "Number representing the write capacity for the dynamo table"
  type        = number
  default     = 1
}

variable "ecmo_textbook_dynamo_table_hash_key" {
  description = "Map containing details for the hash key of dynamo table"
  type        = map(string)
  default     = {
    name  = "id"
    type  = "S"
  }
}

variable "ecmo_textbook_dynamo_table_range_key" {
  description = "Map containing details for the sort key of dynamo table"
  type        = map(string)
  default     = {
    name  = "chapter_id"
    type  = "S"
  }
}

# ecmo dynamo tables (sceanrio) - tables for storing data in dynamo db
variable "ecmo_scenario_dynamo_table_read_capacity" {
  description = "Number representing the read capacity for the dynamo table"
  type        = number
  default     = 1
}

variable "ecmo_scenario_dynamo_table_write_capacity" {
  description = "Number representing the write capacity for the dynamo table"
  type        = number
  default     = 1
}

variable "ecmo_scenario_dynamo_table_hash_key" {
  description = "Map containing details for the hash key of dynamo table"
  type        = map(string)
  default     = {
    name  = "id"
    type  = "S"
  }
}

variable "ecmo_scenario_dynamo_table_range_key" {
  description = "Map containing details for the sort key of dynamo table"
  type        = map(string)
  default     = {
    name  = "title"
    type  = "S"
  }
}
