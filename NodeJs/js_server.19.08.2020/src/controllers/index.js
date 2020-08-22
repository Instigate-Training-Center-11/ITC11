const models = require('../models');

const {Users, Cities, Offices} = models;

/*
const allUsers = async(req, res) => {
    try {
        const users = Users.findAll({
            include: [
                {model: Cities, as: 'city', attributes: ['name']},
                {model: Offices, as: 'office', attributes:['name']}
            ],
            attributes: { exclude:['cityID'],exclude: ['OfficeID'] }
        })
        res.send(users);
    } catch(e) {
        console.log(e)
    }
}
*/

const allUsers = async(req, res) => {
    console.log('aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa')
    try {
        const users = await Users.findAll({
            include: [{ model: Cities, as: 'city', attributes: ['name'] }],
            attributes: {exclude:['cityID'],exclude: ['OfficeID']}
        })
        res.send(users);
    } catch(e) {
        console.log(e)
    }
}


const createUsers = async(req, res) => {
    try {
        const { firstName, lastName, job, imageUrl, city, office } = req.body;
        const cityID = await Cities.findOne({
            where: {name: city},
            attributes: ['id']
        })
        if(!cityID) {
            res.status(400);
            res.send('no such city');
        }
        // const officeID = await Offices.findOne({
        //     where: {name: office},
        //     attributes: ['id']
        // })
        // if(!officeID) {
        //     res.status(400);
        //     res.send('no such city');
        // }
        const newUser = await Users.create({
            firstName,
            lastName,
            job,
            imageUrl,
            cityID: cityID.dataValues.id,
            // officeID: officeID.dataValues.id
        })
        res.send(newUser);
    } catch(e) {
        console.log(e)
        res.status(500);
        res.send('Internal error');
    }
}


const createOffices = async(req, res) => {
    try {
        const { name} = req.body;
        const newOffices = await  Offices.create({
            name
        })
        res.send(newOffices);
    } catch(e) {
        res.status(500);
        res.send('Internal error');
    }
}

const createCities = async(req, res) => {

    console.log('newCitynewCitynewCitynewCitynewCitynewCitynewCitynewCitynewCitynewCity')
    try {
        const { name, isCapital, population} = req.body;
        const newCity = await Cities.create({
            name,isCapital,population
        })
        res.send(newCity);
    } catch(e) {
        res.status(500);
        res.send('Internal error');
    }
}


const deleteUser = (req, res) => {
    res.send('Get request to the homepage');
};

const getAllCities = async (req, res) => {
    const cities = await Cities.findAll();
    res.send(cities);
}

const getUsersById = async (req,res) => {

    const result = await Users.findAll({
        where: {
            id: req.params.id
        }
    });
    res.send(result);

}

const getAllOffices = async (req, res) => {
    const getOffices = await Offices.findAll();
    res.send(getOffices);
}


module.exports = {
    allUsers,
    createUsers,
    deleteUser,
    createCities,
    createOffices,
    getAllCities,
    getAllOffices,
    getUsersById
}