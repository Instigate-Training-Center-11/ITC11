const { user } = require('../models/user');

const getUsers = async function(req, res) {
    const users = await user.findAll();
    res.send(users);
}

const getUserByID = async function(req, res) {
    const id = req.params.id;
    const users = await user.findAll({
        where: {
            id: Number(id)
        }
    });

    if (users && users.length > 0) {
        res.send(users[0]);
    } else {
        res.status(405).send({
            message: "Can't find user!"
        });
    }
}

const wrongURL = async function(req, res) {
    res.status(404).json({
        message: "Can't find this page!"
    });
}

module.exports = {
    getUsers,
    getUserByID,
    wrongURL
}