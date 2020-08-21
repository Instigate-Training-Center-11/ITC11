const { Sequelize, DataTypes } = require('sequelize');
//const configs = require('../configs');
const { host_name, db_name, db_user, db_password } = require('../configs');

/* to connect to database */
const sequelize = new Sequelize(db_name, db_user, db_password, {
    host: host_name,
    dialect: 'mysql' /* whisch kind database will we use */
});

const Users = sequelize.define('users', { /* to create table with function define */
    id: {                                /* the first param is the name of param, second is the type */
        type: DataTypes.UUID,           /* sometimes we need to declare defaultvalue */
        defaultValue: DataTypes.UUIDV4,
        primaryKey: true,
        unique: true,
    },
    name: {
        type: DataTypes.STRING,
        allowNull: false
    },
    job: {
        type: DataTypes.STRING,
        allowNull: false,
    },
    imageUrl: {
        type: DataTypes.STRING,
        allowNull: false
    },
    password: {
        type: DataTypes.STRING,
        allowNull: false,
        defaultValue: false
    },
    isAdmin: {
        type: DataTypes.BOOLEAN,
        allowNull: false,
        defaultValue: false
    }

}, {
    /* we can give the object to addition into our table */
});
const Cities = sequelize.define('cities', {
    id: {
        type: DataTypes.INTEGER,
        primaryKey: true,
        autoIncrement: true,
    },
    name: {
        type: DataTypes.STRING,
        allowNull: false
    }
}, {
    /* we can give the object to addition into our table */
});
/* to connect two tables with a key: we are adding an colom into the user table with name cityID */
Users.belongsTo(Cities, { foreignKey: 'cityID' })
module.exports = {
    Users: Users,
    Cities: Cities,
    //    db: sequelize
}