function copy(obj) {
    var copiedObj = {};
    for(var key in obj) {         
        if(obj[key] != null &&  typeof(obj[key]) == "object") {
            copiedObj[key] = copy(obj[key]);
            continue;
        }
        copiedObj[key] = obj[key];
    }
    return copiedObj;
};

var ob = {
    fild1: 1,
    fild2: "obj",
    fild3: { 
        fild4: 2 
    },
    fild5: ['a', 'b']
};

var copyObj = copy(ob);
copyObj.fild1 = 1111;
copyObj.fild5[1] = true;
ob.fild2 = {
    new: 'new fild'
};

ob.fild3.fild4 = ['arr1', 'arr2', true, 16];
console.log(ob);
console.log(copyObj);