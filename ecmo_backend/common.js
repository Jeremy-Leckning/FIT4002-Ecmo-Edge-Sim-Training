function createError(status, message) {
    const error = new Error(message);
    error.status = status;
    return error
}

module.exports = {
    HTTP_STATUS_CODES: {
        OK: 200,
        CREATED: 201,
        NO_CONTENT: 204,
        BAD_REQUEST: 400,
        FORBIDDEN: 403,
        NOT_FOUND: 404,
        INTERNAL_SERVER_ERROR: 500,
        NOT_IMPLEMENTED: 501
    },
    TABLES: {
        SCENARIO_TABLE: 'Scenario_tb',
        TEXTBOOK_TABLE: 'Textbook_tb'
    },
    createError: createError
}