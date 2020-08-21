const jwt = require('jwt-simple');

const authUsers = (req, res, next) => {
    const token = req.headers.authorization;

    if(!token) {
        res.statusCode = 400;
        res.send('Not Authorize');
    }

    try {
        decode = jwt.decode(token, process.env.SECRET);
        next();
    } catch (e) {
        res.statusCode = 401;
        res.send('Token Error ----------');
    }
}

const authAdmin = (req, res, next) => {
    const token = req.headers.authorization;

    if(!token) {
        res.statusCode = 400;
        res.send('Not Authorize');
    }

    try {
        decode = jwt.decode(token, process.env.SECRET)
        if (!decode.isAdmin) {
            res.statusCode = 403;
            res.send('Not Admin');
        } else {
            next();
            res.send('Admin');
        }
    } catch (e) {
        res.statusCode = 401;
        res.send('Token Error ----------');
    }
}

module.exports = {
    authUsers,
    authAdmin,
};