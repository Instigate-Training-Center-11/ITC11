var express = require('express');
var router = express.Router();
const {Offices, Users, Cities} = require('/home/meruzh/IdeaProjects/n/models/createDatabases');

router.post('/', function(req, res, next) {
    const {name, isCapital, population} = req.body;
    Cities.create({name: name, isCapital: isCapital, population: population}).then();
});

router.get('/', function(req, res, next) {
    Cities.findAll({attributes : ['name', 'isCapital', 'population']}).then(n => res.send(n));
});

module.exports = router;