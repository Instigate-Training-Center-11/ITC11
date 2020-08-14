let dataUrl1 = 'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Artashes_Sargsyan/Web/JS/json/investments_data.json'
let dataUrl2 = 'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Artashes_Sargsyan/Web/JS/json/users_data.json'

function joinData(first, second) {
    let allData = new Array()
    for(let i = 0; i < second.peoplesData.length; ++i) {
        allData.push(second.peoplesData[i]);
        allData[i].investments = first.investmentsData[i].investments;
    }
    return allData;
}

function renderData(data) {
    let count = 1;
    for(let key of Object.keys(data[0])) {
        newTableHead = document.createElement("th");
        newTableHead.setAttribute("data-column", `column${count}`);
        newTableHead.className = `column100 column${count}`;
        newTableHead.innerHTML = key;
        document.getElementById("tableHead").appendChild(newTableHead);
        ++count;
    }

    for (let i = 0; i < data.length; ++i) {
        let newElement = new Array();
        newRow = document.createElement("tr");
        newRow.setAttribute("id", `rowId${i + 1}`);
        newRow.className = "row100";
        document.getElementById("tBoady").appendChild(newRow);

        let count = 0;
        for(let value of Object.values(data[i])) {
            newElement[count] = document.createElement("td");
            newElement[count].className = `column100 column${count + 1}`;
            newElement[count].setAttribute("data-column", `column${count + 1}`);
            newElement[count].innerHTML = value;
            document.getElementById(`rowId${i + 1}`).appendChild(newElement[count]);
            ++count;
        }
    }
}

async function getData(dataUrl1, dataUrl2) {
    try {
        let Invest = await fetch(dataUrl1);
        let People = await fetch(dataUrl2);
        let dataInvest = await Invest.json();
        let dataPeople = await People.json();
        renderData(joinData(dataInvest, dataPeople));
        return Promise.resolve('Success...')
    } catch {
        return Promise.reject('No connection or wrong url!')
    }
}

getData(dataUrl1, dataUrl2)
.then((data) => {
    console.log(data)
})
.catch(err => err)