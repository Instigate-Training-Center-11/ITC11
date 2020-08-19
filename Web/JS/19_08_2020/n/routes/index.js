var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  const {Offices, Users, Cities} = require('/home/meruzh/IdeaProjects/n/models/createDatabases');
  const {name, surname, job, image} = req.body;
  Users.create({name: name, surname: surname, job: job, image: image}).then();
  console.log(req.body);
  res.render('index', { title: 'Express' });
});
router.get('/k', function(req, res) {
  res.send('hello world');
});
module.exports = router;
