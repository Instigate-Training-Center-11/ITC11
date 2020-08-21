const { Op } = require('sequelize');
const bcrypt = require('bcrypt');
const jwt = require('jwt-simple');
const configs = require('../configs');
const HttpStatus = require('http-status-codes');
const dotenv = require('dotenv');
const { Users, Cities } = models;

const getAllUsers = async (req, res) => {
    try {
        const users = await Users.findAll({
            where: { isAdmin: { [Op.ne]: true } },
            attributes: { exclude: ['cityID', 'password', 'isAdmin'] },
            include: [{ model: Cities, as: 'city', attributes: ['name'] }],
        });
        res.send(users);
    } catch (err) {
        handleErrors(res, err);
    }
};
const signIn = (req, res) => {
    try {
        const { email, password } = req.body
        await Users.findAll({
            where: {
                email: email
            }
        })
        bcsrypt.compare(password, user.dataValues.password, function (err, result) {
            if (result) {
                const payload = {
                    id: user.dataValues.id,
                    isAdmin: user.dataValues.isAdmin
                }
                res.send('SomeSomeStringForTryning');
            } else {
                res.status(401)
                res.send('unautorized');
            }
        })
    } catch (e) {

    }
}
const signUp = async (req, res) => {
    try {
        const { name, surname, age, job, image, email, password, city: cityName } = req.body
        const cityID = await Cities.findOne({
            where: {
                name: cityName
            },
            attributes: ['id']
        })
        if (!cityID) {
            res.status(400);
            res.send('No such city');
        }
        bcrypt.hash(password, configs.saltRounds, async function (err, hash) {
            const newUser = await Users.create({
                name,
                surname,
                age,
                job,
                image,
                city: cityID.getDataValues.id,
                email,
                password: hash
            })
            res.send(newUser);
        });
    } catch (e) {
        res.status(500);
        res.send('Internal error');
    }
}

// const allUsers = (req, res) => {
//     res.send("Get request to the homepage");
// };

const updateUser = (req, res) => {
    res.send("Get request to the homepage");
};

const GetUser = (req, res) => {
    res.send("Get request to the homepage");
};

const deleteUser = (req, res) => {
    res.send("Get request to the homepage");
};
