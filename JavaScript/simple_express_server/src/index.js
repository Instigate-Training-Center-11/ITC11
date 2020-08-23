const express = require("express");
const { Sequelize, DataTypes } = require("sequelize");
var bodyParser = require("body-parser");
const config = require("./configs");

var investments = require("../investments.json");
var users = require("../users.json");

const { db_name, db_user, db_pass, host_name } = config;

const sequelize = new Sequelize(db_name, db_user, db_pass, {
  host: host_name,
  dialect: "mysql",
});

const app = express();
const port = 3002;

const User = sequelize.define("Users", {
  id: {
    type: DataTypes.INTEGER,
    primaryKey: true,
    unique: true,
    autoIncrement: true,
  },
  firstName: {
    type: DataTypes.STRING,
    allowNull: false,
  },
  lastName: {
    type: DataTypes.STRING,
    allowNull: false,
  },
  job: {
    type: DataTypes.STRING,
  },
  imageUrl: {
    type: DataTypes.STRING,
    allowNull: false,
  },
});

const Investment = sequelize.define("Investments", {
  id: {
    type: DataTypes.INTEGER,
    primaryKey: true,
    unique: true,
    autoIncrement: true,
  },
  price: {
    type: DataTypes.INTEGER,
    allowNull: false,
  },
});

User.hasOne(Investment, { foreignKey: "userId" });

const connect = async () => {
  try {
    await sequelize.authenticate();
    // users.peoplesData.forEach(async (element, ind) => {
    //   await User.create({
    //     firstName: element.name,
    //     lastName: element.lastname,
    //     age: element.age,
    //     job: element.job,
    //     imageUrl: element.imageUrl,
    //     cityId: (ind % 3) + 1,
    //
    //   })
    //     .then((res) => console.log(res))
    //     .catch((err) => console.log(err));
    // });
    // investments.investmentsData.forEach(async (element, ind) => {
    //   await Investment.create({
    //     price: element.investments,
    // userId: ind + 1,
    //   })
    //     .then((res) => console.log(res))
    //     .catch((err) => console.log(err));
    // });

    // await User.sync();
    // await Investment.sync();

    console.log("Connection has been established successfully.");
  } catch (error) {
    console.error("Unable to connect to the database:", error);
  }
};

const getUsers = async (req, res) => {
  const users = await User.findAll({
    include: [
      { model: Investment, foreignKey: "userId", attributes: ["price"] },
    ],
    attributes: { exclude: ["createdAt", "updatedAt"] },
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
    where: { id },
    include: [
      { model: Investment, foreignKey: "userId", attributes: ["price"] },
    ],
    attributes: { exclude: ["createdAt", "updatedAt"] },
  });
  if (user) {
    res.send(JSON.stringify(user, null, 2));
  }
  res.statusCode = 404;
  res.send("Not found");
};

const getInvestments = async (req, res) => {
  const investments = await Investment.findAll({
    attributes: { exclude: ["createdAt", "updatedAt", "userId"] },
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
    attributes: { exclude: ["createdAt", "updatedAt", "userId"] },
  });

  if (investment) {
    res.send(JSON.stringify(investment, null, 2));
  }
  res.statusCode = 404;
  res.send("Not found");
};

app.use((req, res, next) => {
  res.setHeader("Access-Control-Allow-Origin", "*");
  res.setHeader("Access-Control-Allow-Headers", "origin, content-type, accept");
  res.setHeader("Content-Type", "application/json");
  next();
});

app.use(bodyParser.json());

app.get("/", (req, res) => res.send("Home page"));

app.get("/users", getUsers);

app.get("/users/:id", getUser);

app.get("/investments", getInvestments);

app.get("/investments/:id", getInvestment);

app.listen(port, () =>
  console.log(`Example app listening on port port!`, port)
);

connect();
