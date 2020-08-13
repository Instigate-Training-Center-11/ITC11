//Json 

let pData = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armenuhi_Kocharyan/Web/JavaScript/jsonFiles/firstfile.json')
    .then(response => response.json());
let iData = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armenuhi_Kocharyan/Web/JavaScript/jsonFiles/secondfile.json')
    .then(response => response.json());
let promise = Promise.all([pData, iData]).then((data) => {
        console.log(data);
        return data;
    }).then((data) => {    
        let array = [];
        for (let i in data[0].invData) {
            if (data[0].invData[i].investments > 500) {
                if (data[0].invData[i].id = data[1].peopData[i].id) {
                    data[0].invData[i].name = data[1].peopData[i].name;
                    data[0].invData[i].age = data[1].peopData[i].age;
                    data[0].invData[i].job = data[1].peopData[i].job;
                }
                array.push(data[0].invData[i]);
            }
        }
        console.log(array);
        return array;
    }).then((array) => {
        array.sort(function (a, b) {
            return b.investments - a.investments;
        });
        let newArray = [];
        for (let i = 0; i < 3; ++i) {
            newArray[i] = array[i];
        }
        console.log(newArray);
        return newArray;
    })
    .catch((error) => {
        console.log(error);
    });


   