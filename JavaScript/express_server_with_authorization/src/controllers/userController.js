const bcrypt = require("bcrypt");
const jwt = require("jwt-simple");
const dotenv = require("dotenv");

const models = require("../models");
const { userSchema } = require("../schemas");
const { validate, handleErrors } = require("../utils");

dotenv.config();

const { City, Offic, User } = models;

const signup = async (req, res) => {
  const {
    cityName,
    firstName,
    lastName,
    job,
    imageUrl,
    officName,
    age,
    password,
    email,
    isAdmin,
  } = req.body;
  try {
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
    validate(userSchema, req.body);
    bcrypt.hash(password, 10, async function (err, hash) {
      const user = await User.create({
        firstName,
        lastName,
        email,
        password: hash,
        isAdmin,
        job,
        age,
        imageUrl,
        cityId: city.id,
        officId: offic.id,
      });
      res.statusCode = 201;
      res.send(user);
    });
  } catch (error) {
    handleErrors(res, error);
  }
};

const signin = async (req, res) => {
  const { email, password } = req.body;
  try {
    const user = await User.findOne({ where: { email } });
    if (!user) {
      res.statusCode = 400;
      res.send("Wrong email or password");
    } else {
      bcrypt.compare(password, user.password, function (err, result) {
        if (!result) {
          res.statusCode = 400;
          res.send("Wrong email or password");
        } else {
          var token = jwt.encode(
            {
              email: user.email,
              name: user.firstName,
              lastName: user.lastName,
              isAdmin: user.isAdmin,
            },
            process.env.SECRET_KEY
          );
          res.send({ accessToken: token });
        }
      });
    }
  } catch (error) {}
};

const getUsers = async (req, res) => {
  const users = await User.findAll({
    include: [
      {
        model: City,
        foreignKey: "cityId",
        attributes: ["name", "population", "isCapital"],
      },
      { model: Offic, foreignKey: "officId", attributes: ["name"] },
    ],
    attributes: { exclude: ["createdAt", "updatedAt", "password", "isAdmin"] },
  });
  if (users.length) {
    res.send(users);
  }
  res.statusCode = 404;
  res.send("Not found");
};

const getUser = async (req, res) => {
  const { id } = req.params;
  const user = await User.findOne({
    where: { id },
    include: [
      {
        model: City,
        foreignKey: "cityId",
        attributes: ["name", "population", "isCapital"],
      },
      { model: Offic, foreignKey: "officId", attributes: ["name"] },
    ],
    attributes: { exclude: ["createdAt", "updatedAt", "password", "isAdmin"] },
  });
  if (user) {
    res.send(user);
  }
  res.statusCode = 404;
  res.send("Not found");
};

module.exports = {
  signup,
  signin,
  getUsers,
  getUser,
};
