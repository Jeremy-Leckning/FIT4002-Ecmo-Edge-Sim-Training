/* dynamo table (provisioned) 
 * module for creating a dynamodb table
 * version 0.13
 */
#############################################
# dynamo table (provisioned) module
#############################################
variable "create_dynamodb_table" {
  description = "Boolean value to determine whether or not the dynamodb table is created."
  type        = bool
  default     = true 
}

variable "dynamodb_table_name" {
  description = "The name of the table, this needs to be unique within a region."
  type        = string
  default     = "dynamodb_table" 
}

variable "dynamodb_table_read_capacity" {
  description = "The name of the table, this needs to be unique within a region."
  type        = number
  default     = 1
}

variable "dynamodb_table_write_capacity" {
  description = "The name of the table, this needs to be unique within a region."
  type        = number
  default     = 1
}

variable "dynamodb_table_hash_key" {
  description = "List of configurations specifying dynamodb table partition key"
  type        = map(string)
  default     = {
    name  = "id"
    type  = "S"
  }
}

variable "dynamodb_table_range_key" {
  description = "List of configurations specifying dynamodb table sort key"
  type        = map(string)
  default     = {}
}

variable "tags" {
  description = "A mapping of tags to assign to the resource"
  type        = map(string)
  default     = {}
}
