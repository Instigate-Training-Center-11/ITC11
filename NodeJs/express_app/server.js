const express = require('express');
const app = express();
const { Sequelize, DataTypes } = require('sequelize');
const config = require('./config');
const peoples = require('./json/people.json');
const inv = require('./json/investments.json');

const { host_name, db_name, db_user, db_password } = config;

const sequelize = new Sequelize(db_name, db_user, db_password, {
    host: host_name,
    dialect: 'mysql'
});

// create table users
const Users = sequelize.define('users', {
    id: {
        type: DataTypes.UUID,
        primaryKey: true,
        unique: true
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
    imageUrl: {
        type: DataTypes.STRING,
        allowNull: false
    }
}, {});

// create table investments
const Investments = sequelize.define('investments', {
    id: {
        type: DataTypes.UUID,
        primaryKey: true,
        unique: true
    },
    investments: {
        type: DataTypes.INTEGER,
        allowNull: false,
    },
}, {});

const connect = async () => {
    try {
        await sequelize.authenticate();
        await Users.sync();
        await Investments.sync();
        console.log('Connection has been established successfully.');
    } catch (error) {
        console.error('Unable to connect to the database:', error);
    }
}

connect();

async function createUsersTable() {
    for(var i = 0; i < peoples.peoplesData.length; ++i) {
        await Users.create({
            id: peoples.peoplesData[i].id, 
            name: peoples.peoplesData[i].name,
            lastName: peoples.peoplesData[i].lastName,
            job: peoples.peoplesData[i].job,
            imageUrl: peoples.peoplesData[i].photo,
        });
    }
};
// createUsersTable();

async function createInvestmentsTable() {
    for(var i = 0; i < inv.investmentsData.length; ++i) {
        await Investments.create({
            id: inv.investmentsData[i].id, 
            investments: inv.investmentsData[i].investments,
        });
    }
};
// createInvestmentsTable();

// find all users 
const getAllUsers = async (req, res) => {
    const allUser = await Users.findAll();

    if (allUser) {
        res.send(allUser);
    } else {
        res.statusCode = 404;
        res.send('Not Found');
    }
};

// get all investments 
const getInvestments = async (req, res) => {
    const allInvestments = await Investments.findAll();

    if (allInvestments) {
        res.send(allInvestments);
    } else {
        res.statusCode = 404;
        res.send('Not Found');
    }
};

// get user by id
const getUserById = async (req, res) => {
    const id = req.params.id;
    const userById = await Users.findByPk(id);

    if (userById) {
        res.send(userById);
    } else {
        res.statusCode = 404;
        res.send('Not Found');
    }
};

// get user by id
const getInvestmentsById = async (req, res) => {
    const id = req.params.id;
    const invById = await Investments.findByPk(id);

    if (invById) {
        res.send(invById);
    } else {
        res.statusCode = 404;
        res.send('Not Found');
    }
};

app.get('/users', getAllUsers);
app.get('/investments', getInvestments);
app.get('/users/:id', getUserById);
app.get('/investments/:id', getInvestmentsById);
 
app.listen(3000, () => console.log('connection ...'))