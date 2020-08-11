const copyObject = function (obj) {
    return JSON.parse(JSON.stringify(obj));
}

const obj = {
    foo: 'Bar',
    name: 'Ani',
    age: 16,
    phone: '37455887799',
}

const copyObj = copyObject(obj);

copyObj.foo = 'baz';
copyObj.name = 'Armen';

obj.newProp = 'neew';
console.log(obj);
console.log(copyObj);