const usersDataJson = require('./users.json');
const users = usersDataJson.users;

const id = Math.round(Math.random() * 8);

const changeStatus = function(users) {
    for(let i = 0; i < users.length; ++i) {
        if(i === id) {
            users[i].isActive = !users[i].isActive;
            notify(users[i].followers, users, id);
        }
    }
}

const notify = function(followers, users, id) {
    for(let i = 0; i < followers.length; ++i) {
        if(users[id].isActive) {
            console.log(`${users[followers[i]].name} status ${users[id].name} has been is changed, current status is: Active`)
        } else {
            console.log(`${users[followers[i]].name} status ${users[id].name} has been is changed, current status is: Not Active`)
        }
    }
}

changeStatus(users);