const { Sequelize, DataTypes } = require('sequelize');
let configs = require('../configs');
const {host_name, db_name, db_user, db_password} = configs;

const sequelize = new Sequelize(db_name, db_user,db_password, {
  host: host_name,
  dialect: 'mysql'
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