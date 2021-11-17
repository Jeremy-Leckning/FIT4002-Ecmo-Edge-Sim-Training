const AWS = require("aws-sdk");

const dynamo = new AWS.DynamoDB.DocumentClient();

exports.handler = async (event, context) => {
  let body;
  let statusCode = 200;
  const headers = {
    "Content-Type": "application/json"
  };

  var ecmo_dynamo_textbook_table_name = "ecmo-api-dev-textbook-dynamo-table";
  var ecmo_dynamo_scenario_table_name = "ecmo-api-dev-scenario-dynamo-table";

  try {
    switch (event.routeKey) {
      /* [TEXTBOOK] CREATE chapter(s)
       * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#putItem-property
       */
      case "PUT /textbook/chapters":
        let putTextbookChapterJSON = JSON.parse(event.body);
        await dynamo
          .put({
            TableName: ecmo_dynamo_textbook_table_name,
            Item: {
              id: putTextbookChapterJSON.id,
              chapter_number: putTextbookChapterJSON.chapter_number,
              chapter_title: putTextbookChapterJSON.chapter_title,
              object_type : "chapter"
            }
          })
          .promise();
        body = `chapter created | 
                ${putTextbookChapterJSON}`;
        break;
      /* [TEXTBOOK] READ chapter(s)
       * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#getItem-property
       */
      case "GET /textbook/chapters/{id}":
        body = await dynamo
          .get({
            TableName: ecmo_dynamo_textbook_table_name,
            Key: {
              id: event.pathParameters.id
            }
          }).promise()
        break;
      /* [TEXTBOOK] UPDATE chapter(s)
       * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#updateItem-property
       */
      case "POST /textbook/chapters":
        let postTextbookChapterJSON = JSON.parse(event.body);
        await dynamo
          .update({
            TableName: ecmo_dynamo_textbook_table_name,
            Key: {
              id: postTextbookChapterJSON.id
            },
            UpdateExpression: "SET chapter_number = :cn, chapter_title = :ct",
            ExpressionAttributeValues: {
              ":cn": postTextbookChapterJSON.chapter_number,
              ":ct": postTextbookChapterJSON.chapter_title,
            }
          }).promise();
        body = `chapter updated | 
                ${postTextbookChapterJSON}`;
        break;
      /* [TEXTBOOK] DESTROY chapter(s)
       * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#deleteItem-property
       */
      case "DELETE /textbook/chapters/{id}":
        body = await dynamo
          .delete({
            TableName: ecmo_dynamo_textbook_table_name,
            Key: {
              id: event.pathParameters.id
            }
          }).promise();
        break;
      /* [TEXTBOOK] LIST chapter(s)
       * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#deleteItem-property
       */
      case "GET /textbook/chapters":
        body = await dynamo
          .scan({ 
            TableName: ecmo_dynamo_textbook_table_name,
            FilterExpression: "#ot = :chapter" ,
            ExpressionAttributeNames:{ 
              "#ot": "object_type"
            },
            ExpressionAttributeValues: {
              ":chapter": "chapter"
            }
          }).promise()
        break;
      
      /* [TEXTBOOK] CREATE page(s)
       * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#putItem-property
       */
      case "PUT /textbook/pages":
        let putTextbookPageJSON = JSON.parse(event.body);
        await dynamo
          .put({
            TableName: ecmo_dynamo_textbook_table_name,
            Item: {
              id: putTextbookPageJSON.id,
              chapter_number: putTextbookPageJSON.chapter_number,
              chapter_title: putTextbookPageJSON.chapter_title,
              object_type: "page",
              header_content: putTextbookPageJSON.header_content,
              subheader_content: putTextbookPageJSON.subheader_content,
              card_content: putTextbookPageJSON.card_content,
              text_content: putTextbookPageJSON.text_content,
              img_src_content_top_right: putTextbookPageJSON.img_src_content_top_right,
              img_src_content_bottom_right: putTextbookPageJSON.img_src_content_bottom_right,
              img_header_content_top_right: putTextbookPageJSON.img_header_content_top_right,
              img_header_content_bottom_right: putTextbookPageJSON.img_header_content_bottom_right,
              config_card_width: putTextbookPageJSON.config_card_width,
              config_mirrored_view: putTextbookPageJSON.config_mirrored_view,
              config_completed: putTextbookPageJSON.config_completed,
              buttonLinkTo: putTextbookPageJSON.buttonLinkTo
            }
          })
          .promise();
        body = `page created | 
                ${putTextbookPageJSON}`;
        break;
      /* [TEXTBOOK] READ page(s)
      * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#getItem-property
      */
      case "GET /textbook/pages/{id}":
        body = await dynamo
          .get({
            TableName: ecmo_dynamo_textbook_table_name,
            Key: {
              id: event.pathParameters.id
            }
          }).promise()
        break;
      /* [TEXTBOOK] UPDATE page(s)
      * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#updateItem-property
      */
      case "POST /textbook/pages":
        let postTextbookPageJSON = JSON.parse(event.body);
        await dynamo
          .update({
            TableName: ecmo_dynamo_textbook_table_name,
            Key: {
              id: postTextbookPageJSON.id
            },
            UpdateExpression: "SET chapter_number = :cn, chapter_title = :ct, header_content = :hc, subheader_content = :sc, card_content = :lc, text_content = :rc, img_src_content_top_right = :isctr, img_src_content_bottom_right = :iscbr, img_header_content_top_right = :ihctr, img_header_content_bottom_right = :ihcbr, config_card_width = :clw, config_mirrored_view = :cmv, config_completed = :cc, buttonLinkTo = :blt",
            ExpressionAttributeValues: {
              ":cn": postTextbookPageJSON.chapter_number,
              ":ct": postTextbookPageJSON.chapter_title,
              ":hc": postTextbookPageJSON.header_content,
              ":sc": postTextbookPageJSON.subheader_content,
              ":lc": postTextbookPageJSON.card_content,
              ":rc": postTextbookPageJSON.text_content,
              ":isctr": postTextbookPageJSON.img_src_content_top_right,
              ":iscbr": postTextbookPageJSON.img_src_content_bottom_right,
              ":ihctr": postTextbookPageJSON.img_header_content_top_right,
              ":ihcbr": postTextbookPageJSON.img_header_content_bottom_right,
              ":clw": postTextbookPageJSON.config_card_width,
              ":cmv": postTextbookPageJSON.config_mirrored_view,
              ":cc": postTextbookPageJSON.config_completed,
              ":blt": putTextbookPageJSON.buttonLinkTo
            }
          })
          .promise();
        body = `page updated | 
                ${postTextbookPageJSON}`;
        break;
      /* [TEXTBOOK] DESTROY page(s)
      * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#deleteItem-property
      */
      case "DELETE /textbook/pages/{id}":
        await dynamo
          .delete({
            TableName: ecmo_dynamo_textbook_table_name,
            Key: {
              id: event.pathParameters.id
            }
          }).promise();
        body = `deleted page ${event.pathParameters.id}`;
        break;
      /* [TEXTBOOK] LIST page(s)
      * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#deleteItem-property
      */
      case "GET /textbook/pages":
        body = await dynamo
          .scan({ 
            TableName: ecmo_dynamo_textbook_table_name,
            FilterExpression: "#ot = :page" ,
            ExpressionAttributeNames:{ 
              "#ot": "object_type"
            },
            ExpressionAttributeValues: {
              ":page": "page"
            }
          }).promise()
        break;

      /* [TEXTBOOK] CREATE scenario(s)
      * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#putItem-property
      */
      case "PUT /scenario":
        let putScenarioJSON = JSON.parse(event.body);
        await dynamo
          .put({
            TableName: ecmo_dynamo_scenario_table_name,
            Item: putScenarioJSON
          })
          .promise();
        body = `put scenario |
                ${putScenarioJSON}`;
        break;
      /* [TEXTBOOK] READ scenario(s)
      * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#getItem-property
      */
      case "GET /scenario/{id}":
        body = await dynamo
          .get({
            TableName: ecmo_dynamo_scenario_table_name,
            Key: {
              id: event.pathParameters.id
            }
          }).promise()
        break;
      /* [TEXTBOOK] DESTROY scenario(s)
      * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#deleteItem-property
      */
      case "DELETE /scenario/{id}":
        await dynamo
          .delete({
            TableName: ecmo_dynamo_scenario_table_name,
            Key: {
              id: event.pathParameters.id
            }
          }).promise();
        body = `deleted scenario ${event.pathParameters.id}`;
        break;
      /* [TEXTBOOK] LIST scenario(s)
      * https://docs.aws.amazon.com/AWSJavaScriptSDK/latest/AWS/DynamoDB.html#deleteItem-property
      */
      case "GET /scenario":
        body = await dynamo
          .scan({ 
            TableName: ecmo_dynamo_scenario_table_name,
          }).promise()
        break;  
      default:
        throw new Error(`Unsupported route: "${event.routeKey}"`);
    }
  } catch (err) {
    statusCode = 400;
    body = err.message;
  } finally {
    body = JSON.stringify(body);
  }

  return {
    statusCode,
    body,
    headers
  };
};
