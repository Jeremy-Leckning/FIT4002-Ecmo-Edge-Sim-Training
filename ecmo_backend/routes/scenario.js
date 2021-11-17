const express = require('express');
const request = require('request');
const router = express.Router();

const { HTTP_STATUS_CODES, TABLES } = require('../common');
const { OK, BAD_REQUEST } = HTTP_STATUS_CODES;
const { SCENARIO_TABLE } = TABLES;

// To be removed when DB is implemented
const { scenario_1 } = require('../data model/scenario_1')

/**
 * GET /api/scenarios
 * 
 * 
 * Get scenario list using dummy data
 */
router.get('/', async (req, res, next) => {
    const scenario = scenario_1;

    res.status(OK).send(scenario);
});

/** Get vitals through api gateway
*/
router.get("/vitals", async (req, res, next) => {

    let url = 'https://46y7wzkd1j.execute-api.ap-southeast-2.amazonaws.com/vitals';
    let options = { json: true };

    request(url, options, (error, res2, body) => {
        try {
            res.status(OK).send(body);
        }
        catch (error) {
            return console.log(error)
        };


    });

});


router.get("/vitals/:patient_id/:time_log", async (req, res, next) => {

    let url = 'https://46y7wzkd1j.execute-api.ap-southeast-2.amazonaws.com/vitals/' + req.params.patient_id + '/' + req.params.time_log;
    let options = { json: true };

    request(url, options, async (error, res2, body) => {
        try {

            res.status(OK).send(body);

        }
        catch (error) {
            return console.log(error)
        };

    });

});

/**
 * GET /api/scenarios/{scenario_id}
 * 
 * Get specific scenario
 * 
 */

// router.get('/:scenario_id', async (req, res, next) => {

//     const scenario = scenario_1;

//     res.status(OK).send(scenario);
// })

module.exports = router;