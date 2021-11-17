/* terraform api_gateway module
 */
resource "aws_cloudwatch_log_group" "apigatewayv2_api_logging" {
  name              = "/aws/apigateway/${var.apigatewayv2_api_name}"
  retention_in_days = 30
  tags              = var.tags
}

resource "aws_apigatewayv2_api" "apigatewayv2_api" {
  count         = var.create_apigatewayv2_api ? 1 : 0
  name          = var.apigatewayv2_api_name
  description   = var.apigatewayv2_api_description
  protocol_type = var.apigatewayv2_api_protocol_type
  tags          = var.tags
}

resource "aws_apigatewayv2_integration" "apigatewayv2_api_integration" {
  count                   = var.create_apigatewayv2_api ? length(var.apigatewayv2_api_integrations) : 0
  api_id                  = aws_apigatewayv2_api.apigatewayv2_api[0].id
  integration_type        = var.apigatewayv2_api_integrations[count.index].integration_type
  payload_format_version  = "2.0"

  integration_method      = var.apigatewayv2_api_integrations[count.index].integration_method
  integration_uri         = var.apigatewayv2_api_integrations[count.index].integration_uri
}

resource "aws_apigatewayv2_route" "apigatewayv2_api_route" {
  count     = var.create_apigatewayv2_api ? length(var.apigatewayv2_api_integrations) : 0
  api_id    = aws_apigatewayv2_api.apigatewayv2_api[0].id
  route_key = "${var.apigatewayv2_api_integrations[count.index].method} ${var.apigatewayv2_api_integrations[count.index].resource_path}"

  target    = "integrations/${aws_apigatewayv2_integration.apigatewayv2_api_integration[count.index].id}"
}

resource "aws_apigatewayv2_stage" "apigatewayv2_api_stage" {
  api_id      = aws_apigatewayv2_api.apigatewayv2_api[0].id
  name        = "$default"
  auto_deploy = true
  access_log_settings {
    destination_arn = aws_cloudwatch_log_group.apigatewayv2_api_logging.arn
    format          = "{ \"requestId\":\"$context.requestId\", \"ip\": \"$context.identity.sourceIp\", \"requestTime\":\"$context.requestTime\", \"httpMethod\":\"$context.httpMethod\",\"routeKey\":\"$context.routeKey\", \"status\":\"$context.status\",\"protocol\":\"$context.protocol\", \"responseLength\":\"$context.responseLength\" }"
  }
  tags        = var.tags
}
