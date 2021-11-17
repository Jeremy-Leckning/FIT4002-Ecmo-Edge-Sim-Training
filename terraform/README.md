# ECMO Sim Training (Terraform)
The purpose of this section of the repository is to provision the infrastructure that hosts the ECMO Sim Training platform as code.


## Dependencies
 * AWS CLI
    * version: v2
    * link: [AWSCLIV2.msi](https://awscli.amazonaws.com/AWSCLIV2.msi)
 * Terraform
    * version: v0.13.7
    * link: [terraform/0.13.7](https://releases.hashicorp.com/terraform/0.13.7/)

## Installation
In the AWS Account where infrastructure is to be created, create an IAM User called `ecmo_provisioner`so that Terraform can use this IAM User to create, change, or destroy AWS resources. Please find instructions for creating IAM Users from the [relevant AWS Documentation](https://docs.aws.amazon.com/IAM/latest/UserGuide/id_users_create.html#id_users_create_cliwpsapi). The details of the IAM User are as follows:
```
iam_user_name       ecmo_provisioner        as this has been used as the profile in the provider clause in main.tf
aws_access_type     access_key              for programmatic access
permissions         [                       NOTE: these permissions may require tightening or loosening
                        "iam:*",
                        "s3:*",
                        "ec2:*",
                        "kms:*",
                        "ebs:*",
                        "dynamodb:*",
                        "lambda:*",
                        "s3:*",
                        "vpc:*",
                        "execute-api:*"
                    ]
```

## Usage
1. Open a command line in the home directory of the terraform infrastructure directory. For example, `$REPOSITORY_HOME/terraform/infrastructure/ecmo_rest_api`
2. Run the following commands to initialize, plan, apply, or destroy infrastructure using Terraform. For more information on these commands, see the official Terraform documentation as follows:
    * [initialize](https://www.terraform.io/docs/cli/commands/init.html)
    * [plan](https://www.terraform.io/docs/cli/commands/plan.html)
    * [apply](https://www.terraform.io/docs/cli/commands/apply.html)
    * [destroy](https://www.terraform.io/docs/cli/commands/destroy.html)

## Features Planned
 * tighten security group policies (the default inbound rules have been left open to everything 0.0.0.0/0 eg. at `terraform/infrastructure/ecmo_pulse_engine/terraform.tfvars` line 37 for ec2_sg_ingress_with_cidr_blocks, strongly recommend to tighten to a CIDR that only allows your IP address for security purposes)
 * add authentication step in CRUD API
 * create S3 bucket for storing assets
 * create ec2 for hosting server (this will be very similar to the ecmo_pulse_engine terraform code)
