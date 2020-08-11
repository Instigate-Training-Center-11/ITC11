let id1 = Symbol("id");
let id2 = Symbol("id");

console.log(id1 == id2); // false

console.log(typeof id1);
console.log(id1.toString());
console.log(id1.description);

let user = {
    name: "Levon"
};

let id = Symbol("id");

user[id] = 16;

console.log(user[id]);
console.log(user);

let user1 = {
  name: "Levon",
  age: 16,
  [id]: 123
};

for (let key in user1) {
    console.log("user: ", key);
}

let id3 = Symbol.for("id");

let idAgain = Symbol.for("id");

console.log( id3 === idAgain );