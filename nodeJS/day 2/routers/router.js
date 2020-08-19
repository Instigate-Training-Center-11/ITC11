const express = require('express');
const userController = require('../controllers/user.controller');
const idsController = require('../controllers/ids.controller');
const router = express.Router();

// User routing
router.route('/users/:id')
    .get(userController.getUserByID);
router.route('/users')
    .get(userController.getUsers);

// Investment routing
router.route('/investments/:id')
    .get(idsController.getInvestmentsByID);
router.route('/investments')
    .get(idsController.getInvestments);

router.route('/*')
    .all(userController.wrongURL);

module.exports = router;