module.exports = (sequelize, DataTypes) => {
  const City = sequelize.define("Cities", {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      autoIncrement: true,
    },
    name: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    isCapital: {
      type: DataTypes.BOOLEAN,
      allowNull: false,
    },
    population: {
      type: DataTypes.INTEGER,
      allowNull: false,
    },
  });
  return City;
};
