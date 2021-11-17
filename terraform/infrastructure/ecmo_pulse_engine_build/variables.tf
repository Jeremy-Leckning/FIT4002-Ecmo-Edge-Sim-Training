/* ecmo_pulse_engine_build
 * create ec2 instance from generic ubuntu ami and build Pulse Engine
 *  (original)    pulse_engine: https://gitlab.kitware.com/physiology/engine
 *  (ecmo_modded) pulse_engine: 
 * version 0.13
 */

##################################################
# provider
##################################################
variable "aws_region" {
  description = "AWS region for resource to be provisioned in. Please refer to `https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/Concepts.RegionsAndAvailabilityZones.html` for a complete list of regions." 
  type        = string
  default     = "ap-southeast-2"
}

##################################################
# resource naming
##################################################
# resource_naming (toggle) - module for generating resource names and tags
variable "enable_resource_naming" {
  description = "Toggle to enable or disable resource naming module. Allowed values: true | false"
  type        = string
  default     = "true"
}

# resource_naming (variables) - module for generating resource names and tags
variable "app_name" {
  description = "Name of application name for infrastructure provisioned by this Terraform code."
  type        = string
  default     = "ecmo-pulse-engine-builder"
}

variable "environment" {
  description = "Name of environment provisioned by this Terraform code."
  type        = string
  default     = "dev"
}

##################################################
# vpc and networking for ec2 instance
##################################################
# vpc - vpc to temporarily house ec2 instance
variable "vpc_name" {
  description = "Name of vpc that is being created. Leave as empty string to use resource naming module"
  type        = string
  default     = ""
}

variable "vpc_cidr" {
  description = "CIDR block of vpc."
  type        = string
  default     = "192.168.0.0/16"
}

variable "public_cidr" {
  description = "Public CIDR block of vpc."
  type        = string
  default     = "192.168.1.0/24"
}

variable "private_cidr" {
  description = "Private CIDR block of vpc."
  type        = string
  default     = "192.168.2.0/24"
}

# security group (toggle) - security group to temporarily house ec2 instance
variable "create_sg" {
  description = "Toggle to create or not create security group. Allowed values: true | false"
  type        = bool
  default     = true
}

# security group (configuration) - security group to temporarily house ec2 instance
variable "ec2_sg_name" {
  description = "Name of security group that is being created. Leave as null to use resource naming module"
  type        = string
  default     = null
}

variable "ec2_sg_use_name_prefix" {
  description = "Whether to use name_prefix or fixed name. Should be true to able to update security group name after initial creation"
  type        = bool
  default     = false
}

variable "ec2_sg_description" {
  description = "Description of security group"
  type        = string
  default     = "Security Group managed by Terraform"
}

variable "ec2_sg_vpc_id" {
  description = "ID of the VPC where to create security group"
  type        = string
  default     = null
}

# security group (ingress) - security group to temporarily house ec2 instance
variable "ec2_sg_ingress_with_cidr_blocks" {
  description = "CIDR block ingress rules for ec2 security group"
  type        = list(map(string))
  default     = []
}

# security group (egress) - security group to temporarily house ec2 instance
variable "ec2_sg_egress_with_cidr_blocks" {
  description = "CIDR block egress rules for ec2 security group"
  type        = list(map(string))
  default     = []
}

##################################################
# ec2 instance
##################################################
# ecmo pulse module builder (toggle) - ec2 instance for bulding ecmo pulse engine
variable "ecmo_pulse_module_builder_instance_count" {
  description = "Integer representing number of ec2 instances to be provisioend by module."
  type        = number
  default     = 1
}

# ecmo pulse module builder (configurations) - ec2 instance for bulding ecmo pulse engine
variable "ecmo_pulse_module_builder_instance_name" {
  description = "Name of ec2 instance(s). Leave as null to use resource naming module."
  type        = string
  default     = null
}

variable "ecmo_pulse_module_builder_ami_id" {
  description = "ID ami to be used by ec2 instance"
  type        = string
  default     = "ami-0567f647e75c7bc05"
}

variable "ecmo_pulse_module_builder_instance_type" {
  description = "Type of ec2 instasnce(s)."
  type        = string
  default     = "t3.xlarge"
}

variable "ecmo_pulse_module_builder_key_name" {
  description = "Key name to be used when provisioning ec2 isntances."
  type        = string
  default     = "ecmo-app-dev"
}

variable "ecmo_pulse_module_builder_ebs_optimized" {
  description = "Toggle for ebs optimization. Allowed values: true | false"
  type        = bool
  default     = false
}

# ecmo pulse module builder (networking) - ec2 instance for bulding ecmo pulse engine
variable "ecmo_pulse_module_builder_subnet_ids" {
  description = "List subnet ids to be used for ec2 instance(s)"
  type        = list(string)
  default     = []
}

variable "ecmo_pulse_module_builder_vpc_security_group_ids" {
  description = "List security group ids to be used for ec2 instance(s)"
  type        = list(string)
  default     = []
}

variable "ecmo_pulse_module_builder_associate_public_ip_address" {
  description = "Toggle to associate or not associate public ip address for ec2 instance. Allowed values: true | false"
  type        = bool
  default     = true
}
