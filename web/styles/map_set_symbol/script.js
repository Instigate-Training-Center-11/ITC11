// Create js map
var map = new Map([
    ['name', 'Anna'],
    ['surname', 'Harutyunyan'],
    ['country', 'Armenia'],
    ['city', 'Vanadzor']
]);

console.log(map);
console.log(map.entries());
console.log(map.keys());
console.log(map.values());

var obj = {
    about: 'About person',
    method: function() {
        console.log(this.about);
    }
};

map
    .set(obj, 'The key is object')
    .set(() => console.log('foo'), ['the', 'key', 'is', 'function'])
    .set('age', 'unknown')
    .set(NaN, () => console.log('NaN = Not a Number'))
    .set(undefined, 'undefined value')
    .set(Infinity, 'very big number')
    .set(null, undefined)

for (var i of map.entries()) {
    console.log(i);
}

console.log(map.has('age'));
map.delete('age');
console.log(map.has('age'));

console.log(map.get(obj.method()));

map.forEach((k, v, map) => {
    console.log(k, v);
});

// map to array
var arr = Array.from(map);
console.log(arr);

map.clear();
console.log(map.entries());

// Create js set
var set = new Set([111, 1, 2, 3, 4, 4, 4, 5, 5, 5, 5, 6, 7]);
console.log(set);

console.log(set.has(5));
console.log(set.has(55));
set.delete(5);
console.log(set.has(5));

console.log(set.values());
console.log(set.keys());
console.log(set.entries());

set.add('str')
    .add({
        key: 'value'
    })
    .add(() => 5)

console.log(set);

function uniq(arr) {
    return Array.from(new Set(arr));
};

console.log(uniq([1, 4, 4, 4, 5, 5, 6, 7, 7, 7, 8, 8, 8, 8]));

set.clear();
console.log(set);

// weekmap js
var obj1 = {
    key: 'val'
};
var weakMap = new WeakMap([
    [obj1, 'obj']
]);

console.log(weakMap.get(obj1));
obj1 = null;
console.log(weakMap.get(obj1));
console.log(weakMap.has(obj1))

// js weakset
var obj2 = {
    key: 555
};
var weakSet = new WeakSet([obj2]);

console.log(weakSet.has(obj2));
obj2 = null;
console.log(weakSet.has(obj2));

// js symbols
var sym1 = Symbol('mySymbol');
console.log(sym1);

var sym2 = Symbol('mySymbol');
console.log(sym1 === sym2);

var sym3 = Symbol.for('mySymbol2');
console.log(sym3);

var sym4 = Symbol.for('mySymbol2');
console.log(sym3 === sym4);

var name = Symbol.keyFor(sym4);
console.log(name);

var object = {
    name: 'Jane',
    age: 25,
    [Symbol('password')]: 'Jane25'
};

console.log(object.password); // undefined
console.log(object[Symbol('password')]); // undefined

var object2 = {
    name: 'Jane',
    age: 25,
    [Symbol.for('password')]: 'Jane25',
    [Symbol.for('login')]: 'Jane_25',
    ['aaa']: 'name'
};

console.log(object2.password); // undefined
console.log(object2[Symbol.for('password')]); // 'Jane25'

console.log(Object.getOwnPropertySymbols(object2));

for (var i in object2) {
    console.log(i);
}