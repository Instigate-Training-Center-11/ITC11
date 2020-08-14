var urls = [
    'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Anna_Harutyunyan/web/styles/Promise/investments.json',
    'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Anna_Harutyunyan/web/styles/async_await_dom/users.json'
];

async function users() {
    try {  
        var res1 = await fetch(urls[0])
        var data1 = await res1.json(); 

        var res2 = await fetch(urls[1])
        var data2 = await res2.json(); 

        var res = await Promise.all([
            data1, data2
        ])

        for (let i in res[0].investmentsData) {
            res[0].investmentsData[i].name = res[1].peoplesData[i].name;
            res[0].investmentsData[i].lastName = res[1].peoplesData[i].lastName;
            res[0].investmentsData[i].age = res[1].peoplesData[i].age;
            res[0].investmentsData[i].job = res[1].peoplesData[i].job;
            res[0].investmentsData[i].photo = res[1].peoplesData[i].photo;

            let el = document.createElement('div');
            el.setAttribute('id', `divs${i}`);
            el.setAttribute('class', 'container');

            let img = document.createElement('img');
            img.src = res[0].investmentsData[i].photo;

            let btn = document.createElement('btn');
            btn.setAttribute('id', 'btn');
            btn.textContent = 'X';

            btn.addEventListener('click', function() {
                let elem = document.getElementById(`divs${i}`);
                elem.parentNode.removeChild(elem);
                return false;                                                                       
            });

            let div = document.createElement('div');
            div.setAttribute(`id`, `con${i}`);
            div.setAttribute(`class`, `content`);
                
            let h1 = document.createElement('h1');
            h1.setAttribute('class', 'name');
            h1.textContent = `${res[0].investmentsData[i].name} 
            ${res[0].investmentsData[i].lastName} 
            Investments - (${res[0].investmentsData[i].investments})`;

            let h2 = document.createElement('h2');
            h2.setAttribute('class', 'age-job');
            h2.textContent = `age - ${res[0].investmentsData[i].age}, ${res[0].investmentsData[i].job}`

            document.getElementById('root').appendChild(el);
            document.getElementById(`divs${i}`).appendChild(img);
            document.getElementById(`divs${i}`).appendChild(div);
            document.getElementById(`con${i}`).appendChild(h1);
            document.getElementById(`con${i}`).appendChild(h2);
            document.getElementById(`con${i}`).appendChild(btn);
        }
        console.log('hi', res[0]);
        } catch (e) {
        console.log(e);
    }
}