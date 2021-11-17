/* dynamo table (provisioned) 
 * module for creating a dynamodb table
 * version 0.13
 */
locals {
  dynamodb_table_range_key_name     = lookup(var.dynamodb_table_range_key, "name", null)
  dynamodb_table_key_configurations = local.dynamodb_table_range_key_name == null ? [var.dynamodb_table_hash_key] : [var.dynamodb_table_hash_key, var.dynamodb_table_range_key]
}

#############################################
# dynamo table (provisioned) module
#############################################
resource "aws_dynamodb_table" "dynamodb_table" {
  count               = var.create_dynamodb_table ? 1 : 0

  name                = var.dynamodb_table_name
  billing_mode        = "PROVISIONED"
  read_capacity       = var.dynamodb_table_read_capacity
  write_capacity      = var.dynamodb_table_write_capacity
  hash_key            = lookup(var.dynamodb_table_hash_key, "name", "id")
  range_key           = lookup(var.dynamodb_table_range_key, "name", null)
  dynamic "attribute" {
    for_each = local.dynamodb_table_key_configurations
    content {
      name = attribute.value.name
      type = attribute.value.type
    }
  }

  tags                = var.tags
}