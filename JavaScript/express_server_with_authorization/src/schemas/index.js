const Joi = require("@hapi/joi");

const userSchema = Joi.object().keys({
  firstName: Joi.string().required(),
  lastName: Joi.string().min(2).max(20).required(),
  job: Joi.string().min(2).max(20).required(),
  cityName: Joi.string().min(2).max(20).required(),
  imageURL: Joi.string(),
  email: Joi.string().email().required(),
  password: Joi.string()
    .pattern(
      new RegExp("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#$%^&*])(?=.{8,})")
    )
    .required(),
});

const citySchema = Joi.object().keys({
  name: Joi.string().required(),
  population: Joi.number().required(),
  isCapital: Joi.bool().required(),
});

const officeSchema = Joi.object().keys({
  name: Joi.string().required(),
});

module.exports = { userSchema, citySchema, officeSchema };
