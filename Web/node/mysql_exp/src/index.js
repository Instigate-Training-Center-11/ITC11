const bodyParser = require('body-parser');
const express = require("express");
const models = require('./models');
const configs = require('./configs');
const controllers = require('./controllers');
const services = require('./services');

// const bcrypt = require('bcrypt');
// const users = require('./users.json');
// const { createUsers } = controllers;

const app = express();
const { auth, verifyBody } = services;
const { signUp, allUsers, signIn, addCity } = controllers;
app.use(bodyParser.json(), verifyBody);
const { Users, Cities } = models;
app.post('/signin', signIn);
app.post('/signup', signUp);
app.get('/users', auth, allUsers);
app.get('/cities', addCity);

/*sync to database */
const sync = async () => {
    try {
        await Users.sync()
        await Cities.sync()

        await Cities.create({
            name: 'Vanadzor',
            isCapital: false,
            population: 10000
        })
        await Cities.create({
            name: 'Yerewan',
            isCapital: true,
            population: 40000
        })
        await Cities.create({
            name: 'Gyumry',
            isCapital: false,
            population: 30000
        })
        await Cities.create({
            name: 'Aparan',
            isCapital: false,
            population: 20000
        })
        await Users.create({
            name: 'Admin',
            surname: 'Admin',
            age: 20,
            jod: 'Admin',
            image: './src/9.jpg',
            cityID: 1,
            email: 'admin@gmail.com',
            isAdmin: true,
            password: hash /* to insert hash */
        })

        for (let i = 0; i < users.length; ++i) {
            bcrypt.hash(users[i].password, config.saltRounds, async function (err, hash) {

                console.log('New User ', {
                    ...users[i],
                    password: hash  /* to insert hash */
                })

                await Users.create({
                    ...users[i],
                    password: hash /* to insert hash */
                })
            });
        }
        console.log('Connection has been established successfully.');
    } catch (error) {
        console.error('Unable to connect to the database:', error);
    }
}
sync()
app.listen(configs.port)
console.log(`Srever listen port ${configs.port}`)
