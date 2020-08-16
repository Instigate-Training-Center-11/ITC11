const peoplesData = [
    { "id": "49e9e1db-161c-4988-b3ab-e1779286b65f", "name": "Armen", "lastName": "Vardanyan", "age": 32, "job": "bugalter", "imageUrl": "./image/team-1.jpg" },
    { "id": "7a43da8c-0f54-4105-a869-692790024d71", "name": "Artak", "lastName": "Hakobyan", "age": 28, "job": "developer", "imageUrl": "./image/team-3.jpg" },
    { "id": "18eecfd2-2f9f-4675-bed3-8192094fe968", "name": "Karen", "lastName": "Arshakyan", "age": 26, "job": "developer", "imageUrl": "./image/team-1.jpg" },
    { "id": "383c0b79-0b62-416d-aec3-8e904f1c77cc", "name": "Ashot", "lastName": "Hunanyan", "age": 45, "job": "teacher", "imageUrl": "./image/team-3.jpg" },
    { "id": "12340853-4c1c-4c68-bdfa-c46c9a21b752", "name": "Nelli", "lastName": "Hakobyan", "age": 21, "job": "teacher", "imageUrl": "./image/team-2.jpg" },
    { "id": "bcc35ab6-3759-4c29-803a-07189763ec12", "name": "Hakob", "lastName": "Vardanyan", "age": 16, "job": "", "imageUrl": "./image/team-1.jpg" },
    { "id": "1d1be76a-ffbf-4654-9db6-d7464f2abd40", "name": "Gevorg", "lastName": "Hunanyan", "age": 20, "job": "developer", "imageUrl": "./image/team-3.jpg" },
    { "id": "4a914765-48ce-41ac-a412-be31eee81bb2", "name": "Mane", "lastName": "Hakobyan", "age": 18, "job": "", "imageUrl": "./image/team-4.jpg" },
    { "id": "9d25bfe2-59d1-498c-8293-072b0d148684", "name": "Mariam", "lastName": "Hunanyan", "age": 32, "job": "doctor", "imageUrl": "./image/team-2.jpg" },
    { "id": "faddc483-fd54-457e-8121-a8fab5e6e970", "name": "Hayk", "lastName": "Vardanyan", "age": 44, "job": "doctor", "imageUrl": "./image/team-1.jpg" },
    { "id": "bb546d56-218c-467a-b827-c7c2b89b6f66", "name": "Arman", "lastName": "Arshakyan", "age": 26, "job": "police", "imageUrl": "./image/team-3.jpg" },
    { "id": "697e87f3-cd97-49d6-b837-2498a03b8d27", "name": "Davit", "lastName": "Hunanyan", "age": 22, "job": "police", "imageUrl": "./image/team-1.jpg" },
    { "id": "664041f9-a9f3-48a3-bc5f-d0637dd374c6", "name": "Armine", "lastName": "Vardanyan", "age": 17, "job": "", "imageUrl": "./image/team-2.jpg" },
    { "id": "af7bf17a-d1fa-4870-b863-6b43c9d94886", "name": "Karine", "lastName": "Hakobyan", "age": 26, "job": "teacher", "imageUrl": "./image/team-4.jpg" }
];
function del() {
    document.getElementsByClassName('people').innerHTML = "";
}
function getAge(age) {
    let calculatedAge = 0 + age;
    return `${calculatedAge} years old`;
}
function jobs(job) {
    let favJob = job;
    return `Current job is ${favJob}`;
}
function peopleTemplate(people) {
    return `
    <div class="people" id = "somediv">
    <img class="people-imageUrl" src="${people.imageUrl}">
    <h2 class="people-name" id="nameOfpeople">${people.name} <span class="lastName">(${people.lastName})</span></h2>
    <p><strong>Age:</strong> ${getAge(people.age)}</p>
    <p><strong>Job:</strong> ${jobs(people.job)}</p>
    <button class = "myBtn" onclick = "this.del()"> x </button>    
    </div>`;
}

document.getElementById("app").innerHTML = `
            <h1 class="app-title">There are ${peoplesData.length} peoples regitred</h1>
            ${peoplesData.map(peopleTemplate).join("")}
            <p class="footer">End of page.</p>`;

function getResult() {
    var s = document.getElementById("search").value;
    var k = document.getElementById("nameOfpeople");
    if (s === k) {
        alert('This name exists');
    }
    else {
        alert('This name do not exist in this page');
    }
}
