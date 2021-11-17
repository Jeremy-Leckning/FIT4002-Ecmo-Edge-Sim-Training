/* lambda
 * module for  create lambda function without environment variables
 * version 0.13
 */
#############################################
# lambda function module
#############################################
output "function_arn" {
  description = "Amazon Resource Name (ARN) identifying the lambda function."
  value       = aws_lambda_function.lambda_function.*.arn
}

output "invoke_arn" {
  description = "ARN to be used for invoking lambda function from API Gasteway"
  value       = aws_lambda_function.lambda_function.*.invoke_arn
}

output "last_modified" {
  description = "Date this resource was last modified"
  value       = aws_lambda_function.lambda_function.*.last_modified
}

output "version" {
  description = "Latest published version of the Lambda Function"
  value       = aws_lambda_function.lambda_function.*.version
}

#############################################
# lambda function execution role
#############################################
output "execution_role_arn" {
  description = "Amazon Resource Name (ARN) specifying the role."
  value       = aws_iam_role.lambda_execution_role.*.arn
}

output "execution_role_id" {
  description = "ID of lambda execution role."
  value       = aws_iam_role.lambda_execution_role.*.id
}

output "execution_role_name" {
  description = "Name of lambda execution role."
  value       = aws_iam_role.lambda_execution_role.*.name
}

output "execution_role_unique_id" {
  description = "Stable and unique string identifying lambda execution role."
  value       = aws_iam_role.lambda_execution_role.*.unique_id
}

output "execution_role_create_date" {
  description = "Creation date of lambda execution role."
  value       = aws_iam_role.lambda_execution_role.*.create_date
}
