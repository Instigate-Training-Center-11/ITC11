const {Sequelize,DataTypes} = require('sequelize');
const configs = require('../configs');


const {host_name, db_name, db_user, db_password} = configs;

const sequelize = new Sequelize( db_name, db_user, db_password, {
    host:host_name,
    dialect:'mysql'
});


const Offices = sequelize.define('Offices', {
    id:{
        type:DataTypes.INTEGER,
        primaryKey:true,
        autoIncrement:true
    },
    name:{
        type:DataTypes.STRING,
        allowNull:false
    }
}, {

});

const Users = sequelize.define('Users',{
    id:{
        type:DataTypes.UUID,
        primaryKey:true,
        unique:true
    },
    firstName:{
        type:DataTypes.STRING,
        allowNull:false
    },
    lastName:{
        type:DataTypes.STRING,
        allowNull:false
    },
    job:{
        type:DataTypes.STRING,
        allowNull:false
    },
    imageUrl:{
        type:DataTypes.STRING,
        allowNull:false
    }
}, {

});


const Cities = sequelize.define('Cities', {
    id:{
        type:DataTypes.INTEGER,
        primaryKey:true,
        autoIncrement:true
    },
    name:{
        type:DataTypes.STRING,
        allowNull:false
    },
    isCapital: {
        type: DataTypes.BOOLEAN,
        defaultValue: true,
        allowNull: false
    },
    population: {
        type:DataTypes.INTEGER,
        allowNull:false
    }
}, {

})


Users.belongsTo(Offices,{foreignKey:'officeID'});
Users.belongsTo(Cities,{foreignKey:'cityID'});

module.exports = {
    Users,
    Cities,
    Offices
}