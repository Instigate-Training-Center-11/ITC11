// ==============1
console.log(this === window); // true

let a = 88;
console.log(window.a); // 88

// ==============2
function f1() {
	return this;
}

f1() === window;

function f2() {
	'use strict'; // see strict mode
	return this;
}

f2() === undefined; // true

// ============3
class Example {
	constructor() {
		console.log(this);
	}
}

a =  new Example(); // ['constructor', 'first', 'second']
a.c = "a new"
b = a;

console.log(b);

b.d = "b new"
console.log(a);

// ==================4
let obj = {tmp: 'Custom'};

let tmp = 'Global';

function whatsThis() {
  return this.tmp;
}

console.log(whatsThis());          // 'Global' as this in the function isn't set, so it defaults to the global/window object
console.log(whatsThis.call(obj));  // 'Custom' as this in the function is set to obj
console.log(whatsThis.apply(obj));

//=================5
function add(c, d) {
	return this.a + this.b + c + d;
}

let obj2 = {a: 1, b: 3};
console.log(add.call(obj2, 15, 9)); // 28
console.log(  add.apply(obj2, [12, 34])); // 50


function bar() {
	console.log(Object.prototype.toString.call(this));
}

console.log(bar.call(64));     // [object Number]
console.log(bar.call(true));     // [object Boolean]
console.log(bar.call('Armine')); // [object String]
console.log(bar.call(undefined)); // [object global]
console.log(bar.call(NaN)); // [object Number]
console.log(bar.call(bar)); // [object Function]


// ======================6
function f() {
	return this;
}

let g = f.bind({a: 'asdf'});
console.log(g()); // asdf

let h = g.bind({a: 'foo'}); // bind only works once!
console.log(h()); // asdf

let o = {a: 37, f: f, g: g, h: h};
console.log(o.a, o.f(), o.g(), o.h());

// =====================7
let globalObject = this;
let foo = (() => this);
console.log(foo() === globalObject); // true

// ========================8
let obj3 = {f: function() { return this; }};
let p = Object.create(obj3);
p.a = 1;
p.b = 4;

console.log(p.f());
console.log(o.f());