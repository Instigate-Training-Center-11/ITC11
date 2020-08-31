const add = function(num1, num2) {
    try {
        return parseFloat(num1) + parseFloat(num2);
    } catch (error) {
        return "Not a Number";
    }
}

const sub = function(num1, num2) {
    try {
        return parseFloat(num1) - parseFloat(num2);
    } catch (error) {
        return "Not a Number";
    }
}

const mul = function(num1, num2) {
    try {
        return parseFloat(num1) * parseFloat(num2);
    } catch (error) {
        return "Not a Number";
    }
}

const div = function(num1, num2) {
    try {
        if(parseFloat(num2) !== 0) {
            return parseFloat(num1) / parseFloat(num2);
        }

        return "Can not division by 0";
    } catch (error) {
        return "Not a Number";
    }

}

const testForAdd = function(val1, val2, res) {
    const result = add(val1, val2);
    if(res == result || result === "Not a Number") {
        console.log("Functional test for add function is ready");
    } else {
        console.log("Functional test for add function is fail");
    }
}

const testForSub = function(val1, val2, res) {
    const result = sub(val1, val2);

    if(res == result || result === "Not a Number") {
        console.log("Functional test for subscription function is ready");
    } else {
        console.log("Functional test for subscription function is fail");
    }
}

const testForMul = function(val1, val2, res) {
    const result = mul(val1, val2);

    if(res == result || result === "Not a Number") {
        console.log("Functional test for multiplication function is ready");
    } else {
        console.log("Functional test for multiplication function is fail");
    }
}

const testForDiv = function(val1, val2, res) {
    const result = div(val1, val2);

    if(res == result || result === "Not a Number" || result === "Can not division by 0") {
        console.log("Functional test for division function is ready");
    } else {
        console.log("Functional test for division function is fail");
    }
}

testForAdd('4', 5, 'a');
testForDiv(8, '0');
testForMul('4', 5, 'aaa');
testForSub(32, 24, 8);