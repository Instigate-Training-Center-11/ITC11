msgLen = 'Exceeded the planned limit'
msgType = 'Entered an incorrect type';
msgZero = 'Can not be divided by zero';

function test(num1, num2) {
    if (num1 > Number.MAX_VALUE || num1 > Number.MAX_VALUE
        || num1 < Number.MIN_VALUE || num1 < Number.MIN_VALUE) {
        throw msgLen;
    } else if (typeof(num1) != 'number' || typeof(num1) != 'number') {
        throw msgType;
    }
}

function sum(num1, num2) {
    test(num1, num2);
    if (num1 + num2 > Number.MAX_VALUE || num1 + num2 < Number.MIN_VALUE) {
        throw msgLen;
    }    
    return num1 + num2;
}

function sub(num1, num2) {
    test(num1, num2)
    if (num1 - num2 > Number.MAX_VALUE || num1 - num2 < Number.MIN_VALUE) {
        throw msgLen;
    }
    
    return num1 - num2;
}

function mul(num1, num2) {
    test(num1, num2);
    if (num1 * num2 > Number.MAX_VALUE || num1 * num2 < Number.MIN_VALUE) {
        throw msgLen;
    }
    
    return num1 * num2;
}

function div(num1, num2) {
    test(num1, num2);
    if (num2 == 0) {
        throw msgZero;
    }

    if (num1 / num2 > Number.MAX_VALUE || num1 / num2 < Number.MIN_VALUE) {
        throw msgLen;
    }

    return num1 / num2;
}

function mod(num1, num2) {
    test(num1, num2);
    if (num2 == 0) {
        throw msgZero;
    }

    if (num1 % num2 > Number.MAX_VALUE || num1 % num2 < Number.MIN_VALUE) {
        throw msgLen;
    }

    return num1 % num2;
}

function showResult(symbol){
    var firstNumber = parseFloat(document.getElementById('num1').value);
    var secondNumber = parseFloat(document.getElementById('num2').value);
    var result;

    switch(symbol) {
        case '+':
            result = sum(firstNumber, secondNumber);
            break;
        case '-':
            result = sub(firstNumber, secondNumber);
            break;
        case '*':
            result = mul(firstNumber, secondNumber);
            break;
        case '/': 
            result = div(firstNumber, secondNumber);
            break;
        case '%':
            result = mod(firstNumber, secondNumber);
            break;
        default:
            break;      
    }

    document.getElementById('result').value = result;
}