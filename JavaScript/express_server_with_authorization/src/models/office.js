module.exports = (sequelize, DataTypes) => {
  const Offic = sequelize.define("Offices", {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      autoIncrement: true,
    },
    name: {
      type: DataTypes.STRING,
      allowNull: false,
    },
  });
  return Offic;
};
