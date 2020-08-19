const models = require('../models');
const { Users, Cities, Office } = models;

// get all users
const getAllUsers = async (req, res) => {
    const allUser = await Users.findAll({
        include: [
            { model: Cities, as: 'city', attributes: ['name', 'population']},
            { model: Office, as: 'office', attributes: ['name']}
        ],
        attributes: { exclude: ['cityID', 'officeID'] }
    });

    if (allUser) {
        res.send(allUser);
    } else {
        res.statusCode = 404;
        res.send('Not Found');
    }
};

// get all cities 
const getCities = async (req, res) => {
    const allCities = await Cities.findAll({
        attributes: {exclude: ['id']}
    });

    if (allCities) {
        res.send(allCities);
    } else {
        res.statusCode = 404;
        res.send('Not Found');
    }
};

// get user by id
const getUserById = async (req, res) => {
    const id = req.params.id;
    const userById = await Users.findByPk(id, {
        include: [
            { model: Cities, as: 'city', attributes: ['name', 'population']},
            { model: Office, as: 'office', attributes: ['name']}
        ],
        attributes: { exclude: ['cityID', 'officeID'] }
    });

    if (userById) {
        res.send(userById);
    } else {
        res.statusCode = 404;
        res.send('Not Found');
    }
};

// get all offices
const getOffices = async (req, res) => {
    const allOffices = await Office.findAll({
        attributes: {exclude: ['id']}
    });

    if (allOffices) {
        res.send(allOffices);
    } else {
        res.statusCode = 404;
        res.send('Not Found');
    }
};

// add new user
const addUser = async (req, res) => {
    try {
        const { name, lastName, job, photo, city: cityName, office: officeName } = req.body;

        const cityID = await Cities.findOne({
            where: {
                name: cityName
            },
            attributes: ['id']
        });

        const officeID = await Office.findOne({
            where: {
                name: officeName
            },
            attributes: ['id']
        });

        if (!cityID || !officeID) {
            res.status = 400;
            res.send('City or Office Not Exist');
        };

        const newUser = await Users.create({
            name, lastName, job, photo, cityID: cityID.dataValues.id, officeID: officeID.dataValues.id,
        });

        res.send(newUser);
    } catch (e) {
        res.status = 500;
        res.send('Add User, Error >>>>>>>>>>>>>');
    }
}

// add new city
const addCity = async (req, res) => {
    try {
        const { name, isCapital, population } = req.body;

        const newCity = await Cities.create({
            name, isCapital, population
        });
        res.send(newCity);
    } catch (e) {
        res.status = 500;
        res.send('Add City, Error >>>>>>>>>>>>>');
    }
}

// add office
const addOffice = async (req, res) => {
    try {
        const { name } = req.body;

        const newOffice = await Office.create({
            name
        });

        res.send(newOffice);
    } catch (e) {
        res.status = 500;
        res.send('Add Office, Error >>>>>>>>>>>>>');
    }
}

module.exports = {
    getAllUsers,
    getCities,
    getUserById,
    getOffices,
    addUser,
    addCity,
    addOffice
}