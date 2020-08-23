const jwt = require("jwt-simple");
const config = require("../configs");

const auth = (req, res, next) => {
  const { authorization } = req.headers;
  if (!authorization) {
    res.statusCode = 401;
    res.send("Unauthorized");
  } else {
    const token = authorization.slice(7);
    if (!token) {
      res.statusCode = 401;
      res.send("Unauthorized");
    }
    try {
      const decode = jwt.decode(token, config.secret);
      next();
    } catch (error) {
      res.statusCode = 401;
      res.send("Invalid token");
    }
  }
};

const isAdmin = (req, res, next) => {
  const { authorization } = req.headers;
  if (!authorization) {
    res.statusCode = 401;
    res.send("Unauthorized");
  } else {
    const token = authorization.slice(7);
    if (!token) {
      res.statusCode = 401;
      res.send("Unauthorized");
    }
    try {
      const decode = jwt.decode(token, config.secret);
      if (decode.isAdmin) {
        next();
      } else {
        res.statusCode = 403;
        res.send("Forbidden");
      }
    } catch (error) {
      res.statusCode = 401;
      res.send("Invalid token");
    }
  }
};

module.exports = {
  auth,
  isAdmin,
};
