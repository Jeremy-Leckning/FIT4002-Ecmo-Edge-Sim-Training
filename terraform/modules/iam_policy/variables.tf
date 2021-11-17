/* iam policy
 * module for creating iam policy with optional policy attachment
 * version 0.13
 */
#############################################
# meta-arguments
#############################################
variable "policy_file_path" {
  description = "Region for where lambda function is to be created."
  type        = string
  default     = null
}

variable "policy_file_variables" {
  description = "AWS account id."
  type        = map
  default     = {}
}

#############################################
# iam policy module
#############################################
# policy (policy) - iam policy
variable "create_iam_policy" {
  description = "Boolean value to determine whether or not the lambda function is created."
  type        = bool
  default     = true 
}

variable "iam_policy_name" {
  description = "Unique name for iam_policy"
  type        = string
  default     = ""
}

# policy (attachment) - iam policy
variable "attach_policy" {
  description = "Boolean value to determine whether or not the lambda function is created."
  type        = bool
  default     = false 
}

variable "target_iam_role_name" {
  description = "Unique name for target role that iam_policy is to be attached to"
  type        = string
  default     = null
}
