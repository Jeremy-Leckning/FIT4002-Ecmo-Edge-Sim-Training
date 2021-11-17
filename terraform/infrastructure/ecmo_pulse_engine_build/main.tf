/* ecmo_pulse_engine_build
 * create ec2 instance from generic ubuntu ami and build Pulse Engine
 *  (original)    pulse_engine: https://gitlab.kitware.com/physiology/engine
 *  (ecmo_modded) pulse_engine: 
 * version 0.13
 */

##################################################
# provider
##################################################
provider "aws" {
  profile = "ecmo_provisioner"
  region = var.aws_region
}

##################################################
# resource naming
##################################################
module "resource_naming" {
  source = "../../modules/resource_naming"
  # resource_naming (toggle) - module for generating resource names and tags
  enabled                 = var.enable_resource_naming
  # resource_naming (variables) - module for generating resource names and tags
  app_name                = var.app_name
  environment             = var.environment
  attributes              = []
  # resource_naming (tagging) - module for generating resource names and tags
  tags                    = {}
  additional_tag_map_list = []
  label_order             = ["app_name", "environment"]
}

##################################################
# vpc and networking for ec2 instance
##################################################
# vpc - vpc to temporarily house ec2 instance
module "vpc" {
  source        = "../../modules/vpc"
  # vpc (configurations) - vpc to temporarily house ec2 instance
  vpc_name      = coalesce(var.vpc_name, "${module.resource_naming.id}-private-vpc")
  # vpc (cidr blocks) - vpc to temporarily house ec2 instance
  vpc_cidr      = var.vpc_cidr   
  public_cidr   = var.public_cidr  
  private_cidr  = var.private_cidr
}

# security group - security group to temporarily house ec2 instance
module "ec2_sg"{
  source = "../../modules/security_group"
  # security group (toggle) - security group to temporarily house ec2 instance
  create_sg = var.create_sg
  # security group (configuration) - security group to temporarily house ec2 instance
  name            = coalesce(var.ec2_sg_name, "${module.resource_naming.id}-ecmo-app-sg")
  use_name_prefix = var.ec2_sg_use_name_prefix
  description     = var.ec2_sg_description
  vpc_id          = coalesce(var.ec2_sg_vpc_id, module.vpc.vpc_id)
  tags            = module.resource_naming.tags
  # security group (ingress) - security group to temporarily house ec2 instance
  ingress_with_cidr_blocks  = var.ec2_sg_ingress_with_cidr_blocks
  # security group (egress) - security group to temporarily house ec2 instance
  egress_with_cidr_blocks   = var.ec2_sg_egress_with_cidr_blocks
}

##################################################
# ec2 instance
##################################################
module "ecmo_pulse_module_builder" {
  source = "../../modules/ec2"
  # ecmo pulse module builder (toggle) - ec2 instance for bulding ecmo pulse engine
  instance_count              = var.ecmo_pulse_module_builder_instance_count
  # ecmo pulse module builder (configurations) - ec2 instance for bulding ecmo pulse engine
  name                        = coalesce(var.ecmo_pulse_module_builder_instance_name, "${module.resource_naming.id}-ecmo-pulse-module-builder")
  ami                         = var.ecmo_pulse_module_builder_ami_id
  instance_type               = var.ecmo_pulse_module_builder_instance_type
  key_name                    = var.ecmo_pulse_module_builder_key_name
  ebs_optimized               = var.ecmo_pulse_module_builder_ebs_optimized
  user_data                   = templatefile(
    "userdata.tpl", {
      pulse_engine_source = "https://gitlab.kitware.com/physiology/engine/-/archive/master/engine-master.tar.gz"
    }
  )
  tags                        = module.resource_naming.tags
  # ecmo pulse module builder (networking) - ec2 instance for bulding ecmo pulse engine
  subnet_ids                  = concat(var.ecmo_pulse_module_builder_subnet_ids, [ module.vpc.subnet_public_id ])
  vpc_security_group_ids      = concat(var.ecmo_pulse_module_builder_vpc_security_group_ids, [ module.ec2_sg.security_group_id ])
  associate_public_ip_address = var.ecmo_pulse_module_builder_associate_public_ip_address
}
