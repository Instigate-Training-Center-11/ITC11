const math = {};

math.add = function(num1, num2) {
    try {
        return parseFloat(num1) + parseFloat(num2);
    } catch (error) {
        return "Not a Number";
    }
}

math.sub = function(num1, num2) {
    try {
        return parseFloat(num1) - parseFloat(num2);
    } catch (error) {
        return "Not a Number";
    }
}

math.multiply = function(num1, num2) {
    try {
        return parseFloat(num1) * parseFloat(num2);
    } catch (error) {
        return "Not a Number";
    }
}

math.div = function(num1, num2) {
    try {
        if(parseFloat(num2) !== 0) {
            return parseFloat(num1) / parseFloat(num2);
        }

        return "Can not division by 0";
    } catch (error) {
        return "Not a Number";
    }

}

module.exports = math;