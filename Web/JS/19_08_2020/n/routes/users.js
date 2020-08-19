var express = require('express');
var router = express.Router();
const {Offices, Users, Cities} = require('/home/meruzh/IdeaProjects/n/models/createDatabases');

router.post('/', function(req, res, next) {
  const {name, surname, job, image} = req.body;
  Users.create({name: name, surname: surname, job: job, image: image}).then();
});

router.get('/', function(req, res, next) {
  Users.findAll({attributes : ['name', 'surname', 'job', 'image']}).then(n => res.send(n));
});

module.exports = router;
