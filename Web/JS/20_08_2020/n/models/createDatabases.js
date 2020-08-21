const { Sequelize, DataTypes } = require('sequelize');
const sequelize = new Sequelize('itc11', 'root', 'arsen98ak', {
    host: 'localhost',
    dialect: 'mysql'
});

const Offices = sequelize.define('Offices', {
    id: {
        type: DataTypes.INTEGER,
        primaryKey: true,
        autoIncrement: true
    },
    name: {
        type: DataTypes.STRING,
        allowNull: false
    }
}, {

})

const Users = sequelize.define('Users', {
    id: {
        type: DataTypes.INTEGER,
        autoIncrement: true,
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
    email: {
        type: DataTypes.STRING,
        //unique: true,
        allowNull: false
    },
    isAdmin: {
        type: DataTypes.BOOLEAN,
        allowNull: false
    },
    password: {
        type: DataTypes.STRING,
        //unique: true,
        allowNull: false
    },
    /*cityID - int, foreign key (should be referred on id column of the Cities )
oficeID - int, foreign key (should be referred on id column of the Ofice )*/
}, {
})


const Cities = sequelize.define('Cities', {
    id: {
        type: DataTypes.INTEGER,
        primaryKey: true,
        autoIncrement: true
    },
    name: {
        type: DataTypes.STRING,
        allowNull: false
    },
    isCapital: {
        type: DataTypes.BOOLEAN,
        allowNull: false
    },
    population: {
        type: DataTypes.INTEGER,
        allowNull: false
    }
}, {
});


module.exports={
    Offices: Offices,
    Users: Users,
    Cities: Cities
}