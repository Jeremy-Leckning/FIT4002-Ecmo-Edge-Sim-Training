/* resource naming
 * module for generating resource names and tags by preconcatenating values as local variables
 * version 0.13
 */
#############################################
# resource_naming module
#############################################
# resource_naming (toggle) - module for generating resource names and tags
variable "enabled" {
  type        = string
  default     = "true"
  description = "Toggle to false to prevent the module from creating any resources" 
}

# resource_naming (configuration) - module for generating resource names and tags
variable "delimiter" {
  type        = string
  default     = "-"
  description = "Delimiter to be used between name components such as `app_name` and `environment`" 
}

variable "invalid_chars" {
  type        = string
  default     = "/[^a-zA-Z0-9@._,-]/"
  description = "Invalid characters to be replaced with an empty string in generated name components" 
}

# resource_naming (variables) - module for generating resource names and tags
variable "app_name" {
  type        = string
  default     = "ecmo-application"
  description = "Name of application that resources belong to" 
}

variable "environment" {
  type        = string
  default     = "dev"
  description = "Environment of application that resources belong to" 
}

variable "attributes" {
  type        = list(string)
  default     = []
  description = "List of additional attributes for the resource being created" 
}

# resource_naming (tagging) - module for generating resource names and tags
variable "tags" {
  type        = map(string)
  default     = {}
  description = "Tags for resources (eg. `map('Environment', 'dev')`)"
}

variable "additional_tag_map_list" {
  type        = list(map(string))
  default     = []
  description = "Additional tags for appending to each tag map (eg. `propagate_at_launch = 'true'`)"
}

# resource_naming (naming_convention) - module for generating resource names and tags
variable "label_order" {
  type        = list(string)
  default     = ["app_name", "environment"]
  description = "Default naming convention for resources"
}
