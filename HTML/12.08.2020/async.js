let getData1 = async function() {
    let res1 = await fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armine_Gevorgyan/HTML/12.08.2020/file1.json');
    let data = await res1.json();
    return data;
}

let getData2 = async function() {
    let res1 = await fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armine_Gevorgyan/HTML/12.08.2020/file2.json');
    let data = await res1.json();
    return data;
}

Promise.all([getData1(), getData2()]).then(values => {
    addElements('main', [values[0].investmentsData, values[1].peoplesData])
})

function addElements(id, data) {
    for(let i = 0; i < data[0].length; ++i) {
        for(let j = 0; j < data[1].length; ++j) {
            if(data[0][i].id == data[1][j].id) {
                createData(data, i, j);
            }
        }
    }
}

function createData(data, i, j) {
    let content = document.createElement('DIV');
    content.id = 'content_' + i + 1;
    let imageDiv = document.createElement('DIV');
    let infoDiv = document.createElement('DIV');
    infoDiv.className = 'info';
    let img = document.createElement('IMG');
    let info = document.createElement('DIV');
    let info_1 = document.createElement('DIV');
    let info_2 = document.createElement('DIV');
    let rBin = document.createElement('IMG');
    let name = document.createElement('H2');
    let lname = document.createElement('H2');
    let age = document.createElement('H3');
    let job = document.createElement('H3');
    let investments = document.createElement('H3');
    let investmentsData = document.createElement('H3');

    name.innerText = data[1][j].name;
    lname.innerText = data[1][j].lname;
    age.innerText = data[1][j].age;
    job.innerText = data[1][j].job;
    investments.innerText = 'Investments: ';
    investmentsData.innerText = data[0][i].investments;
    rBin.className = 'rBin';
    rBin.src = './rBin.png';
    rBin.addEventListener('click', function(){
        content.style.display = 'none';
    })
    img.src = data[1][j].img;

    document.getElementById('main').appendChild(content);
    content.appendChild(imageDiv);
    content.appendChild(infoDiv);
    imageDiv.appendChild(img);
    info.appendChild(name);
    info.appendChild(lname);
    info.appendChild(rBin);
    info_1.appendChild(age);
    info_1.appendChild(job);
    info_2.appendChild(investments);
    info_2.appendChild(investmentsData);
    infoDiv.appendChild(info);
    infoDiv.appendChild(info_1);
    infoDiv.appendChild(info_2);
}