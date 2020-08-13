const tasks = {};


// 1. Need to get all data using "Promises.all" function.
// ... You can use fetch for example
tasks.taskOne = function() {
    const urls = [
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/homework/id.json',
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/homework/users.json',
    ];

    // Recreate every URL to promise, returned fetch
    let requests = urls.map(url => fetch(url), {
        credentials: 'same-origin'
    });

    // Promise.all will wait for done all promises
    Promise.all(requests)
    .then(responses => responses.forEach(response => console.log(response.json())))
    .catch(error => alert("Something went wrong in 1st function!"));

};


// 2. Get rows from investment data in which investments are not less then 500
// and then get the that people's info from people's data and combine.
tasks.taskTwo = function() {
    const url = 'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/homework/id.json';

    // Recreate every URL to promise, returned fetch, parse from json to js object
    let requests = urls.map(url => fetch(url).then(data => data.json()));

    Promise.all(requests)
    .then(data => {
        ids = data[0].investmentsData;
        users = data[1].peoplesData;
        let filtered = ids.filter(element => element.investments >= 500);
        const allData = filtered.map(element => {
            let id = element.id;
            user = users.find(user => user.id === id);
            return Object.assign(user, element);
        });
        console.log(allData);
    })
    .catch((err) => {
        alert("Something went wrong in 2nd function!");
        console.log(err.status);
    });
};