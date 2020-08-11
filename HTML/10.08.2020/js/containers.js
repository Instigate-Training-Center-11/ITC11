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

// ======================SET==============================
const mySet = new Set();

mySet.add(558);
mySet.add(558);
mySet.add(777);
mySet.add("asaa");

console.log(mySet);
console.log('558 has in mySet? ',mySet.has(558));

mySet.delete(558);
console.log('558 has in mySet? ',mySet.has(558));

console.log('size of mySet', mySet.size);

mySet.forEach(function display(value) {
    console.log(value);
})

mySet.clear();

// ======================weakMap==============================
const wm = new WeakMap();

const o1 = {},
    o2 = function(){},
    o3 = window,
    o4 = [1, 2, 3];

wm.set(o1, 44);
wm.set(o2, 'foo');
wm.set(o3, 'bar');

console.log(wm.get(o2));
console.log(wm.has(o2));

wm.delete(o1);
console.log(wm);

// ======================weakSet==============================
let ws = new WeakSet();

let objj = {};
let foo1 = {};

ws.add(window);
ws.add(objj);

console.log('window has in WeakSet? ', ws.has(window));
console.log('foo1 has in WeakSet? ', ws.has(foo1));

ws.delete(window);
console.log('window has in WeakSet? ', ws.has(window));