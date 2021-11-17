/* ecmo_pulse_engine_build
 * create ec2 instance from generic ubuntu ami and build Pulse Engine
 *  (original)    pulse_engine: https://gitlab.kitware.com/physiology/engine
 *  (ecmo_modded) pulse_engine: 
 * version 0.13
 */

##################################################
# provider
##################################################
aws_region              = "ap-southeast-2"

##################################################
# resource naming
##################################################
# resource_naming (toggle) - module for generating resource names and tags
enable_resource_naming  = "true"
# resource_naming (variables) - module for generating resource names and tags
app_name                = "ecmo-pulse-engine-builder"
environment             = "dev"
##################################################
# vpc and networking for ec2 instance
##################################################
# vpc - vpc to temporarily house ec2 instance
vpc_name                        = ""
vpc_cidr                        = "192.168.0.0/16"
public_cidr                     = "192.168.1.0/24"
private_cidr                    = "192.168.2.0/24"
# security group (toggle) - security group to temporarily house ec2 instance
create_sg                       = true
# security group (configuration) - security group to temporarily house ec2 instance
ec2_sg_name                     = null
ec2_sg_use_name_prefix          = false
ec2_sg_description              = "Security Group managed by Terraform"
ec2_sg_vpc_id                   = null
# security group (ingress) - security group to temporarily house ec2 instance
ec2_sg_ingress_with_cidr_blocks = [
  {
    from_port   = 0
    to_port     = 0
    protocol    = "-1"
    description = "super secure protocol"
    cidr_blocks = "0.0.0.0/0"
  }
]
# security group (egress) - security group to temporarily house ec2 instance
ec2_sg_egress_with_cidr_blocks  = [
  {
    from_port   = 0
    to_port     = 0
    protocol    = "-1"
    description = "super secure protocol"
    cidr_blocks = "0.0.0.0/0"
  }
]
##################################################
# ec2 instance
##################################################
# ecmo pulse module builder (toggle) - ec2 instance for bulding ecmo pulse engine
ecmo_pulse_module_builder_instance_count  = 1
# ecmo pulse module builder (configurations) - ec2 instance for bulding ecmo pulse engine
ecmo_pulse_module_builder_instance_name   = null
ecmo_pulse_module_builder_ami_id          = "ami-0567f647e75c7bc05"
ecmo_pulse_module_builder_instance_type   = "t3.xlarge"
ecmo_pulse_module_builder_key_name        = "ecmo-app-dev"
ecmo_pulse_module_builder_ebs_optimized   = false
# ecmo pulse module builder (networking) - ec2 instance for bulding ecmo pulse engine
ecmo_pulse_module_builder_subnet_ids                  = []
ecmo_pulse_module_builder_vpc_security_group_ids      = []
ecmo_pulse_module_builder_associate_public_ip_address = true
