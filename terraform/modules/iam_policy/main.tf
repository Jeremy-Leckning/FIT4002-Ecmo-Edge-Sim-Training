/* iam policy
 * module for creating iam policy with optional policy attachment
 * version 0.13
 */
#############################################
# iam policy module
#############################################
data "template_file" "iam_policy_tempalte" {
  template = "${file("${var.policy_file_path}")}"
  vars = var.policy_file_variables
}

# policy (policy) - iam policy
resource "aws_iam_policy" "iam_policy" { 
  count       = var.create_iam_policy ? 1 : 0
  name        = "${var.iam_policy_name}"
  description = "${var.iam_policy_name}"

  policy      = "${data.template_file.iam_policy_tempalte.rendered}"
}

# policy (attachment) - iam policy
resource "aws_iam_role_policy_attachment" "iam_policy_attachment" {
  count       = var.attach_policy ? 1 : 0
  role        = var.target_iam_role_name
  policy_arn  = aws_iam_policy.iam_policy[0].arn
}
