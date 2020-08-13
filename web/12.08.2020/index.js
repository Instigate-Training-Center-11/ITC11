function  concatData(arrayFilterInvestments,arrayPeoplesData) {
  let resultConcat = new Array();
  arrayFilterInvestments.forEach(element => {
    arrayPeoplesData.forEach(item => {
      if(element.id === item.id) {
        const {investments} = element;
        let result = {
          ...item,
          investments
        }
        resultConcat.push(result);
      }
    });
  });
  return resultConcat;
}


function bindAllData(arrayInvestmentsData,arrayPeoplesData) {
  let resultBind = new Array();
  arrayInvestmentsData.forEach(element => {
    arrayPeoplesData.forEach(item => {
      if(element.id === item.id) {
        const {investments} = element;
        let result = {
          ...item,
          investments
        }
        resultBind.push(result);
      }
    });
  });
  return resultBind;
}


function topThreeInvestments(arrayInvestmentsData,arrayPeoplesData) {
  let data = bindAllData(arrayInvestmentsData,arrayPeoplesData);
    data.sort(function(a, b) {
        var x = a["investments"]; var y = b["investments"];
        return ((x > y) ? -1 : ((x < y) ? 1 : 0));
    });

    if (data.length <= 3) {
      return data;
    }
    let top = new Array();
    for (let i = 0; i < 3; ++i) {
      top.push(data[i]);
    }
    return top;
}


const p1 = fetch(
  "https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armen_Nersesyan/web/12.08.2020/investmentsData.json"
).then(response => response.json())

const p2 = fetch(
  "https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armen_Nersesyan/web/12.08.2020/peoplesData.json"
).then(response => response.json())


Promise.all([p1, p2]).then((data) => {
  let arrayInvestmentsData = data[0].investmentsData;
  let arrayPeoplesData = data[1].peoplesData;
  console.log(arrayInvestmentsData);
  console.log(arrayPeoplesData);

  arrayFilterInvestments = arrayInvestmentsData.filter(element => element.investments >= 500).map(element => element);
  console.log(arrayFilterInvestments);

  console.log(concatData(arrayFilterInvestments,arrayPeoplesData));

  console.log(bindAllData(arrayInvestmentsData,arrayPeoplesData));

  console.log(topThreeInvestments(arrayInvestmentsData,arrayPeoplesData));
})
.catch((Error) => {
  console.log(Error);
});

