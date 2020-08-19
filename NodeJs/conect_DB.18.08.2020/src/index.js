var express = require('express');
const configs = require('./src/configs/');
var app = express();

const {Sequelize,DataTypes, UUID, STRING} = require('sequelize');

const {host_name,db_name,db_user,db_password} = configs;

const sequelize = new  Sequelize(db_name,db_user,db_password,{
    host_name:host_name,
    dialect:'mysql'
})


const Investments = sequelize.define('Investments',{
    id:{
        type:DataTypes.STRING,
        primaryKey:true,
    },
    investments:{
        type:DataTypes.INTEGER,
        allowNull:false
    }
}, {
    freezeTableName: true
});

const Users = sequelize.define('Users',{
    id:{
        type:DataTypes.UUID,
        primaryKey:true,
        defaultValue: Sequelize.UUIDV4
    },
    firstName:{
        type:DataTypes.STRING,
        allowNull:false
    },
    lastName:{
        type:DataTypes.STRING,
        allowNull:false
    },
    job:{
        type:DataTypes.STRING,
        allowNull:false
    },
    imageUrl:{
        type:DataTypes.STRING,
        allowNull:false
    },
}, {
    freezeTableName: true
});


const connect=async () => {

    try {
        await sequelize.authenticate();
        await Users.sync();
        await Investments.sync();
        console.log('Connection has been established successfully.');
    } catch (error) {
        console.error('Unable to connect to the database:', error);
    }
}
console.log(Users === sequelize.models.Users);
/*
const addUsers = (req,res) => {

};

const allUsers = (req,res) => {

};


const updateUsers = (req,res) => {

};



const deleteUsers = (req,res) => {

};

const deleteUsers = (req,res) => {

};
*/

connect();
app.listen(3000);