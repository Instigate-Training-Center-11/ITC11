require('dotenv').config();
const { Sequelize, DataTypes } = require('sequelize');
let configs = require('../configs');
const { dialect } = configs;

const sequelize = new Sequelize(process.env.DB_NAME, process.env.DB_USER, process.env.DB_PASSWORD, {
  host: process.env.HOST_NAME,
  dialect
});

const User = sequelize.define('users', {
  id: {
    type: DataTypes.UUID,
    defaultValue: DataTypes.UUIDV4,
    primaryKey: true,
  },

  name: {
    type: DataTypes.STRING,
    allowNull: false,
  },

  lastName: {
    type: DataTypes.STRING,
    allowNull: false,
  },

  job: {
    type: DataTypes.STRING,
    allowNull: false,
  },

  photo: {
    type: DataTypes.STRING,
    allowNull: false,
  },

  email: {
    type: DataTypes.STRING,
    allowNull: false,
  },

  password: {
    type: DataTypes.STRING,
    allowNull: false,
  },

  isAdmin: {
    type: DataTypes.BOOLEAN,
    defaultValue: false,
    allowNull: false
  }
},{
  timestamps: false,
});

const Cities = sequelize.define('cities', {
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
  }
}, {
  timestamps: false,
});

const Offices = sequelize.define('offices', {
  id: {
    type: DataTypes.INTEGER,
    primaryKey: true,
    autoIncrement: true,
  },

  name: {
    type: DataTypes.STRING,
    allowNull: false,
  }
}, {
  timestamps: false,
});

User.belongsTo(Cities, {foreignKey: 'cityID'});
User.belongsTo(Offices, {foreignKey: 'officeID'});

module.exports = {
  User: User,
  Cities: Cities,
  Offices: Offices,
}