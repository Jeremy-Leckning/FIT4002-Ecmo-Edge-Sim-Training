/* lambda
 * module for  create lambda function without environment variables
 * version 0.13
 */
#############################################
# local variable declaration
#############################################
locals {
  trust_policy_custom_statements = length(var.trust_policy_custom_statements) == 0 ? "" : ",${var.trust_policy_custom_statements}"
}

#############################################
# lambda function module
#############################################
resource "aws_lambda_function" "lambda_function" {
  count             = var.create_lambda_function ? 1 : 0

  function_name     = var.lambda_function_name
  description       = var.lambda_function_description
  
  role              = aws_iam_role.lambda_execution_role[0].arn
  handler           = var.lambda_function_handler
  runtime           = var.lambda_function_runtime
  filename          = var.lambda_function_source_code_path
  source_code_hash  = filebase64sha256(var.lambda_function_source_code_path)

  tags          = var.tags
}

#############################################
# lambda function execution role
#############################################
data "template_file" "lambda_execution_role_policy_template" {
  template = "${file("${path.module}/lambda_execution_role_policy.json")}"
  vars = {
    aws_region            = var.aws_region
    aws_account_id        = var.aws_account_id
    lambda_function_name  = var.lambda_function_name
  }
}

resource "aws_iam_policy" "lambda_execution_role_policy" {
  # lambda_execution_role (policy) - exeuction role for lambda function
  count       = var.create_lambda_execution_role ? 1 : 0
  name        = "${var.lambda_execution_role_name}-policy"
  description = "Policy for ${var.lambda_execution_role_name}"

  policy      = "${data.template_file.lambda_execution_role_policy_template.rendered}"
}

resource "aws_iam_role" "lambda_execution_role" {
  # lambda_execution_role (role) - exeuction role for lambda function
  count       = var.create_lambda_execution_role ? 1 : 0
  name        = var.lambda_execution_role_name
  description = "Execution role for lambda function ${var.lambda_function_name}"
  path        = "/service-role/"

  assume_role_policy = <<EOF
{
  "Version": "2012-10-17",
  "Statement": [
    {
      "Sid": "LambdaAssumption",
      "Action": "sts:AssumeRole",
      "Principal": {
        "Service": "lambda.amazonaws.com"
      },
      "Effect": "Allow"
    }
    ${local.trust_policy_custom_statements}
  ]
}
  EOF
}

resource "aws_iam_role_policy_attachment" "lambda_execution_policy_attachment" {
  count       = var.create_lambda_execution_role ? 1 : 0
  role        = aws_iam_role.lambda_execution_role[0].name
  policy_arn  = aws_iam_policy.lambda_execution_role_policy[0].arn
}
