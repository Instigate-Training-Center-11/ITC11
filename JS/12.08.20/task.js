const a = {
    "investmentsData": [
      {"id": "49e9e1db-161c-4988-b3ab-e1779286b65f",  "investments": 150},
      {"id": "7a43da8c-0f54-4105-a869-692790024d71",  "investments": 1200},
      {"id": "18eecfd2-2f9f-4675-bed3-8192094fe968",  "investments": 1400},
      {"id": "383c0b79-0b62-416d-aec3-8e904f1c77cc",  "investments": 250},
      {"id": "12340853-4c1c-4c68-bdfa-c46c9a21b752",  "investments": 150},
      {"id": "bcc35ab6-3759-4c29-803a-07189763ec12",  "investments": 580},
      {"id": "1d1be76a-ffbf-4654-9db6-d7464f2abd40",  "investments": 760},
      {"id": "4a914765-48ce-41ac-a412-be31eee81bb2",  "investments": 120},
      {"id": "9d25bfe2-59d1-498c-8293-072b0d148684",  "investments": 200},
      {"id": "faddc483-fd54-457e-8121-a8fab5e6e970",  "investments": 8250},
      {"id": "bb546d56-218c-467a-b827-c7c2b89b6f66",  "investments": 100},
      {"id": "697e87f3-cd97-49d6-b837-2498a03b8d27",  "investments": 80},
      {"id": "664041f9-a9f3-48a3-bc5f-d0637dd374c6",  "investments": 140},
      {"id": "af7bf17a-d1fa-4870-b863-6b43c9d94886",  "investments": 180}
    ]
  };

const c = {
    "peoplesData": [
      {"id": "49e9e1db-161c-4988-b3ab-e1779286b65f", "name": "Armen", "age": 32, "job": "bugalter"},
      {"id": "7a43da8c-0f54-4105-a869-692790024d71", "name": "Artak", "age": 28, "job": "developer"},
      {"id": "18eecfd2-2f9f-4675-bed3-8192094fe968", "name": "Karen", "age": 26, "job": "developer"},
      {"id": "383c0b79-0b62-416d-aec3-8e904f1c77cc", "name": "Ashot", "age": 45, "job": "teacher"},
      {"id": "12340853-4c1c-4c68-bdfa-c46c9a21b752", "name": "Nelli", "age": 21, "job": "teacher"},
      {"id": "bcc35ab6-3759-4c29-803a-07189763ec12", "name": "Hakob", "age": 16, "job": ""},
      {"id": "1d1be76a-ffbf-4654-9db6-d7464f2abd40", "name": "Gevorg", "age": 20, "job": "developer"},
      {"id": "4a914765-48ce-41ac-a412-be31eee81bb2", "name": "Mane", "age": 18, "job": ""},
      {"id": "9d25bfe2-59d1-498c-8293-072b0d148684", "name": "Mariam", "age": 32, "job": "doctor"},
      {"id": "faddc483-fd54-457e-8121-a8fab5e6e970", "name": "Hayk", "age": 44, "job": "doctor"},
      {"id": "bb546d56-218c-467a-b827-c7c2b89b6f66", "name": "Arman", "age": 26, "job": "police"},
      {"id": "697e87f3-cd97-49d6-b837-2498a03b8d27", "name": "Davit", "age": 22, "job": "police"},
      {"id": "664041f9-a9f3-48a3-bc5f-d0637dd374c6", "name": "Armine", "age": 17, "job": ""},
      {"id": "af7bf17a-d1fa-4870-b863-6b43c9d94886", "name": "Karine", "age": 26, "job": "teacher"}
    ]
  }

  ///__________2____________
 const b = c.peoplesData.filter(asa =>  a.investmentsData.filter(word => word.investments > 500).find(element => asa.id === element.id));
 console.log(...b);

 ///__________4____________

 const k = c.peoplesData.filter(el => Object.assign(el,(a.investmentsData.find(element => element.id === el.id))));
console.log(...k);

///__________5____________

const t = new WeakMap()
k.forEach(el => t.set(el));
console.log(t);

///__________3____________

k.sort(function(a,b){
  return a.investments - b.investments;
  }
);
k.reverse();
var sort = [];
for(var i = 0; i < 3; ++i) {
  sort[i] = k[i];
}
console.log(sort);

