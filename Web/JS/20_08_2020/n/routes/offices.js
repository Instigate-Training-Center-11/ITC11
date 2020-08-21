var express = require('express');
var router = express.Router();
const {Offices, Users, Cities} = require('/home/meruzh/IdeaProjects/n/models/createDatabases');

router.post('/', function(req, res, next) {
  const {name} = req.body;
  Offices.create({name: name}).then();
});

router.get('/', function (req, res, next) {
  Offices.findAll({attributes : ['name']}).then(n => res.send(n));
});

module.exports = router;
