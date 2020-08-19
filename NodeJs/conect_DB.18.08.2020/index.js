var express = require('express');
const configs = require('./src/configs');
var users = require('./users/users.json');
var investments = require('./investments/investmentsData.json');
const cors = require("cors");

var corsOptions = {
    origin: "http://localhost:3000"
};


var app = express();
app.use(cors(corsOptions));

const { Sequelize, DataTypes, UUID, STRING } = require('sequelize');

const { host_name, db_name, db_user, db_password } = configs;

const sequelize = new Sequelize(db_name, db_user, db_password, {
    host_name: host_name,
    dialect: 'mysql'
});

const Investments = sequelize.define('Investments', {
    id: {
        type: DataTypes.UUID,
        primaryKey: true,
        defaultValue: Sequelize.UUIDV4,
        unique: true
    },
    investments: {
        type: DataTypes.INTEGER,
        allowNull: false
    }
}, {
    freezeTableName: true
});

const Users = sequelize.define('Users', {
    id: {
        type: DataTypes.UUID,
        primaryKey: true,
        defaultValue: Sequelize.UUIDV4,
        unique: true
    },
    firstName: {
        type: DataTypes.STRING,
        allowNull: false
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
    },
}, {
    freezeTableName: true
});

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

/*
var arrInvestments = investments.investmentsData;
var arrUsers = users.peoplesData;
for (let i = 0; i < arrUsers.length; i++) {
    sequelize.sync()
    .then(() => Users.create({
        firstName:arrUsers[i].name,
        lastName:arrUsers[i].surname,
        job:arrUsers[i].job,
        imageUrl:arrUsers[i].img
    }))
    .then(jane => {
        console.log(jane.toJSON());
    });
}

for (let i = 0; i < arrInvestments.length; i++) {
    sequelize.sync()
    .then(() => Investments.create({
        investments:arrInvestments[i].investments
    }))
    .then(jane => {
        console.log(jane.toJSON());
    });
}
*/


const allUsers = async (req, res) => {
    const users = await Users.findAll();
    res.send(users);
}

const allInvestments = async (req, res) => {
    const investments = await Investments.findAll();
    res.send(investments);
}

const findInvestmentsById = async (req,res) => {

    const result = await Investments.findAll({
        where: {
            id: req.params.id
        }
    });
    res.send(result);

}


const findUsersById = async (req,res) => {

    const result = await Users.findAll({
        where: {
            id: req.params.id
        }
    });
    res.send(result);

}

app.get('/users', allUsers);
app.get('/investments',allInvestments);
app.get('/investments/:id',findInvestmentsById);
app.get('/users/:id',findUsersById);

connect();
app.listen(3000);
