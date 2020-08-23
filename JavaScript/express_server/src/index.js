const express = require("express");
var bodyParser = require("body-parser");
const controllers = require("./controllers");
const models = require("./models");
const port = require("./configs").port;

const { City, User, Offic, db } = models;

const {
  createUser,
  getUser,
  getUsers,
  createCity,
  getCities,
  createOffic,
  getOffices,
} = controllers;

const app = express();

app.use((req, res, next) => {
  res.setHeader("Access-Control-Allow-Origin", "*");
  res.setHeader("Access-Control-Allow-Headers", "origin, content-type, accept");
  res.setHeader("Content-Type", "application/json");
  next();
});

app.use(bodyParser.json());

app.get("/", (req, res) => res.send("Home page"));

//user
app.get("/users", getUsers);
app.post("/users", createUser);
app.get("/users/:id", getUser);

//city
app.post("/cities", createCity);
app.get("/cities", getCities);

//offic
app.post("/offices", createOffic);
app.get("/offices", getOffices);

app.listen(port, () =>
  console.log(`Example app listening on port port!`, port)
);

const connect = async () => {
  try {
    await db.authenticate();
    await City.sync();
    await Offic.sync();
    await User.sync();

    console.log("Connection has been established successfully.");
  } catch (error) {
    console.error("Unable to connect to the database:", error);
  }
};

connect();
