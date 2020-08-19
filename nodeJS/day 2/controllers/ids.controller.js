const { id } = require('../models/id');

const getInvestments = async function(req, res) {
    const ids = await id.findAll();
    res.send(ids)
}

const getInvestmentsByID = async function(req, res) {
    const invest = req.params.id;
    const ids = await id.findAll({
        where: {
            id: Number(invest)
        }
    })
    if (ids && ids.length > 0) {
        res.send(ids[0]);
    } else {
        res.status(405).send({
            message: "Can't find id!"
        });
    }
}

module.exports = {
    getInvestments,
    getInvestmentsByID
}