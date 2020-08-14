async function getInputValue(){
    var input = document.getElementById("search").value;
    let elements = document.getElementsByClassName("people");
    while(elements.length > 0){
        elements[0].parentNode.removeChild(elements[0]);
    }
    f(input);
}
let fn = async function(e) {
    e.parentNode.remove();
};
let f = async function(search) {
    let pA = await fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Meruzhan_Unanyan/Web/JS/13_08_2020/people.json');
    let de = await pA.json();
    for (let i = 0; i < de.peoplesData.length; ++i) {
        if ((de.peoplesData[i].name + de.peoplesData[i].lastName).includes(search.trim())) {
            let divElement = document.createElement('div');
            divElement.className = "people";
            divElement.id = de.peoplesData[i].id;
            divElement.innerHTML = "<p><img alt='()' src=" + de.peoplesData[i].imageUrl + "></p><p></p>" + de.peoplesData[i].name + "</p><p>" + de.peoplesData[i].lastName +
                "</p><p>" + de.peoplesData[i].age + "</p><p>" + de.peoplesData[i].job + "</p>" + "<button onclick='fn(this)'>X</button>";
            document.body.append(divElement);
        }
    }
};
f("");
