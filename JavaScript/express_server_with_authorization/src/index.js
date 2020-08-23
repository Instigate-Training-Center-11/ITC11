const express = require("express");
var bodyParser = require("body-parser");
const dotenv = require("dotenv");

const controllers = require("./controllers");
const models = require("./models");
const { isAdmin, auth } = require("./auth");

dotenv.config();

const { City, User, Offic, db } = models;

const {
  signup,
  signin,
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
  res.setHeader(
    "Access-Control-Allow-Headers",
    "origin, content-type, accept, authorization"
  );
  res.setHeader("Content-Type", "application/json");
  next();
});

const checkBody = (err, req, res, next) => {
  if (err) {
    res.statusCode = 400;
    res.send("Invalid Json");
  } else {
    next();
  }
};

app.use(bodyParser.json(), checkBody);

app.get("/", (req, res) => res.send("Home page"));

//auth
app.post("/signup", signup);
app.post("/signin", signin);

//user
app.get("/users", auth, getUsers);
app.get("/users/:id", getUser);

//city
app.post("/cities", isAdmin, createCity);
app.get("/cities", getCities);

//offic
app.post("/offices", createOffic);
app.get("/offices", getOffices);

app.listen(process.env.PORT, () =>
  console.log(`Example app listening on port port!`, process.env.PORT)
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
