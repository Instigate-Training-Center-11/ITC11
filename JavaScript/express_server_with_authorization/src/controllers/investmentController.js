var models = require("../models");

const { Investment, User } = models;

const getInvestments = async (req, res) => {
  const investments = await Investment.findAll({
    include: [{ model: User, foreignKey: "investmentId" }],
  });
  if (investments.length) {
    res.send(investments);
  }
  res.statusCode = 404;
  res.send("Not found");
};

const getInvestment = async (req, res) => {
  const { id } = req.params;
  const investment = await Investment.findOne({
    where: { id },
    include: [{ model: User, as: "User", foreignKey: "userId" }],
  });

  if (investment) {
    res.send(investment);
  }
  res.statusCode = 404;
  res.send("Not found");
};

module.exports = {
  getInvestments,
  getInvestment,
};
