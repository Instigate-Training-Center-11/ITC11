
let pData = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armenuhi_Kocharyan/jsonFiles/firstfile.json')
  .then((response) => response.text());
let iData = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armenuhi_Kocharyan/jsonFiles/secondfile.json')
  .then((response) => response.text());
promises = Promise.all(([pData, iData]));
promises.then((p) => p.toString()).then(p => console.log(p));
