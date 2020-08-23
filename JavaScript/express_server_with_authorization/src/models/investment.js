module.exports = (sequelize, DataTypes) => {
  const Investment = sequelize.define("Investments", {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      unique: true,
      autoIncrement: true,
    },
    price: {
      type: DataTypes.INTEGER,
      allowNull: false,
    },
  });
  return Investment;
};
