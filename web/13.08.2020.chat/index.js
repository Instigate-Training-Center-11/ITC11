
const urlPeoplesData = 'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armen_Nersesyan/web/12.08.2020/peoplesData.json';
const urlInvestmentsData = 'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armen_Nersesyan/web/12.08.2020/investmentsData.json';


const bindAllData = (arrayInvestmentsData, arrayPeoplesData) => arrayPeoplesData.map(item => {
  item.investments = arrayInvestmentsData.find(elem => elem.id === item.id).investments;
  return item;
});


function deleteElement(content){
  content.parentElement.style = 'display: none';
}
function searchPeoples() {
  alert("hello");
}
function createUsers(dataUsers){
  dataUsers.forEach(element => {
    let chat = document.getElementById("chat");
    let div = document.createElement('div');
    let divDate = document.createElement('div');
    div.style = 'border-top: 1px solid #636363;padding: 20px; display: flex; flex-direction: row; justify-content: space-between';
    div.innerHTML = `<img  src="${element.img}" alt="" class="round" width="150" height="150">`;
    divDate.innerHTML += '<b> name</b> : ' + element.name;
    divDate.innerHTML += '<b> <br> surname : </b>' + element.surname + '<br>';
    divDate.innerHTML += '<b> <br> age : </b>' + element.age + ' year';
    divDate.innerHTML += '<b> <br> investments : </b>' + element.investments;
    divDate.innerHTML += '<b> <br> job : </b>' + element.job;
    div.appendChild(divDate);
    div.innerHTML += '<button class="buttonC" type="button" onclick="deleteElement(this)" width: 5px;">X</button>';
    chat.appendChild(div);
  });
  console.log(dataUsers);
}

async function jsonDataPeoples() {
    try {
        const response = await fetch(urlPeoplesData);
        const dataPeoples = await response.json();
        return dataPeoples;
    } catch (err) {
        alert(err);
    }
}


async function jsonDataInvestments() {
    try {
        const response = await fetch(urlInvestmentsData);
        const dataInvestments = await response.json();
        return dataInvestments;
    } catch (err) {
        alert(err);
    }
}


Promise.all([jsonDataInvestments(), jsonDataPeoples()]).then(data => {
    console.log(data);

    let arrayInvestmentsData = data[0].investmentsData;
    let arrayPeoplesData = data[1].peoplesData;
    arrayFilterInvestments = arrayInvestmentsData.filter(element => element.investments >= 500);
    dataUsers = bindAllData(arrayInvestmentsData,arrayPeoplesData);
    console.log(bindAllData(arrayInvestmentsData,arrayPeoplesData));
    createUsers(dataUsers);

});
