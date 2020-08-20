const { Sequelize, DataTypes } = require('sequelize');
//const configs = require('../configs');
const { host_name, db_name, db_user, db_password } = require('../configs');

// const {host_name, db_name, db_user, db_password} = configs;

/* Kap hastatel db het */
const sequelize = new Sequelize(db_name, db_user, db_password, {
    host: host_name,
    dialect: 'mysql' /* te inch tesaki db het e ashxatum */
});

const Users = sequelize.define('users', { /*sxema haytararvum e define fuctioni mijocov */
    id: {                                /* arajin parame-anun, II param - colomi nkaragrutyun */
        type: DataTypes.UUID,           /* tiperi haytararum,anhraj depqum default arjeq */
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
    /*stex karayinq obyekt tayinq, voronq inqe avelacner mer colome sarqelu jmanak*/
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
},{
    /*stex karayinq obyekt tayinq, voronq inqe avelacner mer colome sarqelu jmanak*/
});

/* kapi stexcume keyi mijocov: Usersi mej avelacnum enq cityID 
anunov colom kapi stexcman hamar*/
Users.belongsTo(Cities, {foreignKey: 'cityID'}) 

module.exports = {
    Users: Users,
    Cities: Cities,
//    db: sequelize
}