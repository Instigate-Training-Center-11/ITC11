const { DataTypes } = require("sequelize");

module.exports = (sequelize) => {
    const Cities = sequelize.define("Cities", {
        id: {
            type: DataTypes.INTEGER,
            primaryKey: true,
            autoIncrement: true
        },
        name: {
            type: DataTypes.STRING,
            allowNull: false
        }
    });

    return Cities;
  };