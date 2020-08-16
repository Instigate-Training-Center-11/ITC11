var urls = [
    `https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Anna_Harutyunyan/web/styles/Promise/investments.json`,
    `https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Anna_Harutyunyan/web/styles/async_await_dom/users.json`
];

var data1 = fetch(urls[0]).then(res => res.json());
var data2 = fetch(urls[1]).then(res => res.json());

async function getUsers() {
    try {
        var res = await Promise.all([
            data1, data2
        ]);

        searchUsers();

        for (let i in res[0].investmentsData) {
            res[0].investmentsData[i].name = res[1].peoplesData[i].name;
            res[0].investmentsData[i].lastName = res[1].peoplesData[i].lastName;
            res[0].investmentsData[i].age = res[1].peoplesData[i].age;
            res[0].investmentsData[i].job = res[1].peoplesData[i].job;
            res[0].investmentsData[i].photo = res[1].peoplesData[i].photo;
        }
    } catch (e) {
        console.log(e);
    }
    createHtml(res[0].investmentsData);
}

function searchUsers() {
    let inp = document.createElement(`input`);
    inp.type = `text`;
    inp.placeholder = `Enter the name`;
    inp.setAttribute(`id`, `filter`);
    document.getElementById(`root`).appendChild(inp);

    inp.onkeyup = function() {
        let input;
        let filter;
        let cards;
        let cardContainer;
        let name;

        input = document.getElementById(`filter`);
        filter = input.value.toUpperCase();
        cardContainer = document.getElementById(`root`);
        cards = cardContainer.getElementsByClassName(`container`);

        for (let i = 0; i < cards.length; ++i) {
            name = cards[i].querySelector(`.container .content h1.name`);
            if (name.innerText.toUpperCase().indexOf(filter) > -1) {
                cards[i].style.display = ``;
            } else {
                cards[i].style.display = `none`;
            }
        }
    }
}

function createHtml(data) {
    for (let i in data) {
        let el = document.createElement(`div`);
        el.setAttribute(`id`, `divs${i}`);
        el.setAttribute(`class`, `container`);

        let img = document.createElement(`img`);
        img.src = data[i].photo;

        let btnContainer = document.createElement(`div`);
        btnContainer.setAttribute(`id`, `btnCon${i}`);

        let btn = document.createElement(`btn`);
        btn.setAttribute(`id`, `btn`);
        btn.textContent = `X`;

        btn.addEventListener(`click`, function() {
            let elem = document.getElementById(`divs${i}`);
            elem.parentNode.removeChild(elem);
            return false;                                                                       
        });

        let div = document.createElement(`div`);
        div.setAttribute(`id`, `con${i}`);
        div.setAttribute(`class`, `content`);
            
        let h1 = document.createElement(`h1`);
        h1.setAttribute(`class`, `name`);
        h1.textContent = `${data[i].name} ${data[i].lastName}`;

        let h2 = document.createElement(`h2`);
        h2.setAttribute(`class`, `age-job`);
        h2.textContent = `age - ${data[i].age}, ${data[i].job},
        Investments - (${data[i].investments})`;

        document.getElementById(`root`).appendChild(el);
        document.getElementById(`divs${i}`).appendChild(img);
        document.getElementById(`divs${i}`).appendChild(div);
        document.getElementById(`con${i}`).appendChild(h1);
        document.getElementById(`con${i}`).appendChild(h2);           
        document.getElementById(`con${i}`).appendChild(btnContainer);
        document.getElementById(`btnCon${i}`).appendChild(btn);
    }
}