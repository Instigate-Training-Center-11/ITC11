const models = require('../models');

const {Users, Cities, Offices} = models;

const allUsers = async(req, res) => {
    try {
        const users = Users.findAll({
            include: [{models:Cities, as: 'city', attributes: ['name']},
            {models:Offices, as: 'office', attributes:['name']}],
            attributes: {exclude:['cityID'],exclude: ['OfficeID']}
        })
        res.send(users);
    } catch(e) {

    }
}


const createUsers = async(req, res) => {
    try {
        const { name, surname, age, job, image, city: cityName,office: officeName } = req.body;
        const cityID = Cities.findOne({
            where: {
                name:cityName
            },
            attributes: ['id']
        })
        if(!cityID) {
            res.status(400);
            res.send('no such city');
        }
        const newUser = await Users.create({
            name, surname, age, job, image, cityID: cityID.dataValue.id, OfficeID: OfficeID.dataValue.id
        })
        res.send(newUser);
    } catch(e) {
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


const updateUser = (req, res) => {
    res.send('Get request to the homepage');
};

const getUser = (req, res) => {
    res.send('Get request to the homepage');
};

const deleteUser = (req, res) => {
    res.send('Get request to the homepage');
};

const getAllUsers = async (req, res) => {
    const users = await Users.findAll();
    res.send(users);
}

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
    updateUser,
    getAllUsers,
    deleteUser,
    createCities,
    createOffices,
    getAllCities,
    getAllOffices,
    getUsersById
}