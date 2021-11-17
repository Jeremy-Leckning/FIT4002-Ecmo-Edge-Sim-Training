/* resource naming
 * module for generating resource names and tags by preconcatenating values as local variables
 * version 0.13
 */
#############################################
# resource_naming module
#############################################
output "id" {
  value       = local.enabled ? local.id : ""
  description = "Resource ID"
}

output "app_name" {
  value       = local.enabled ? local.app_name : ""
  description = "Name of application that resources belong to"
}

output "environment" {
  value       = local.enabled ? local.environment : ""
  description = "Environment of application that resources belong to"
}

output "attributes" {
  value       = local.attributes
  description = "List of additional attributes for the resource being created"
}

output "delimiter" {
  value       = local.enabled ? local.delimiter : ""
  description = "Delimiter to be used between name components such as `app_name` and `environment`"
}

output "tags" {
  value       = local.tags
  description = "Tag map for created resources"
}

output "tag_map_list" {
  value       = [local.tag_map_list]
  description = "Tags as a list of Terraform maps that apply to the created resources"
}

output "label_order" {
  value       = local.label_order_final_list
  description = "Naming convention of resources for this module"
}
