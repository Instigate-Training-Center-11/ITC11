function deepCopyObject(obj) {
    const copy = JSON.parse(JSON.stringify(obj));
    copy.arr[0] = "string";
    copy.data = {
        name: 'NAME'
    };
    obj.number = 777;
    console.log(obj);
    console.log(copy);
};

const obj = {
    str: 'any_str',
    number: 555,
    data: new Date(),
    boolean: false,
    arr: [1, 2, 3]
};
deepCopyObject(obj);