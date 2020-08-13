function getRandomColor() {
    let letters = '0123456789ABCDEF';
    let color = '#';
    for (let i = 0; i < 6; ++i) {
      color += letters[Math.floor(Math.random() * 16)];
    }
    
    return color;
  }

let getData = async function() {
    let res1 = await fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Armine_Gevorgyan/HTML/12.08.2020/file1.json');
    let data = await res1.json()
    for(let i = 0; i < data.investmentsData.length; ++i) {
        let node = document.createElement("DIV");
        node.style.height = data.investmentsData[i].investments + '%';
        node.style.width = '25px';
        node.style.backgroundColor = getRandomColor();
        node.style.marginRight = '25px';
        node.style.border = '1px solid black';
        document.getElementById("main").appendChild(node);
    }
}

getData();