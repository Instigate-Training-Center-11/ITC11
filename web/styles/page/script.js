var calc = document.getElementById('calc');
var result = 0;
var newNum = false;
var oper = '';

function press(num) {
    if (newNum) {
        calc.numbers.value = num;
        newNum = false;
    } else {
        if (calc.numbers.value == '0') {
            calc.numbers.value = num;
        } else {
            calc.numbers.value += num;
        }
    }
};

function operation(Op) {
    var numbers = calc.numbers.value;
    newNum = true;

    if ('+' == oper) {
        result += parseFloat(numbers);
    } else if ( '-' == oper ) {
        result -= parseFloat(numbers);
    } else if ( '/' == oper ) {
        result /= parseFloat(numbers);
    } else if ( '*' == oper ) {
        result *= parseFloat(numbers);
    } else {
        result = parseFloat(numbers);
    }
    calc.numbers.value = result;
    oper = Op;
};

function dote() {
    var num  = calc.numbers.value;
    if (newNum) {
        num = '0.';
        newNum = false;
    } else {
        if (num.indexOf('.') == -1)
            num += '.';
    }
    calc.numbers.value = num;
};
            
function del() {
    calc.numbers.value = '0';
    newNum = true;
};

function neg() {
    calc.numbers.value = parseFloat(calc.numbers.value) * -1;
};