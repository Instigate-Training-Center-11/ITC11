const HttpStatus = require('http-status-codes');
const { ResponseError } = require('./ResponseError');
const validate = (schema, data) => {
    const { error, value } = schema.validate(data);
    if (error) {
        throw new ResponseError(HttpStatus.BAD_REQUEST, error.details[0].message);
    }
    return value;
};
const handleErrors = (res, err) => {
    const message = err.message || 'internal server error';
    const statusCode = err.status || HttpStatus.INTERNAL_SERVER_ERROR;
    res.status(statusCode).send(message);
};
module.exports = { validate, handleErrors };