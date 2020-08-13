const handleClick = async function() {
    const urls = [
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/homework/users/src/id.json',
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/homework/users/src/users.json',
    ];

    // Get data from urls and convert to js-object
    let requests = await Promise.all(urls.map(url => fetch(url).then(data => data.json())));

    // Merge 2 objects in one to have full data about user
    const ids = requests[0].investmentsData;
    const users = requests[1].peoplesData;
    let allData = ids.map(element => {
        let id = element.id;
        user = users.find(user => user.id === id);
        return Object.assign(user, element);
    });

    // Render new page by data
    render(allData);
};

const render = function(data) {
    document.getElementById("main").remove();
    let main = document.createElement('main');
    main.id = "main";
    main.className = "col";
    let titleOne = document.createElement('H1');
    titleOne.className = "title";
    titleOne.innerHTML = "ALL USERS FROM OUR SITE";
    let titleTwo = document.createElement('H2');
    titleTwo.className = "titleSmall";
    titleTwo.innerHTML = "Find the person's profile you want to see";
    main.appendChild(titleOne);
    main.appendChild(titleTwo);

    let box = document.createElement('div');
    box.id = "box";
    box.title = "#profile";
    box.className = "box";
    data.forEach(elem => {
        let profile = document.createElement('div');
        profile.className = "profile";
        profile.id = elem.id;
        let image = document.createElement('img');
        image.src = elem.image;
        image.title = "#image";
        image.className = "picture";

        let info = document.createElement('div');
        info.className = "info";

        let name = document.createElement('h3');
        name.className = "name";
        name.innerHTML = elem.name + ' ' + elem.surname;
        info.appendChild(name);

        let id = document.createElement('h6');
        id.className = "text";
        id.innerHTML = 'ID: ' + elem.id;
        info.appendChild(id);

        let age = document.createElement('h6');
        age.className = "text";
        age.innerHTML = 'Age: ' + elem.age;
        info.appendChild(age);

        let job = document.createElement('h6');
        job.className = "text";
        job.innerHTML = 'Job: ' + elem.job;
        info.appendChild(job);

        let investments = document.createElement('h6');
        investments.className = "text";
        investments.innerHTML = 'Investments: ' + elem.investments;
        info.appendChild(investments);

        let button = document.createElement("button");
        button.className = "close";
        button.title = '#remove';
        button.onclick = () => {
            document.getElementById(elem.id).style.display = "none";
        }
        button.innerHTML = "X";

        profile.appendChild(image);
        profile.appendChild(info);
        profile.appendChild(button);
        box.appendChild(profile);
    });
    main.appendChild(box)
    document.body.appendChild(main);
}