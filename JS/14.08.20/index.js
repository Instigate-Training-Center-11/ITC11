const start_click = async function() {
    const urls = [
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Zhora-Begloyan/web/jsPromises/investments.json',
        'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Zhora-Begloyan/web/jsPromises/people.json',
    ];
    let requests = await Promise.all(urls.map(url => fetch(url).then(data => data.json())));
    const ids = requests[0].investmentsData;
    const users = requests[1].peoplesData;
    let all_data = ids.map(element => {
        let id = element.id;
        user = users.find(user => user.id === id);
        return Object.assign(user, element);
    });
    print(all_data);
};

const print = function(data) {

    let ele = document.getElementById("main");
    ele.parentElement.removeChild(ele);
    let main = document.createElement('main');
    main.className = "user_list";
    let list = document.createElement('div');
    list.className = "list";
    data.forEach(elem => {
        let elements = document.createElement('div');
        elements.className = "elements";
        elements.id = elem.id;
        let url = document.createElement('img');
        url.src = elem.url;
        url.className = "picture";
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
        
        let button1 = document.createElement("button");
        button1.className = "close";
        button1.onclick = () => {
            document.getElementById(elem.id).style.display = "none";
        }
        elements.appendChild(url);
        elements.appendChild(info);
        elements.appendChild(button1);
        list.appendChild(elements);
    });
    let button2 = document.createElement("button");
    button2.innerHTML = "All users";
    button2.className = "start";
    button2.onclick = () => {
        main.id = "main"
        print(data);
    }
    main.appendChild(button2)
    main.appendChild(list)
    document.body.appendChild(main);
}