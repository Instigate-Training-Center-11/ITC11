var models = require("../models");
const { citySchema } = require("../schemas");
const { validate, handleErrors } = require("../utils");

const { City } = models;

const createCity = async (req, res) => {
  try {
    const { name, isCapital, population } = req.body;
    const city = await City.findOne({
      where: { name },
      attributes: ["id"],
    });
    if (population <= 0) {
      res.statusCode = 400;
      res.send("Population should be positiv number");
    } else if (city) {
      res.statusCode = 400;
      res.send("City with this name alerady exist");
    } else {
      validate(citySchema, req.body);
      const newCity = await City.create({
        name,
        isCapital,
        population,
      });
      res.statusCode = 201;
      res.send(newCity);
    }
  } catch (error) {
    handleErrors(res, error);
  }
};

const getCities = async (req, res) => {
  const cities = await City.findAll({
    attributes: ["name", "isCapital", "population"],
  });
  if (cities.length) {
    res.send(cities);
  } else {
    res.statusCode = 404;
    res.send("Not found");
  }
};

module.exports = {
  createCity,
  getCities,
};
