
const math = require("./index");

const testForAdd = function(val1, val2, res) {
    const result = math.add(val1, val2);
    if(res == result || result === "Not a Number") {
        console.log("Functional test for addition function is ready (", val1, " + ", val2, " = ", result, ")");
    } else {
        console.log("Functional test for addition function is fail (", val1, " + ", val2, " != '", res, "')");
    }
}

const testForSub = function(val1, val2, res) {
    const result = math.sub(val1, val2);

    if(res == result || result === "Not a Number") {
        console.log("Functional test for subscription function is ready (", val1, " - ", val2, " = ", result, ")");
    } else {
        console.log("Functional test for subscription function is fail (", val1, " - ", val2, " != '", res, "')");
    }
}

const testForMul = function(val1, val2, res) {
    const result = math.multiply(val1, val2);

    if(res == result || result === "Not a Number") {
        console.log("Functional test for multiplication function is ready (", val1, " * ", val2, " = ", result, ")");
    } else {
        console.log("Functional test for multiplication function is fail (", val1, " * ", val2, " != '", res, "')");
    }
}

const testForDiv = function(val1, val2, res) {
    const result = math.div(val1, val2);

    if(res == result || result === "Not a Number" || result === "Can not division by 0") {
        console.log("Functional test for division function is ready (", val1, " / ", val2, " = ", result, ")");
    } else {
        console.log("Functional test for division function is fail (", val1, " / ", val2, " != '", res, "')");
    }
}

testForAdd('4', 5, 'a');
testForDiv(8, '0');
testForMul('4', 5, 'aaa');
testForSub(32, 24, 8);