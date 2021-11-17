const express = require('express');
const request = require('request');
const router = express.Router();

const {HTTP_STATUS_CODES} = require('../common');
const {OK} = HTTP_STATUS_CODES;

/*
* GET /api/textbook
* 
* Gets all chapters of textbook through api gateway
*/
router.get("/", async (req, res, next) => {

    let url = 'https://46y7wzkd1j.execute-api.ap-southeast-2.amazonaws.com/chapters';
    let options = {json: true};

    request(url, options, (error, res2, body) => {
        if (error) {
            return  console.log(error)
        };
    
        if (!error && res2.statusCode == 200) {
            res.status(OK).send(body);
        };
    });
    
});

/*
* GET /api/textbook/
* 
* Gets all chapters of textbook through api gateway
*/
router.get("/:chapter_id", async (req, res, next) => {

    let url = 'https://46y7wzkd1j.execute-api.ap-southeast-2.amazonaws.com/chapters/' + req.params.chapter_id;
    let options = {json: true};

    request(url, options, (error, res2, body) => {
        if (error) {
            return  console.log(error)
        };
    
        if (!error && res2.statusCode == 200) {
            res.status(OK).send(body);
        };
    });
    
});


module.exports = router;