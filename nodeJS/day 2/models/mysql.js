const { user } = require('./user');
const { id } = require('./id');
const { sequelize } = require('./connection');
const usersData = require('../src/user.json');
const idsData = require('../src/ids.json');

// Checking connection with database
let connect = async () => {
    try {
        await sequelize.sync({ alter: true });
        let users = usersData.peoplesData;
        let ids = idsData.investmentsData;

        for (let k in ids) {
            let elem = ids[k];
            await id.create({
                id: Number(elem.id),
                investments: Number(elem.investments)
            });
        }

        for (let i in users) {
            let elem = users[i];
            await user.create({
                name: elem.name,
                id: Number(elem.id),
                surname: elem.surname,
                age: Number(elem.age),
                job: elem.job,
                image: elem.image
            });
        }
    } catch (error) {
        console.error('Unable to connect to the MySql:', error);
    }
};

connect();

module.exports = {
    user: user
}