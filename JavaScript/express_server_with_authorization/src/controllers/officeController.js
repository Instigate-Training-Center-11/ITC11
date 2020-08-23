var models = require("../models");
const { officeSchema } = require("../schemas");
const { validate, handleErrors } = require("../utils");

const { Offic } = models;

const createOffic = async (req, res) => {
  try {
    const { name } = req.body;
    const offic = await Offic.findOne({
      where: { name },
      attributes: ["id"],
    });
    if (offic) {
      res.statusCode = 400;
      res.send("City with this name alerady exist");
    } else {
      validate(officeSchema, req.body);
      const newOffice = await Offic.create({
        name,
      });
      res.statusCode = 201;
      res.send(newOffice);
    }
  } catch (error) {
    handleErrors(res, error);
  }
};

const getOffices = async (req, res) => {
  const cities = await Offic.findAll({
    attributes: ["name"],
  });
  if (cities.length) {
    res.send(cities);
  } else {
    res.statusCode = 404;
    res.send("Not found");
  }
};

module.exports = {
  createOffic,
  getOffices,
};
