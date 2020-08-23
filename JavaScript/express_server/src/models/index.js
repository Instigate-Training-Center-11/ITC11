const { DataTypes, Sequelize } = require("sequelize");
const config = require("../configs");

const { db_name, db_user, db_pass, host_name } = config;

const sequelize = new Sequelize(db_name, db_user, db_pass, {
  host: host_name,
  dialect: "mysql",
});

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
  age: {
    type: DataTypes.INTEGER,
    allowNull: false,
  },
  job: {
    type: DataTypes.STRING,
    allowNull: false,
  },
  imageUrl: {
    type: DataTypes.STRING,
    defaultValue:
      "https://cdn1.iconfinder.com/data/icons/avatar-2-2/512/Programmer-512.png",
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

const City = sequelize.define("Cities", {
  id: {
    type: DataTypes.INTEGER,
    primaryKey: true,
    autoIncrement: true,
  },
  name: {
    type: DataTypes.STRING,
    allowNull: false,
  },
  isCapital: {
    type: DataTypes.BOOLEAN,
    allowNull: false,
  },
  population: {
    type: DataTypes.INTEGER,
    allowNull: false,
  },
});

const Offic = sequelize.define("Offices", {
  id: {
    type: DataTypes.INTEGER,
    primaryKey: true,
    autoIncrement: true,
  },
  name: {
    type: DataTypes.STRING,
    allowNull: false,
  },
});

User.belongsTo(City, { foreignKey: "cityId" });
User.belongsTo(Offic, { foreignKey: "officId" });

// User.hasOne(Investment, { foreignKey: "userId" });

module.exports = {
  User,
  Investment,
  City,
  Offic,
  db: sequelize,
};
