const userController = require("./userController");
const cityController = require("./cityController");
const officeController = require("./officeController");
const investmentController = require("./investmentController");

module.exports = {
  ...userController,
  ...cityController,
  ...officeController,
  ...investmentController,
};
