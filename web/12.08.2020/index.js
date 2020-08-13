let sum = (a,b) => {
    let result = a+b;
    return result;
};

console.log(sum(8,9));

const investmentsData = new Array();
const peoplesData = new Array();

const p1 = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armen_Nersesyan/web/12.08.2020/investmentsData.json')
const p2 = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armen_Nersesyan/web/12.08.2020/peoplesData.json')

p1.catch((Error) => {
    console.log(Error);
})

p2.catch((Error) => {
    console.log(Error);
})

Promise.all([p1,p2]).then(() => {
    p1.then(response => response.json()).then((res1) => {
        for (let key in res1) {
            investmentsData.push((res1[key]));
        }
    });
    p2.then(response => response.json()).then((res2) => {
        for (let key in res2) {
            peoplesData.push((res2[key]));
        }
    });
})


console.log("-----------------",investmentsData);
console.log("-----------------",peoplesData);



