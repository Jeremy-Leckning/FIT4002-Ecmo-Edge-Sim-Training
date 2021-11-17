/* resource naming
 * module for generating resource names and tags by preconcatenating values as local variables
 * version 0.13
 */
#############################################
# resource_naming module
#############################################
locals{
  # resource_naming (toggle) - module for generating resource names and tags
  enabled     = var.enabled

  # resource_naming (configuration) - module for generating resource names and tags
  delimiter   = var.delimiter != "" ? var.delimiter : "-"

  # resource_naming (variables) - module for generating resource names and tags
  app_name    = lower(replace(var.app_name, var.invalid_chars, ""))
  environment = lower(replace(var.environment, var.invalid_chars, ""))
  attributes  = compact(var.attributes)

  # resource_naming (tagging) - module for generating resource names and tags
  generated_tags  = zipmap(
    [
      "Application",
      "Environment"
    ],
    [
      local.id,
      local.environment
    ]
  )
  tags            = merge(local.generated_tags, var.tags)
  tag_map_list    = concat(
    [for tag_key in keys(local.tags) : {
      "key"   = tag_key
      "value" = local.tags[tag_key]
    }],
    var.additional_tag_map_list
  )

  # resource_naming (naming_convention) - module for generating resource names and tags
  label_order_default_list  = [
    "app_name",
    "environment"
  ]
  label_order_final_list    = distinct(
    compact(
      coalescelist(var.label_order, local.label_order_default_list)
    )
  )
  label_order_length        = length(local.label_order_final_list)

  # resource_naming (context) - module for generating resource names and tags
  output_context = {
    app_name    = [local.app_name]
    environment = [local.environment]
    attributes  = [local.attributes]
    tag_keys    = [keys(local.tags)]
    tag_values  = [values(local.tags)]
    delimiter   = [local.delimiter]
    label_order = [local.label_order_final_list]
  }
  id_context = {
    app_name    = local.app_name
    environment = local.environment
    attributes  = join(local.delimiter, local.attributes)
  }
  id = lower(
    join(
      local.delimiter,
      compact(
        [
          local.label_order_length > 0 ? local.id_context[element(local.label_order_final_list, 0)] : "",
          local.label_order_length > 1 ? local.id_context[element(local.label_order_final_list, 1)] : ""
        ]
      )
    )
  )
}
