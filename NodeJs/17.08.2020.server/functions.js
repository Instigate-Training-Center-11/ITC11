const bindAllData = (arrayInvestmentsData, arrayPeoplesData) => arrayPeoplesData.map(item => {
    item.investments = arrayInvestmentsData.find(elem => elem.id === item.id).investments;
    return item;
  });



  module.exports = bindAllData;