/* lambda
 * module for  create lambda function without environment variables
 */
#############################################
# meta-arguments
#############################################
variable "aws_region" {
  description = "Region for where lambda function is to be created."
  type        = string
  default     = "ap-southeast-2"
}

variable "aws_account_id" {
  description = "AWS account id."
  type        = string
  default     = ""
}

variable "tags" {
  description = "A mapping of tags to assign to the resource"
  type        = map(string)
  default     = {}
}

#############################################
# lambda function module
#############################################
variable "create_lambda_function" {
  description = "Boolean value to determine whether or not the lambda function is created."
  type        = bool
  default     = true 
}

variable "lambda_function_name" {
  description = "Unique name for lambda function"
  type        = string
  default     = ""
}

variable "lambda_function_description" {
  description = "Description of what the lambda function does."
  type        = string
  default     = ""
}

variable "lambda_function_handler" {
  description = "Function entrypoint in function code."
  type        = string
  default     = "index.handler" 
}

variable "lambda_function_runtime" {
  description = "Identifier of the function's runtime. This value may be: nodejs | nodejs4.3 ... see https://docs.aws.amazon.com/lambda/latest/dg/lambda-runtimes.html"
  type        = string
  default     = "nodejs14.x" 
}

variable "lambda_function_source_code_path" {
  description = "Path to lambda function code package"
  type        = string
  default     = "lambda_package.zip" 
}

#############################################
# lambda function execution role
#############################################
variable "create_lambda_execution_role" {
  description = "Boolean value to determine whether or not the execution role is created."
  type        = bool
  default     = true 
}

variable "lambda_execution_role_name" {
  description = "String reperesenting name of lambda execution role"
  type        = string
  default     = "" 
}

variable "trust_policy_custom_statements" {
  description = "Additional policy statements for execution role trust policy"
  type        = string
  default     = "" 
}
