const usersDataJson = require('./users.json');
const users = usersDataJson.users;

const id = Math.round(Math.random() * 8);

const changeStatus = function(users) {
    for(let i = 0; i < users.length; ++i) {
        if(i === id) {
            users[i].isActive = "Active";
            notify(users[i].followers, users, id);
        }
    }
}

const notify = function(followers, users, id) {
    for(let i = 0; i < followers.length; ++i) {
        console.log(`${users[followers[i]].name} status ${users[id].name} has been is changed, current status is: ${users[id].isActive}`)
    }
}

changeStatus(users)