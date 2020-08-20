const dbConfig = require("../config/db.config.js");
const Sequelize = require("sequelize");
const Users = require("./users.model.js");
const Cities = require("./cities.model.js");

const sequelize = new Sequelize(dbConfig.db_name, dbConfig.db_user, dbConfig.db_password, {
  host: dbConfig.host_name,
  dialect: dbConfig.dialect,
  operatorsAliases: false,
});

const db = {};

db.Sequelize = Sequelize;
db.sequelize = sequelize;

db.cities = Users(sequelize);
db.users = Cities(sequelize);

module.exports = db;