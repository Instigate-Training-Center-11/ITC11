// ======================MAP==============================
const myMap = new Map();

myMap.set(0, 'zero');
myMap.set(1, 'one');

for (var [key, value] of myMap) {
    console.log(key + ' = ' + value);
}

for (var key of myMap.keys()) {
    console.log(key);
}

myMap.set(2, 'two');
console.log(myMap.size);

myMap.delete(1);
console.log(myMap.size);

for (var [key, value] of myMap.entries()) {
    console.log(key + ' = ' + value);
}

console.log('2 has in myMap ? ', myMap.has(2));

console.log(myMap.entries());

console.log(myMap.values());

myMap.clear()
console.log(myMap);

//