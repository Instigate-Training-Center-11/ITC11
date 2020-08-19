const { Sequelize, DataTypes } = require('sequelize');
const config = require('../config');

const { host_name, db_name, db_user, db_password } = config;

const sequelize = new Sequelize(db_name, db_user, db_password, {
    host: host_name,
    dialect: 'mysql'
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