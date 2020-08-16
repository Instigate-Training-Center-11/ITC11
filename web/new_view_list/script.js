let url1 = 'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Serzh_Harutyunyan/web/promise/investments.json';
let url2 = 'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Anna_Harutyunyan/web/styles/async_await_dom/users.json';

let p1 = fetch(url1).then(res =>res.json());
let p2 = fetch(url2).then(res =>res.json());

async function link() { 
    try {   
        let results = await Promise.all([p1, p2]);

        let peoples = results[1].peoplesData;
        let inv = results[0].investmentsData;
        myFunction();

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
        
    } catch(error) {
        console.log('My error', error);
    }
}

function myFunction() {
    let label = document.createElement('label');
    label.setAttribute('class', 'my-label');
    label.textContent = 'Find person';
    document.getElementById('list').appendChild(label);

    let input = document.createElement('input');
    input.setAttribute('class', 'my-input');
    document.getElementById('list').appendChild(input);
    input.placeholder = 'Find person';

    let btn = document.createElement('button');
    btn.setAttribute('class', 'my-button');
    btn.textContent = 'Find';
    document.getElementById('list').appendChild(btn);  

    btn.onclick = function() {
        input = document.getElementsByClassName("my-input")[0];
        let filter = input.value.toUpperCase();
        let list = document.getElementById("list");

        let person = document.getElementsByClassName('person')
        let div0 = list.getElementsByClassName('div0');
        for (let i = 0; i < person.length; i++) {
    
            let h2 = div0[i].getElementsByTagName("h2")[0];
            let txtValue = h2.textContent || h2.innerText;
            if (txtValue.toUpperCase().indexOf(filter) != -1) {
                person[i].style.display = "";
            } else {
                person[i].style.display = 'none';
            }
        }
    }
}