// let peoplesJson = require('./peoples');
let express = require('express');
let bodyParser = require('body-parser');
let models = require('./models');
let controllers = require('./controllers');
let app = express();
let {User, Cities, Offices} = models;
const {allCities, allOffices, allUser, oneUser, addOffices, addCity, addUser} = controllers;

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

    // for (let i = 0; i < peoplesJson.peoplesData.length; ++i) {
    //   await User.create(peoplesJson.peoplesData[i]);
    // }

    //await sequelize.authenticate();
  }
    console.log('Connection has been established successfully.');
  } catch (error) {
    console.error('Unable to connect to the database:', error);
  }
}

connect();

app.get('/users', allUser);
app.get('/users/:id', oneUser);
app.get('/cities', allCities);
app.get('/offices', allOffices);
app.post('/offices', addOffices);
app.post('/cities', addCity);
app.post('/addusers', addUser);

app.listen(3000);

// "body-parser": "^1.19.0",
//     "depd": "^2.0.0",
//     "events": "^3.2.0",
//     "express": "^4.17.1",
//     "mysql2": "^2.1.0",
//     "sequelize": "^6.3.4"