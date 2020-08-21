let jwt = require('jwt-simple');

const authUser = (req, res, next) => {
    const token = req.headers.auth;
    if (!token) {
        res.status(401);
        res.send('Unauthorized');
    }

    try {
        next();
    } catch (e) {
        res.status(403);
        res.send('Forbidden');
    }
}

const authAdmin = (req, res, next) => {
    const token = req.headers.auth;
    if (!token) {
        res.status(401);
        res.send('Unauthorized');
    }

    try {
        const decode = jwt.decode(token, process.env.SECRETKEY);
        if(!decode.isAdmin) {
            res.status(403);
            res.send('Forbidden');
        } else {
            next();
            res.send('I am Admin');
        }
    } catch (e) {
        res.status(403);
        res.send('Forbidden');
    }
}


module.exports = {
    authUser,
    authAdmin
}

// Admin
// eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpZCI6IjVhNGExZDY2LWVlMDAtNDZiMy1iNDFiLThjNDViOTJkZTJmNyIsImlzQWRtaW4iOnRydWV9.yynW6UTYMhHorjB7SdBDYl_Z7GVzcRzJwyaM1pgn4iM

// User
// eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpZCI6ImZkYjJmOTQxLTU2ZWUtNDgxNy05YjVkLWRjMjg2MGRkZjRhNCIsImlzQWRtaW4iOmZhbHNlfQ.w-Ycj-Punxo6aDKJv7b_EmGEmh85nVsdDYiiCzFoFG4