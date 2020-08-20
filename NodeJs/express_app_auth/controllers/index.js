const jwt = require('jwt-simple');
const bcrypt = require('bcrypt');
const models = require('../models');
const config = require('../config');

const { secret, saltRounds } = config;
const { Users, Cities, Office } = models;

// get all users
const getAllUsers = async (req, res) => {
    try {
        const allUser = await Users.findAll({
            include: [
                { model: Cities, as: 'city', attributes: ['name', 'population'] },
                { model: Office, as: 'office', attributes: ['name'] }
            ],
            attributes: { exclude: ['cityID', 'officeID'] }
        });

        if (allUser) {
            res.send(allUser);
        } else {
            res.statusCode = 404;
            res.send('Not Found');
        }
    } catch (e) {
        res.statusCode = 500;
        res.send('Server error');
    }
};

// get all cities 
const getCities = async (req, res) => {
    try {
        const allCities = await Cities.findAll({
            attributes: { exclude: ['id'] }
        });

        if (allCities) {
            res.send(allCities);
        } else {
            res.statusCode = 404;
            res.send('Not Found');
        }
    } catch (e) {
        res.statusCode = 500;
        res.send('Server error');
    }
};

// get user by id
const getUserById = async (req, res) => {
    try {
        const id = req.params.id;
        const userById = await Users.findByPk(id, {
            include: [
                { model: Cities, as: 'city', attributes: ['name', 'population'] },
                { model: Office, as: 'office', attributes: ['name'] }
            ],
            attributes: { exclude: ['cityID', 'officeID'] }
        });

        if (userById) {
            res.send(userById);
        } else {
            res.statusCode = 404;
            res.send('Not Found');
        }
    } catch (e) {
        res.statusCode = 500;
        res.send('Server error');
    }
};

// get all offices
const getOffices = async (req, res) => {
    try {
        const allOffices = await Office.findAll({
            attributes: { exclude: ['id'] }
        });

        if (allOffices) {
            res.send(allOffices);
        } else {
            res.statusCode = 404;
            res.send('Not Found');
        }
    } catch (e) {
        res.statusCode = 500;
        res.send('Server error');
    }
};

// add new user
const addUser = async (req, res) => {
    try {
        const { email, password, name, lastName, job, photo, city: cityName, office: officeName } = req.body;

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

        bcrypt.hash(password, saltRounds, async function(err, hash) {
            const newUser = await Users.create({
                name, lastName, job, photo,
                cityID: cityID.dataValues.id,
                officeID: officeID.dataValues.id,
                email, password: hash
            });
            res.send(newUser);
        });
    } catch (e) {
        res.statusCode = 500;
        res.send('Add User, Error >>>>>>>>>>>>>');
    }
}

// signUp
const signUp = async (req, res) => {
    try {
        const { email, password } = req.body;

        const user = await Users.findAll({
            where: {
                email
            }
        })

        bcrypt.compare(password, user[0].dataValues.password, function(err, result) {
            if (result) {
                const payload = {
                    id: user[0].dataValues.id,
                    isAdmin: user[0].dataValues.isAdmin
                };
                const token = jwt.encode(payload, secret);
                res.send({ token });
            } else {
                res.statusCode = 401;
                res.send('Unauthorized user >>>>>>>>>>>>>');
            }
        });
    } catch (e) {
        res.statusCode = 500;
        res.send('Authorization Error >>>>>>>>>>>>>');
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
        res.statusCode = 500;
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
        res.statusCode = 500;
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
    addOffice,
    signUp
}