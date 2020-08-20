const express = require('express');
const bodyParser = require('body-parser')
const models = require('./models');
const controllers = require('./controllers');
const config = require('./config');
const peoples = require('./json/people.json');
const services = require('./services');
 
const app = express();
const { authUsers, authAdmin } = services;
const { Users, Cities, Office } = models;
const {
    getAllUsers,
    getCities,
    getUserById,
    getOffices,
    addUser,
    addCity,
    addOffice,
    signUp
} = controllers;

app.use(bodyParser.json());

const connect = async () => {
    try {
        await Users.sync();
        await Cities.sync();
        await Office.sync();

        // // insert into cities
        // await Cities.create({
        //     name: 'Vanadzor',
        //     isCapital: false,
        //     population: 80000
        // });
        // await Cities.create({
        //     name: 'Gyumri',
        //     isCapital: false,
        //     population: 115000
        // });
        // await Cities.create({
        //     name: 'Erevan',
        //     isCapital: true,
        //     population: 1000000
        // });
        // await Cities.create({
        //     name: 'Aparan',
        //     isCapital: false,
        //     population: 32000
        // });

        // // insert into offices
        // await Office.create({
        //     name: 'IBM'
        // });
        // await Office.create({
        //     name: 'MICROSOFT'
        // });
        // await Office.create({
        //     name: 'ORACLE'
        // });

        ////////////////////////////////////////////////////////////////////////

        // // // insert into users
        // for (let i = 0; i < peoples.peoplesData.length; ++i) {
        //     bcrypt.hash(peoples.peoplesData[i].password, saltRounds, async function(err, hash) {
        //         console.log(hash)

        //         await Users.create({
        //             ...peoples.peoplesData[i],
        //             password: hash
        //         })
        //     });  
        // }

        // await Users.create({
        //     name: 'Admin',
        //     lastName: 'Admin',
        //     job: 'admin',
        //     photo: 'aaa',
        //     email: 'admin@mail.ru',
        //     password: '$2b$10$o9uBRqQv6MKawtIWko1IAef3orIJ8uzOfnxz0n9yFNsdih6oi5czu', // pass = admin
        //     isAdmin: true,
        // })

        console.log('Connection has been established successfully.');
    } catch (error) {
        console.error('Unable to connect to the database:', error);
    }
}

connect();

app.get('/users', authUsers, getAllUsers);
app.get('/users/:id', getUserById);
app.get('/cities', getCities);
app.get('/offices', getOffices);
app.post('/adduser', addUser);
app.post('/addcity', authAdmin, addCity);
app.post('/addoffice', addOffice);
app.post('/signup', signUp);
 
app.listen(config.port, () => console.log('connection ...'));