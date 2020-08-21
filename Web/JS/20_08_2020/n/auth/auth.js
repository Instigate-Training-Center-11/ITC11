let express = require('express');
let router = express.Router();
let jwt = require('jwt-simple');
let HttpStatus = require('http-status-codes');
let bcrypt = require('bcrypt');
const {Offices, Users, Cities} = require('/home/meruzh/IdeaProjects/n/models/createDatabases');

router.use(function(req, res, next) {
    if( req.hasOwnProperty('headers') && req.headers.hasOwnProperty('authorization') ) {
        try {
            const {name, surname, email, isAdmin, password} = req.body;
            Users.findOne({
                where: {
                    email: email,
                    isAdmin: isAdmin,
                }
            }).then(user => {
               // bcrypt.compare(password, user.password, (err, result) => {
               //      if (result) {
                        console.log(surname);
                        const token = jwt.encode({isAdmin}, 'some');
                        res.header('authorization', token);
                    // } else {
                    // }
            });
            // const token = jwt.encode({isAdmin}, 'some');
            // res.header('authorization', token);
        } catch(err) {

        }
    } else {
        res.status(HttpStatus.UNAUTHORIZED);
    }
    next();
});


module.exports=router;