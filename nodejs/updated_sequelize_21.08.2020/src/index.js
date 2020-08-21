// const bcrypt = require('bcrypt');
// let peoplesJson = require('./peoples');

let auth = require('./auth');
let configs = require('./configs');
let express = require('express');
let bodyParser = require('body-parser');
let models = require('./models');
let controllers = require('./controllers');
let app = express();
let {User, Cities, Offices} = models;
const {allCities, allOffices, allUser, oneUser, addOffices, addCity, signIN, signUP} = controllers;
const {authUser, authAdmin} = auth;

app.use(bodyParser.json());
const connect = async() => {
  try {
    await Offices.sync();
    await Cities.sync();
    await User.sync();

   { // await Offices.create({ name: 'Nokia', });
    // await Offices.create({ name: 'Samsung', });
    // await Offices.create({ name: 'Motorola', });

    // await Cities.create({ name: 'Vanadzor', isCapital: false, population: 10000 });
    // await Cities.create({ name: 'Gyumri', isCapital: false, population: 20000 });
    // await Cities.create({ name: 'Erevan', isCapital: true, population: 30000 });
    // await Cities.create({ name: 'Aparan', isCapital: false, population: 40000 });

    // await User.create({
    //   name: 'Admin',
    //   lastName: 'Admin',
    //   job: 'admin',
    //   photo: 'aaa',
    //   email: 'admin@mail.ru',
    //   password: '$2b$10$o9uBRqQv6MKawtIWko1IAef3orIJ8uzOfnxz0n9yFNsdih6oi5czu',
    //   isAdmin: true,
    // })

    // for (let i = 0; i < peoplesJson.peoplesData.length; ++i) {
    //   bcrypt.hash(peoplesJson.peoplesData[i].password, configs.saltRounds, async function(err, hash) {
    //     await User.create({
    //       ...peoplesJson.peoplesData[i],
    //       password: hash
    //     })
    //   });
    // }

    //await sequelize.authenticate();
  }
    console.log('Connection has been established successfully.');
  } catch (error) {
    console.error('Unable to connect to the database:', error);
  }
}

connect();

app.get('/users', authUser, allUser);
app.get('/users/:id', oneUser);
app.get('/cities', allCities);
app.get('/offices', allOffices);
app.post('/addoffices', addOffices);
app.post('/addcities', authAdmin, addCity);
app.post('/addusers', signIN);
app.post('/signUP', signUP);

app.listen(configs.port);