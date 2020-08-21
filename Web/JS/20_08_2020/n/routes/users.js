var express = require('express');
let bcrypt = require('bcrypt');
var router = express.Router();
const {Offices, Users, Cities} = require('/home/meruzh/IdeaProjects/n/models/createDatabases');

router.post('/', function(req, res, next) {
  const {name, surname, email, isAdmin, password} = req.body;
  //console.log(bcrypt.hashSync(password, 10));
  // jwt.encode({email, password, isAdmin}, 'some');
  Users.create({name: name, surname: surname, email: email, isAdmin:
      isAdmin, password: bcrypt.hashSync(password, 10)}).then();
});

/*router.get('/', function(req, res) {
  res.send("tagId is set to " + req.params.id);
});*/

router.get('/', function(req, res, next) {
    if(req.hasOwnProperty('headers') && req.headers.hasOwnProperty('authorization')) {
        Users.findAll({attributes: ['name', 'surname', 'email']}).then(n => res.send(n));
    } else {
        res.send('Please authorized!');
    }
});


module.exports = router;

