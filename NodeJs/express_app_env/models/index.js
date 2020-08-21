const { Sequelize, DataTypes } = require('sequelize');
require('dotenv').config();
const config = require('../config');

const { dialect } = config;

const sequelize = new Sequelize(process.env.DB_NAME, process.env.DB_USER, process.env.DB_PASSWORD, {
    host: process.env.HOST_NAME,
    dialect
});

// create table users
const Users = sequelize.define('users', {
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
        allowNull: false
    },
    job: {
        type: DataTypes.STRING,
        allowNull: false
    },
    photo: {
        type: DataTypes.STRING,
        allowNull: false
    },
    email: {
        type: DataTypes.STRING,
        unique: true,
        allowNull: false
    },
    password: {
        type: DataTypes.STRING,
        allowNull: false
    },
    isAdmin: {
        type: DataTypes.BOOLEAN,
        defaultValue: false,
        allowNull: false
    }
}, {timestamps: false});

// create table cities
const Cities = sequelize.define('cities', {
    id: {
        type: DataTypes.INTEGER,
        primaryKey: true,
        autoIncrement: true
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
}, {timestamps: false});

// create table Office
const Office = sequelize.define('office', {
    id: {
        type: DataTypes.INTEGER,
        primaryKey: true,
        autoIncrement: true
    },
    name: {
        type: DataTypes.STRING,
        allowNull: false,
    }
}, {timestamps: false});

Users.belongsTo(Cities, {foreignKey: 'cityID'});
Users.belongsTo(Office, {foreignKey: 'officeID'});

module.exports = {
    Users,
    Cities,
    Office
}