const { DataTypes, Sequelize } = require("sequelize");
const dotenv = require("dotenv");
const userModel = require("./user");
const cityModel = require("./city");
const officeModel = require("./office");
const investmentModel = require("./investment");
const { dialect } = require("../configs");

dotenv.config();

const sequelize = new Sequelize(
  process.env.DB_NAME,
  process.env.DB_USER,
  process.env.DB_PASSWORD,
  {
    host: process.env.HOST_NAME,
    dialect,
  }
);

const User = userModel(sequelize, DataTypes);
const City = cityModel(sequelize, DataTypes);
const Offic = officeModel(sequelize, DataTypes);
const Investment = investmentModel(sequelize, DataTypes);

User.belongsTo(City, { foreignKey: "cityId" });
User.belongsTo(Offic, { foreignKey: "officId" });

// Investment.hasOne(User, { foreignKey: "investmentId" });

module.exports = {
  User,
  Investment,
  City,
  Offic,
  db: sequelize,
};
