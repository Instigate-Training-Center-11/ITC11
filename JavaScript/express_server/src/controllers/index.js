var models = require("../models");

const { City, Offic, Investment, User } = models;

//user
const createUser = async (req, res) => {
  const {
    cityName,
    firstName,
    lastName,
    job,
    imageUrl,
    officName,
    age,
  } = req.body;
  const city = await City.findOne({
    where: { name: cityName },
    attributes: ["id"],
  });

  const offic = await Offic.findOne({
    where: { name: officName },
    attributes: ["id"],
  });

  if (!city) {
    res.statusCode = 404;
    res.send("City Not found");
    return;
  }
  if (!offic) {
    res.statusCode = 404;
    res.send("Offic Not found");
    return;
  }
  await User.create({
    firstName,
    lastName,
    job,
    age,
    imageUrl,
    cityId: city.id,
    officId: offic.id,
  })
    .then((user) => {
      res.statusCode = 201;
      res.send(JSON.stringify(user));
    })
    .catch((err) => {
      console.log(err);
      res.statusCode = 400;
      res.send("Not valid data");
    });
};

const getUsers = async (req, res) => {
  const users = await User.findAll({
    attributes: { exclude: ["createdAt", "updatedAt", "officId", "cityId"] },
    include: [
      {
        model: City,
        foreignKey: "cityId",
        attributes: ["name", "population", "isCapital"],
      },
      { model: Offic, foreignKey: "officId", attributes: ["name"] },
    ],
  });
  if (users.length) {
    res.send(JSON.stringify(users, null, 2));
  }
  res.statusCode = 404;
  res.send("Not found");
};

const getUser = async (req, res) => {
  const { id } = req.params;
  const user = await User.findOne({
    attributes: { exclude: ["createdAt", "updatedAt", "officId", "cityId"] },
    where: { id },
    include: [
      {
        model: City,
        foreignKey: "cityId",
        attributes: ["name", "population", "isCapital"],
      },
      { model: Offic, foreignKey: "officId", attributes: ["name"] },
    ],
  });
  if (user) {
    res.send(JSON.stringify(user, null, 2));
  }
  res.statusCode = 404;
  res.send("Not found");
};

const getInvestments = async (req, res) => {
  const investments = await Investment.findAll({
    include: [{ model: User, foreignKey: "investmentId" }],
  });
  if (investments.length) {
    res.send(JSON.stringify(investments, null, 2));
  }
  res.statusCode = 404;
  res.send("Not found");
};

const getInvestment = async (req, res) => {
  const { id } = req.params;
  const investment = await Investment.findOne({
    where: { id },
    include: [{ model: User, as: "User", foreignKey: "userId" }],
  });

  if (investment) {
    res.send(JSON.stringify(investment, null, 2));
  }
  res.statusCode = 404;
  res.send("Not found");
};

//city
const createCity = async (req, res) => {
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
    await City.create({
      name,
      isCapital,
      population,
    })
      .then((city) => {
        res.statusCode = 201;
        res.send(JSON.stringify(city));
      })
      .catch((err) => {
        console.log(err);
        res.statusCode = 400;
        res.send("Not valid data");
      });
  }
};

const getCities = async (req, res) => {
  const cities = await City.findAll({
    attributes: ["name", "isCapital", "population"],
  });
  if (cities.length) {
    res.send(JSON.stringify(cities, null, 2));
  } else {
    res.statusCode = 404;
    res.send("Not found");
  }
};

//Offic
const createOffic = async (req, res) => {
  const { name } = req.body;
  const offic = await Offic.findOne({
    where: { name },
    attributes: ["id"],
  });
  if (offic) {
    res.statusCode = 400;
    res.send("City with this name alerady exist");
  } else {
    await Offic.create({
      name,
    })
      .then((offic) => {
        res.statusCode = 201;
        res.send(JSON.stringify(offic));
      })
      .catch((err) => {
        console.log(err);
        res.statusCode = 400;
        res.send("Not valid data");
      });
  }
};

const getOffices = async (req, res) => {
  const cities = await Offic.findAll({
    attributes: ["name"],
  });
  if (cities.length) {
    res.send(JSON.stringify(cities, null, 2));
  } else {
    res.statusCode = 404;
    res.send("Not found");
  }
};

module.exports = {
  createUser,
  getUsers,
  getUser,
  createCity,
  getCities,
  createOffic,
  getOffices,
};
