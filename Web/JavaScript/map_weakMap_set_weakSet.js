const someMap = new Map();
const keyObj = {},

    keyFunc = function () { }
keyString = 'a string';

someMap.set(keyString, 'value with string');
someMap.set(keyFunc, "Value with function");
someMap.set(keyObj, "Value with obj");

console.log(someMap.size);

/* three lines below return undnefined */
console.log(someMap.keyString);
console.log(someMap.keyFunc);
console.log(someMap.keyObj);

/* three lines below return values */
console.log(someMap.get(keyString));
console.log(someMap.get(keyFunc));
console.log(someMap.get(keyObj));

someMap.set(NaN, 'nota a number');

someMap.set(0, 'zero');

for (var [key, value] of someMap) {
    console.log(key);
}

for (var value of someMap.values()) {
    console.log(value);
}

for (var [key, value] of someMap.entries()) {
    console.log(key + ':' + value);
}
someMap.forEach(function (value, key) {
    console.log(`${key} => ${value}`);
});

const firstMap = new Map(
    [1, "one"],
    [2, "two"],
    [3, "three"]
)
const second = new Map([
    [1, 'uno'],
    [2, 'dos']
]);

const marged = new Map([...firstMap, ...second]);
/*-------------------------------------*/
const weakMap1 = new WeakMap(),
    weakMap2 = new WeakMap(),
    weakMap3 = new WeakMap();
const obj1 = {},
    obj2 = function () { },
    obj3 = window,
    o4 = [1, 2, 3];

weakMap1.set(obj1, 37);
weakMap1.set(obj2, 'some');
weakMap2.set(obj1, obj2);
weakMap2.set(obj3, undefined);
weakMap2.set(weakMap1, weakMap2);

weakMap1.get(obj2);
weakMap2.get(obj2);
weakMap2.get(obj3);

weakMap1.has(obj2);
weakMap2.has(obj2);
weakMap2.has(obj3);

weakMap3.set(obj1, 37);
weakMap3.get(obj1);

weakMap1.has(obj1);
weakMap1.delete(obj1);
/*----------------------------------*/
var mySet = new Set();

mySet.add(1);
mySet.add(5);
mySet.add(5);
mySet.add("some text");
var o = { a: 1, b: 2 };
mySet.add(o);

mySet.add({ a: 1, b: 2 });

mySet.has(1);
mySet.has(3);
mySet.has(5);
mySet.has(Math.sqrt(25));
mySet.has("Some Text".toLowerCase());
mySet.has(o);

mySet.size;

mySet.delete(5);
mySet.has(5);

mySet.size;
console.log(mySet);
/*---------------------------------*/
var weakSet = new WeakSet();
var obj = {};
var foo = {};

weakSet.add(window);
weakSet.add(obj);

weakSet.has(window); 
weakSet.has(foo);    

weakSet.delete(window); 
weakSet.has(window); 