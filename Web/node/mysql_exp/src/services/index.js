const jwt = require('jwt-simple');
const configs = require('../configs');
require('dotenv').config();

const auth = (req, res, next) => {

    const token = req.headers.authorization;
    if (!token) {
        res.status(401);
        res.send('Unauthorized');
    }
    try {
        decoded = jwt.decoded(token, configs.secretKey);
        next();
    } catch (e) {
        res.status(401);
        res.send('invalid token');
    }
    //console.log(decoded);
}

const authAdmin = (req, res, next) => {
    const token = req.headers.authorization;
    if (!token) {
        res.status(401);
        res.send('Unauthorized');
    }
    try {
        decoded = jwt.decoded(token, configs.secretKey);
        if (!decoded.isAdmin) {
            res.status(403);
            res.send('Unauthorized');
        } else {
            res.send('Is admin');
        }
    } catch (e) {
        console.log('Some text')
        res.status(401);
        res.send('Invalid token');
    }
}
const verifyBody = (err, req, res, next) => {
    if (err) {
        res.status(400);
        res.send('Invalid Json');
    } else {
        next();
    }
}
module.exports = {
    auth,
    verifyBody
}