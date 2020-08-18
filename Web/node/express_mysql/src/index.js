let peoples = require("./peoples.json");
let inv = require("./investments.json");

const { Sequelize, DataTypes } = require('sequelize');

var express = require("express");

const configs = require('./configs');

var app = express();

console.log(configs);

const { host_name, db_name, db_user, db_password } = configs;

const sequelize = new Sequelize(db_name, db_user, db_password, {
    host: host_name,
    dialect: 'mysql'
});

const User = sequelize.define('user', {
    id: {
        type: DataTypes.UUID,
        primaryKey: true,
        unique: true,
    },
    name: {
        type: DataTypes.STRING,
        allowNull: false
    },
    job: {
        type: DataTypes.STRING,
        allowNull: false,
    },
    imageUrl: {
        type: DataTypes.STRING,
        allowNull: false
    }
}, {
});

const Investments = sequelize.define('investmen', {
    id: {
        type: DataTypes.UUID,
        primaryKey: true,
        unique: true,
    },
    investmen: {
        type: DataTypes.STRING,
        allowNull: false
    }
}, {
});

const insertion = async () => {
    try {
        for (var i = 0; i < inv.length; i++) {
            const investmen = await Investments.create({
                id: parseInt(inv.investmentsData[i].id),
                investmen: inv.investmentsData[i].investments
            }, {});
        }
    } catch (error) {
        console.error('insertion error:', error);
    }
}

const insertionUser = async () => {
    try {
        for (var i = 0; i < peoples.length; i++) {
            const user = await User.create({
                id: parseInt(peoples.peoplesData[i].id),
                name: peoples.peoplesData[i].name,
                job: peoples.peoplesData[i].job,
                imageUrl: peoples.peoplesData[i].imageUrl
            }, {});
        }
    } catch (error) {
        console.error('insertion error:', error);
    }
}

const connect = async () => {
    try {
        await sequelize.authenticate();
        await User.sync()
        await Investments.sync()
        console.log('Connection has been established successfully.');
    } catch (error) {
        console.error('Unable to connect to the database:', error);
    }
}

connect()
insertion()
insertionUser()

app.listen(3002)

// const http = require("http");
// const server = http.createServer((req, res) => {
//     let name = require("url").parse(req.url, true).query.name;
//     let age = require("url").parse(req.url, true).query.age;
//     let users = require("./peoples.json");
//     let investments = require("./investments.json");
//     let path = JSON.stringify(require("url").parse(req.url, true).pathname);
//     if(path === "\"/users\"") {
//         if (name === undefined && age !== undefined) {
//             res.end(JSON.stringify(users.peoplesData.find(item => item.age == age)));
//         } else  if (age === undefined && name !== undefined) {
//             res.end(JSON.stringify(users.peoplesData.find(item => item.name === name)));
//         } else if(age !== undefined && name !== undefined) {
//             res.end(JSON.stringify(users.peoplesData.find(item => item.name === name && item.age == age)));
//         }else {
//             res.end(JSON.stringify(users.peoplesData));
//         }
//     }
//     if(path === "\"/investments\"") {
//         res.end(JSON.stringify(investments.investmentsData));
//     }
//     }
// ).listen(3000);