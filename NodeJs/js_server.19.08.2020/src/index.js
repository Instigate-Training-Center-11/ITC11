const bodyParser = require('body-parser');
const express = require('express');
const models = require('./models');
const configs = require('./configs');
const controllers = require('./controllers');

const {createUsers,createCities,createOffices,getAllCities,allUsers, getUsersById,getAllOffices,} = controllers;
const app = express();

const exp = (error,req,res,next) => {
    res.writeHead(200,{'Content-Type':'application/json; charset=utf-8'})
    if(error) {
        res.status(400);
        res.send('no such format json');
    } else {
        next();
    }
}

app.use (bodyParser.json(),exp);

const {Users,Cities,Offices} = models;


app.post('/cities',createCities);
app.post('/offices',createOffices);
app.post('/users',createUsers);


const sync = async () => {

    try {
        await Cities.sync();
        // await Offices.sync();
        await Users.sync();
        console.log('Connection has been established successfully.');
        console.log(`Server listen port  ${configs.port}`);
    } catch (error) {
        console.error('Unable to connect to the database:', error);
    }
}

app.get('/users', allUsers);
app.get('/cities', getAllCities);
app.get('/offices', getAllOffices);
app.get('/users/:id', getUsersById);

/*
const deleteUsers = (req,res) => {
    To Do
};
*/

sync();

app.listen(configs.port);
