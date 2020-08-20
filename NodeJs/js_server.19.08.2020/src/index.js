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


app.post('/users',createUsers);
app.post('/cities',createCities);
app.post('/offices',createOffices);


const sync = async () => {

    try {

        await Cities.sync();
        await Users.sync();
        await Offices.sync();
        console.log('Connection has been established successfully.');
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

};
*/

sync();

app.listen(configs.port);
console.log(`Server listen port  ${configs.port}`)