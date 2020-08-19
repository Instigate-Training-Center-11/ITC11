const { DataTypes } = require('sequelize');
const { sequelize } = require('./connection');

const user = sequelize.define('users', {
    id: {
        type: DataTypes.INTEGER,
        allowNull: false,
        primaryKey: true
    },
    name: {
        type: DataTypes.STRING,
        allowNull: false
    },
    surname: {
        type: DataTypes.STRING,
        allowNull: false
    },
    age: {
        type: DataTypes.INTEGER,
        allowNull: false
    },
    job: {
        type: DataTypes.STRING
    },
    image: {
        type: DataTypes.STRING
    }
  }, {
});
const id = sequelize.define('ids', {
    id: {
        type: DataTypes.INTEGER,
        allowNull: false,
        primaryKey: true
    },
    investments: {
        type: DataTypes.INTEGER,
        allowNull: false
    }
  }, {
});

module.exports = {
    id : id
};

module.exports = {
    user : user
};