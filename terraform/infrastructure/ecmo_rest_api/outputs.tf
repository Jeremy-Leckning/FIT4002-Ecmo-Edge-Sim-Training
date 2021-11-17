/* ecmo_api
 * api for ecmo
 * version 0.13
 */

##################################################
# resource naming
##################################################
output "ecmo_api_naming_id" {
  value       = module.resource_naming.id
  description = "Resource ID"
}

output "ecmo_api_naming_app_name" {
  value       = module.resource_naming.app_name
  description = "Name of application that resources belong to"
}

output "ecmo_api_naming_environment" {
  value       = module.resource_naming.environment
  description = "Environment of application that resources belong to"
}

output "ecmo_api_naming_attributes" {
  value       = module.resource_naming.attributes
  description = "List of additional attributes for the resource being created"
}

output "ecmo_api_naming_delimiter" {
  value       = module.resource_naming.delimiter
  description = "Delimiter to be used between name components such as `app_name` and `environment`"
}

output "ecmo_api_naming_tags" {
  value       = module.resource_naming.tags
  description = "Tag map for created resources"
}

output "ecmo_api_naming_tag_map_list" {
  value       = module.resource_naming.tag_map_list
  description = "Tags as a list of Terraform maps that apply to the created resources"
}

output "ecmo_api_naming_label_order" {
  value       = module.resource_naming.label_order
  description = "Naming convention of resources for this module"
}

##################################################
# crud api
##################################################
output "ecmo_api_gateway_id" {
  description = "The API identifier."
  value       = module.apigatewayv2_api.id
}

output "ecmo_api_gateway_api_endpoint" {
  description = "The URI of the API, of the form https://{api-id}.execute-api.{region}.amazonaws.com for HTTP APIs and wss://{api-id}.execute-api.{region}.amazonaws.com for WebSocket APIs."
  value       = module.apigatewayv2_api.api_endpoint
}

output "ecmo_api_gateway_arn" {
  description = "The ARN of the API."
  value       = module.apigatewayv2_api.arn
}

output "ecmo_api_gateway_execution_arn" {
  description = "The ARN prefix to be used in an aws_lambda_permission's source_arn attribute or in an aws_iam_policy to authorize access to the @connections API. See the Amazon API Gateway Developer Guide for details."
  value       = module.apigatewayv2_api.execution_arn
}

output "ecmo_crud_api_function_arn" {
  description = "Amazon Resource Name (ARN) identifying the lambda function."
  value       = module.crud_lambda.function_arn
}

output "ecmo_crud_api_invoke_arn" {
  description = "ARN to be used for invoking lambda function from API Gasteway"
  value       = module.crud_lambda.invoke_arn
}

output "ecmo_crud_api_last_modified" {
  description = "Date this resource was last modified"
  value       = module.crud_lambda.last_modified
}

output "ecmo_crud_api_version" {
  description = "Latest published version of the Lambda Function"
  value       = module.crud_lambda.version
}

output "ecmo_crud_api_execution_role_arn" {
  description = "Amazon Resource Name (ARN) specifying the role."
  value       = module.crud_lambda.execution_role_arn
}

output "ecmo_crud_api_execution_role_id" {
  description = "ID of lambda execution role."
  value       = module.crud_lambda.execution_role_id
}

output "ecmo_crud_api_execution_role_name" {
  description = "Name of lambda execution role."
  value       = module.crud_lambda.execution_role_name
}

output "ecmo_crud_api_execution_role_unique_id" {
  description = "Stable and unique string identifying lambda execution role."
  value       = module.crud_lambda.execution_role_unique_id
}

output "ecmo_crud_api_execution_role_create_date" {
  description = "Creation date of lambda execution role."
  value       = module.crud_lambda.execution_role_create_date
}
