let express = require('express');
let router = express.Router();
let jwt = require('jwt-simple');
let HttpStatus = require('http-status-codes');
let bcrypt = require('bcrypt');
const {Offices, Users, Cities} = require('/home/meruzh/IdeaProjects/n/models/createDatabases');

router.use(function(req, res, next) {
    console.log('lkjl');
    if( req.hasOwnProperty('headers') && req.headers.hasOwnProperty('authorization') ) {
        try {
            const {name, surname, email, isAdmin, password} = req.body;
            // let us = async function() {
            //     return Users.findOne({
            //     where: {
            //         email: email,
            //         isAdmin: isAdmin,
            //     }
            // })}();
            //us.then(n => console.log(n));
            // bcrypt.compare(password, us.dataValues.password, (err, result) => {
            //     if (result) {
            //         const token = jwt.encode({id: us.dataValues.id}, 'some');
            //         res.header('authorization', token);
            //     } else {
            //     }
            // });
            const token = jwt.encode({isAdmin}, 'some');
            res.header('authorization', token);
        } catch(err) {

        }
    } else {
        res.status(HttpStatus.UNAUTHORIZED);
    }
    next();
});


module.exports=router;