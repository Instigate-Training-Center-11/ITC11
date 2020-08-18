var express = require('express');
const configs = require('./configs');
var app = express();

const {Sequelize} = require('sequelize');
const {host_name,db_name,db_user,db_password} = configs;

const sequelize = new  Sequelize(db_name,db_user,db_password,{
    host_name:host_name,
    dialect:'mysql'
})

const connect=async () => {

    try {
        await sequelize.authenticate();
        console.log('Connection has been established successfully.');
    } catch (error) {
        console.error('Unable to connect to the database:', error);
    }
}
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


app.listen(3000,'127.0.0.1');