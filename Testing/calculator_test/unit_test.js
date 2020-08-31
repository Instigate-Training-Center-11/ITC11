let firstNum = document.getElementById('first');
let secondNum = document.getElementById('second');
let res = document.getElementById('res');

function add() {
    let first = Number(firstNum.value);
    let second = Number(secondNum.value);
    test(first, second, res.value);

    res.value = first + second;
}

function sub() {
    let first = Number(firstNum.value);
    let second = Number(secondNum.value);
    test(first, second, res.value);

    res.value = first - second;
}

function mul() {
    let first = Number(firstNum.value);
    let second = Number(secondNum.value);
    test(first, second, res.value);

    res.value = first * second;
}

function div() {
    let first = Number(firstNum.value);
    let second = Number(secondNum.value);
    test(first, second, res.value);

    if (second === 0) {
        throw 'Second number must be greater 0';
    }

    res.value = first / second;
}

function test(a, b, res) {
    if (a > Number.MAX_VALUE || b > Number.MAX_VALUE || res > Number.MAX_VALUE) {
        throw 'Very big arguments or result';
    }

    if (a < Number.MIN_VALUE || b < Number.MIN_VALUE || res < Number.MIN_VALUE) {
        throw 'Very small arguments or result';
    }

    if (typeof a != 'number' || typeof b != 'number') {
        throw 'You must enter number';
    }

    if (isNaN(a) || isNaN(b)) {
        throw 'Uncorrect input';
    }
}