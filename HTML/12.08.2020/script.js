let a = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armine_Gevorgyan/HTML/12.08.2020/file1.json')
.then((res) => {
    return res.json()
})
let b = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armine_Gevorgyan/HTML/12.08.2020/file2.json')
.then((res) => {
    return res.json();
})

Promise.all([a, b]).then(values => {
    //============================= 1 ======================================
    console.log([...values[0].investmentsData, ...values[1].peoplesData]);

    //============================= 2 ======================================
    let arr = []
    for(let i = 0; i < values[0].investmentsData.length; ++i) {
        if(values[0].investmentsData[i].investments >= 500) {
            if(values[1].peoplesData[i].id === values[0].investmentsData[i].id) {
                arr.push([{id: values[1].peoplesData[i].id, name:  values[1].peoplesData[i].name,
                    age: values[1].peoplesData[i].age, job: values[1].peoplesData[i].job,
                    investments: values[0].investmentsData[i].investments
                }]);
            }
        }
    }

    //============================= 3 ======================================
    let arr1 = [];
    arr1[0] = values[0].investmentsData[0].investments;
    arr1[1] = values[0].investmentsData[1].investments;
    arr1[2] = values[0].investmentsData[2].investments;
    for(let i = 2; i < values[0].investmentsData.length; ++i) {
        for(let j = 0; j < arr1.length; ++j) {
            if(arr1[j] < values[0].investmentsData[i].investments) {
                arr1[j] = values[0].investmentsData[i].investments;
                break;
            }
        }
    }

    //============================= 4 ======================================
    let arr2 = []
    for(let i = 0; i < values[0].investmentsData.length; ++i) {
        arr2.push([{
            id: values[1].peoplesData[i].id, investments: values[0].investmentsData[i].investments,
            name:  values[1].peoplesData[i].name, age: values[1].peoplesData[i].age,
            job: values[1].peoplesData[i].job,
        }]);
    }

});