let models = require('../models');
const { Offices } = require('../models');
let {User, Cities} = models;

const allCities = async (req, res) => {
  const cities = await Cities.findAll({
    attributes: { exclude: ['id'] },
  });
  try {
    res.send(cities);
  } catch (e) {
    res.statusCode = 404;
    res.send('Cities ot found');
  }
};

const allOffices = async (req, res) => {
  const offices = await Offices.findAll({
    attributes: {exclude: ['id']},
  })
  try {
    res.send(offices);
  } catch (e) {
    res.statusCode = 404;
    res.send('Offices not found');
  }
};

const allUser = async (req, res) => {
  try {
    const users = await User.findAll({
      include: [
        {model: Cities, as: 'city', attributes: ['name', 'isCapital', 'population']},
        {model: Offices, as: 'office', attributes: ['name']},
      ],
      attributes: { exclude: ['cityID', 'officeID'] },
    })
    res.send(users);
  } catch(e) {
    res.statusCode = 404;
    res.send('Users not found');
  }
};

const oneUser = async (req, res) => {
  try {
    const one = await User.findByPk(req.params.id, {
      include: [
        {model: Cities, as: 'city', attributes: ['name', 'isCapital', 'population']},
        {model: Offices, as: 'office', attributes: ['name']},
      ],
      attributes: { exclude: ['cityID', 'officeID'] },
    })
    res.send(one);
  } catch(e) {
    res.statusCode = 404;
    res.send('User not found');
  }
};

const addOffices = async (req, res) => {
  try {
    const { name } = req.body;
    const newOffice = await Offices.create({
      name
    })
    res.send(newOffice);
  } catch(e) {
    res.statusCode = 500;
    res.send('Server error');
  }
}

const addCity = async (req, res) => {
  try {
    const { name, isCapital, population} = req.body;
    const newCity = await Cities.create({
      name, isCapital, population
    })
    res.send(newCity);
  } catch (e) {
    res.statusCode = 500;
    res.send('Server error');
  }
}

const addUser = async (req, res) => {
  try {
    const { name, lastName, job, photo, city: cityName, office: officeName } = req.body;
    const cityId = await Cities.findOne({
      where: {
        name: cityName,
      },
      attributes: ['id'],
    })

    const officeId = await Offices.findOne({
      where: {
        name: officeName,
      },
      attributes:['id'],
    })

    console.log('hhhhh',officeId);
    console.log('ccccccccccc',cityId);
    if(!cityId || !officeId) {
      res.statusCode = 400;
      res.send('Invalid data');
    }

    const newUser = await User.create({
      name, lastName, job, photo,
      cityId: cityId.dataValues.id, officeId: officeId.dataValues.id
    })
    res.send(newUser);
  } catch (e) {
    res.statusCode = 500;
    res.send('Server error');
  }
}

module.exports = {
  allCities,
  allOffices,
  allUser,
  oneUser,
  addOffices,
  addCity,
  addUser
}