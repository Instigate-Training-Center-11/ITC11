let peoplesJson = require('./peoples');
let investmentsJson = require('./investments.json')
const { Sequelize, DataTypes } = require('sequelize');
let express = require('express');
let app = express();
let configs = require('./configs');

const {host_name, db_name, db_user, db_password} = configs;

const sequelize = new Sequelize(db_name, db_user,db_password, {
    host: host_name,
    dialect: 'mysql'
  });

  const User = sequelize.define('users', {
    id: {
      type: DataTypes.UUID,
      primaryKey: true,
      unique: true,
    },

    name: {
      type: DataTypes.STRING,
      allowNull: false,
    },

    lastName: {
      type: DataTypes.STRING,
      allowNull: false,
    },

    job: {
      type: DataTypes.STRING,
      allowNull: false,
    },

    imageUrl: {
      type: DataTypes.STRING,
      allowNull: false,
    }

  });

const Investments = sequelize.define('investments', {
  id: {
    type: DataTypes.UUID,
    primaryKey: true,
    unique: true,
  },

  investments: {
    type: DataTypes.INTEGER,
    allowNull: false,
  }
});

async function insert() {
  for (let i = 0; i < peoplesJson.peoplesData.length; i++) {
    await User.create({
      id: peoplesJson.peoplesData[i].id,
      name: peoplesJson.peoplesData[i].name,
      lastName: peoplesJson.peoplesData[i].lastName,
      job: peoplesJson.peoplesData[i].job,
      imageUrl: peoplesJson.peoplesData[i].photo,
    });
  }
}

async function investments() {
  for (let i = 0; i < investmentsJson.investmentsData.length; i++) {
    await Investments.create({
      id: investmentsJson.investmentsData[i].id,
      investments: investmentsJson.investmentsData[i].investments,
    });
  }
}

const connect = async() => {
  try {
    await User.sync();
    await Investments.sync();
    await sequelize.authenticate();
    console.log('Connection has been established successfully.');
  } catch (error) {
    console.error('Unable to connect to the database:', error);
  }
}

connect();

// insert();
// investments();

const allInvestments = async (req, res) => {
  const investments = await Investments.findAll();
  if(investments) {
    res.send(investments);
  } else {
    res.statusCode = 404;
    res.send('Not found');
  }
};

const oneInvestments = async (req, res) => {
  const one = await Investments.findByPk(req.params.id);
  if(one) {
    res.send(one);
  } else {
    res.statusCode = 404;
    res.send('Not found');
  }
};

const allUser = async (req, res) => {
  const users = await User.findAll();
  if(users) {
    res.send(users);
  } else {
    res.statusCode = 404;
    res.send('Not found');
  }
};

const oneUser = async (req, res) => {
  const one = await User.findByPk(req.params.id);
  if(one) {
    res.send(one);
  } else {
    res.statusCode = 404;
    res.send('Not found');
  }
};

app.get('/investments', allInvestments);
app.get('/investments/:id', oneInvestments);
app.get('/users', allUser);
app.get('/users/:id', oneUser);

app.listen(3004);