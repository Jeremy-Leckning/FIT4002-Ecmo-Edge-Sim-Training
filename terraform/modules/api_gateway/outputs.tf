
output "id" {
  description = "The API identifier."
  value       = aws_apigatewayv2_api.apigatewayv2_api.*.id
}

output "api_endpoint" {
  description = "The URI of the API, of the form https://{api-id}.execute-api.{region}.amazonaws.com for HTTP APIs and wss://{api-id}.execute-api.{region}.amazonaws.com for WebSocket APIs."
  value       = aws_apigatewayv2_api.apigatewayv2_api.*.api_endpoint
}

output "arn" {
  description = "The ARN of the API."
  value       = aws_apigatewayv2_api.apigatewayv2_api.*.arn
}

output "execution_arn" {
  description = "The ARN prefix to be used in an aws_lambda_permission's source_arn attribute or in an aws_iam_policy to authorize access to the @connections API. See the Amazon API Gateway Developer Guide for details."
  value       = aws_apigatewayv2_api.apigatewayv2_api.*.execution_arn
}
