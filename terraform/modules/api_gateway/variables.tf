
variable "create_apigatewayv2_api" {
  description = "Boolean value to determine whether or not the api resource is created."
  type        = bool
  default     = true 
}

variable apigatewayv2_api_name {
  description = "The name of the API. Must be less than or equal to 128 characters in length."
  type        = string
  default     = "aws_http_api" 
}

variable apigatewayv2_api_description {
  description = "The description of the API. Must be less than or equal to 1024 characters in length."
  type        = string
  default     = "AWS HTTP API Gateway resource"
}

variable apigatewayv2_api_protocol_type {
  description = "The API protocol. Valid values: HTTP, WEBSOCKET."
  type        = string
  default     = "HTTP" 
}

variable apigatewayv2_api_integrations {
  description = "List of maps for storing details of API integrations and route details"
  type        = list(map(string))
  default     = []
}

variable "tags" {
  description = "A mapping of tags to assign to the resource"
  type        = map(string)
  default     = {}
}
