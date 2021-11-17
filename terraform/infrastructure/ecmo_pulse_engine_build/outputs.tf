/* ecmo_pulse_engine_build
 * create ec2 instance from generic ubuntu ami and build Pulse Engine
 *  (original)    pulse_engine: https://gitlab.kitware.com/physiology/engine
 *  (ecmo_modded) pulse_engine: 
 * version 0.13
 */

##################################################
# resource naming
##################################################
output "ecmo_pulse_model_builder_naming_id" {
  value       = module.resource_naming.id
  description = "Resource ID"
}

output "ecmo_pulse_model_builder_naming_app_name" {
  value       = module.resource_naming.app_name
  description = "Name of application that resources belong to"
}

output "ecmo_pulse_model_builder_naming_environment" {
  value       = module.resource_naming.environment
  description = "Environment of application that resources belong to"
}

output "ecmo_pulse_model_builder_naming_attributes" {
  value       = module.resource_naming.attributes
  description = "List of additional attributes for the resource being created"
}

output "ecmo_pulse_model_builder_naming_delimiter" {
  value       = module.resource_naming.delimiter
  description = "Delimiter to be used between name components such as `app_name` and `environment`"
}

output "ecmo_pulse_model_builder_naming_tags" {
  value       = module.resource_naming.tags
  description = "Tag map for created resources"
}

output "ecmo_pulse_model_builder_naming_tag_map_list" {
  value       = module.resource_naming.tag_map_list
  description = "Tags as a list of Terraform maps that apply to the created resources"
}

output "ecmo_pulse_model_builder_naming_label_order" {
  value       = module.resource_naming.label_order
  description = "Naming convention of resources for this module"
}

##################################################
# vpc and networking for ec2 instance
##################################################
output "vpc_vpc_id" {
  value       = module.vpc.vpc_id
}

output "vpc_vpc_arn" {
  value       = module.vpc.vpc_arn
}

output "vpc_igw_id" {
  value       = module.vpc.igw_id
}

output "vpc_subnet_public_id" {
  value       = module.vpc.subnet_public_id
}

output "vpc_subnet_private_id" {
  value       = module.vpc.subnet_private_id
}

output "security_group_id" {
  description = "The ID of the security group"
  value       = module.ec2_sg.security_group_id
}

output "security_group_vpc_id" {
  description = "The VPC ID"
  value       = module.ec2_sg.security_group_vpc_id
}

output "security_group_owner_id" {
  description = "The owner ID"
  value       = module.ec2_sg.security_group_owner_id
}

output "security_group_name" {
  description = "The name of the security group"
  value       = module.ec2_sg.security_group_name
}

output "security_group_description" {
  description = "The description of the security group"
  value       = module.ec2_sg.security_group_description
}

##################################################
# ec2 instance
##################################################
output "ec2_id" {
  description = "List of IDs of instances"
  value       = module.ecmo_pulse_module_builder.id
}

output "ec2_arn" {
  description = "List of ARNs of instances"
  value       = module.ecmo_pulse_module_builder.arn
}

output "ec2_availability_zone" {
  description = "List of availability zones of instances"
  value       = module.ecmo_pulse_module_builder.availability_zone
}

output "ec2_key_name" {
  description = "List of key names of instances"
  value       = module.ecmo_pulse_module_builder.key_name
}

output "ec2_private_ip" {
  description = "List of private IP addresses assigned to the instances"
  value       = module.ecmo_pulse_module_builder.private_ip
}

output "ec2_public_ip" {
  description = "List of public IP addresses assigned to the instances, if applicable"
  value       = module.ecmo_pulse_module_builder.public_ip
}

output "ec2_security_groups" {
  description = "List of associated security groups of instances"
  value       = module.ecmo_pulse_module_builder.security_groups
}

output "ec2_vpc_security_group_ids" {
  description = "List of associated security groups of instances, if running in non-default VPC"
  value       = module.ecmo_pulse_module_builder.vpc_security_group_ids
}

output "ec2_subnet_id" {
  description = "List of IDs of VPC subnets of instances"
  value       = module.ecmo_pulse_module_builder.subnet_id
}

output "ec2_instance_count" {
  description = "Number of instances to launch specified as argument to this module"
  value       = module.ecmo_pulse_module_builder.instance_count
}
