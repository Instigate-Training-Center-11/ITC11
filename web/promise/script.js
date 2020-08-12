// Task 1

let promise1 = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Serzh_Harutyunyan/web/promise/investments.json')
.then(response => response.json());

let promise2 = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Serzh_Harutyunyan/web/promise/peoples.json')
.then(response => response.json());

Promise.all([promise1, promise2])
    .then((res) => {
        console.log(res);
        return res;
    })

// Task 2

    .then((res) => {
        let array = [];
        for (let i in res[0].investmentsData) {
            if (res[0].investmentsData[i].investments > 500) {
                if (res[0].investmentsData[i].id = res[1].peoplesData[i].id) {
                    res[0].investmentsData[i].name = res[1].peoplesData[i].name;
                    res[0].investmentsData[i].age = res[1].peoplesData[i].age;
                    res[0].investmentsData[i].job = res[1].peoplesData[i].job;
                } 

                array.push(res[0].investmentsData[i]);
            }
        }

        console.log(array);
        return array;
    })

// Task 3

    .then((array) => {
        array.sort(function(a, b) {
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

// Task4

Promise.all([promise1, promise2])
    .then((res) => {
        console.log(res);
        return res;
    })

    .then((res) => {
        for (let i in res[0].investmentsData) {
            if (res[0].investmentsData[i].id = res[1].peoplesData[i].id) {
                res[0].investmentsData[i].name = res[1].peoplesData[i].name;
                res[0].investmentsData[i].age = res[1].peoplesData[i].age;
                res[0].investmentsData[i].job = res[1].peoplesData[i].job;
            } 
        }

        let entries = [];
        res[0].investmentsData.forEach(item => {
            let mapItem = [item, item.age];
            entries.push(mapItem);
        });
        weakMap = new WeakMap(entries);
        console.log(weakMap);
    })

    .catch((error) => {
        console.log(error);
    });