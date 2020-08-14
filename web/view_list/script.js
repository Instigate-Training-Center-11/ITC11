let url1 = 'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Serzh_Harutyunyan/web/promise/investments.json';
let url2 = 'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Anna_Harutyunyan/web/styles/async_await_dom/users.json';
let resalt = null
;
async function link() { 
    try {
        let page1 = await fetch(url1);
        let data1 = await page1.json();
        let page2 = await fetch(url2);
        let data2 = await page2.json();
        let results = await Promise.all([data1, data2]);

        let peoples = results[1].peoplesData;
        let inv = results[0].investmentsData;

        for (let i in peoples) {
            peoples[i].investments = inv[i].investments;
            
            let el = document.createElement('div');
            el.setAttribute('id', `person${i}`);
            el.setAttribute('class', `person`);

            let img = document.createElement('img');
            img.setAttribute('id', 'img')
            img.setAttribute('class', 'img');
            img.src = peoples[i].photo;

            let div = document.createElement('div');
            div.setAttribute('class', 'div0');

            let h2 = document.createElement('h2');
            h2.textContent = `${peoples[i].name}` + ' ' + `${peoples[i].lastName}`;

            let p = document.createElement('p');
            p.textContent = 'Age: ' + `${peoples[i].age} ` + ' Investments: ' + ` ${peoples[i].investments}`;
            
            let div1 = document.createElement('div');
            div1.setAttribute('class', 'div1');

            let btn = document.createElement('button');
            btn.textContent = 'X';
            btn.addEventListener('click', () => {
                let el = document.getElementById(`person${i}`);
                el.parentNode.removeChild(el);
                return false;                                                                       
            });

            document.getElementById('list').appendChild(el);
            el.appendChild(img);
            el.appendChild(div);
            div.appendChild(h2);
            div.appendChild(p);
            el.appendChild(div1);
            div1.appendChild(btn);
        }

        console.log(peoples);

    } catch(error) {
        console.log('My error', error);
    }
}