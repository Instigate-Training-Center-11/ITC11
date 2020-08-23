const validate = (schema, data) => {
  const { error, value } = schema.validate(data);
  if (error) {
    throw new Error(`400, ${error.details[0].message}`);
  }
  return value;
};

const handleErrors = (res, err) => {
  console.log(err.message);
  const message = err.message || "internal server error";
  const statusCode = err.status || 500;
  res.status(statusCode).send(message);
};

module.exports = { validate, handleErrors };
