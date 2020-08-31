const add = function(num1, num2) {
    return num1 + num2;
}

const sub = function(num1, num2) {
    return num1 - num2;
}

const mul = function(num1, num2) {
    return num1 * num2;
}

const div = function(num1, num2) {
    if(num2 !== 0) {
        return num1 / num2;
    }

    return "Can not division by 0";
}

const testForAdd = function() {
    const result = add(3, 5);
    if(8 === result) {
        console.log("Functional test for add function is ready");
    } else {
        console.log("Functional test for add function is filed");
    }
}

const testForSub = function() {
    const result = sub(5, 8);

    if(-3 === result) {
        console.log("Functional test for subscription function is ready");
    } else {
        console.log("Functional test for subscription function is filed");
    }
}

const testForMul = function() {
    const result = mul(4, 8);

    if(32 === result) {
        console.log("Functional test for multiplication function is ready");
    } else {
        console.log("Functional test for multiplication function is filed");
    }
}

const testForDiv = function() {
    const result = div(12, 0);

    if(12/0 === result) {
        console.log("Functional test for division function is ready");
    } else {
        console.log("Functional test for division function is filed");
    }
}

testForAdd();
testForDiv();
testForMul();
testForSub();