// Task 1
function data () {
    var currontDay = new Date();
    var day = currontDay.getDay();
    var weekDays = ["Sunday","Monday","Tuesday","Wednesday ","Thursday","Friday","Saturday"];
    console.log("currontDay is : " + weekDays[day] + ".");
    var second = currontDay.getSeconds();
    var minute = currontDay.getMinutes();
    var hour = currontDay.getHours();
    if (hour >= 12) {
        var half = " PM ";
    } else {
        var half = " AM ";
    }

    if (hour >= 12) {
        hour = hour - 12;
    }

    console.log("Current Time : " + hour + half + " : " + minute + " : " + second);
};

data();

// Task 2

function printWindow() {
    window.print();
}

// printWindow();

// Task 3

function getData(simbol) {
    var currentDay = new Date();
    var day = currentDay.getDate();
    var month = currentDay.getMonth();
    var year = currentDay.getFullYear();
    return (day + simbol + month + simbol + year);
};

console.log(getData('/'));
console.log(getData('-'));
console.log(getData(':'));    

// Task 4

function triangle(a, b, c) {
    if (a + b < c || a + c < b || b + c < a) {
        return 'There is not triangle on these sides.';
    }  

    var perimeter = a + b + c;
    var area = Math.sqrt(perimeter / 2 * (perimeter / 2 - a) * 
        (perimeter / 2 - b) * (perimeter / 2 - c));
    return area; 
};

console.log(triangle(5, 12, 13));

// Task 5

function rotateString(str) {
    for (let i = 0; i < str.length; ++i) {
        str = str[str.length - 1] + str.substring(0, str.length - 1);
    }

    return str;
};

console.log(rotateString('Serzh'));

// Task 6

function leapYear(year) {
    if (year % 4 === 0) {
        console.log(year, 'is leap year');
    } else {      
        console.log(year, 'is not leap year');
    }
};

leapYear(2000);
leapYear(2001);

// Task 7

function sunday() {
    for (var i = 2014; i <= 2050; ++i) {
        var day = new Date(i, 0, 1);
        if (day.getDay() === 0 ) {
            console.log('1st January is being a Sunday in ' + i + ' year');
        }
    }
};

sunday();

// task 8

function checkNumber() {
    var number = Math.floor((Math.random() * 10) + 1);
    var check = prompt('Check a number');
 
    if (number === check) {
        return 'Good Work';
    }else {
        return 'Not matched ' + number;
    }
};

// console.log(checkNumber());

// task 9

function newYear() {
    var oneMinute = 60 * 1000;
    var oneHour = oneMinute * 60;
    var oneDay = oneHour * 24;
    var today = new Date();
    var newYearDay = new Date();
    newYearDay.setMonth(11);
    newYearDay.setDate(31);
    var diff = newYearDay.getTime() - today.getTime();
    return diff = Math.floor(diff / oneDay);
};

console.log(newYear());

// task 10

function calculate() {
    var number1 = prompt('Enter the first numer');
    var number2 = prompt('Enter the second numer');
    console.log(number1 * number2);
    console.log(number1 / number2);
};

// calculate();

// Task 11

function celsius(fahrenheit) {
    var cel = (fahrenheit - 32) * 5 / 9;
    return cel;
};

console.log(celsius(45));

// Task 12

console.log(document.URL);

// Task 13 -----

// Task 14

function file(fileName) {
    array = fileName.split('.');
    return array[1];
};

console.log(file('system.cpp'));
console.log(file('system.html'));

// Task 15

function diff13(number) {
    if (13 >= number) {
        return 13 - number;
    } else {
        return (number - 13) * 2;
    }
}

console.log(diff13(18));
console.log(diff13(7));

// Task 16

function xSum(number1, number2) {
    if (number1 == number2) {
        return 3 * (number1 + number2);
    } else {
        return number1 + number2;
    }
}

console.log(xSum(3, 3));
console.log(xSum(3, 4));

// Task 17

function diff19(number) {
    if (number <= 19) {
        return (19 - number);
    } else {
        return (number - 19) * 3;
    }
}
  
console.log(diff19(5));
console.log(diff19(19));
console.log(diff19(45));

// Task 18

function compare(number1, number2) {
    return ((number1 == 50 || number2 == 50) || (number1 + number2 == 50));
}

console.log(compare(50));
console.log(compare(17, 33));
console.log(compare(51, 3));

// Task 19

function interval(number) {
    return number > 20 && number < 400;
}
  
console.log(interval(15));
console.log(interval(90));
console.log(interval(499));

  
// Task 20

function signed(number1, number2) {
    if ((number1 < 0 && number2 > 0) || number1 > 0 && number2 < 0) {
        return true;
    } else {
        return false;
     }
}

console.log(signed(3, 4));
console.log(signed(-1, 4));
console.log(signed(24, -12));
console.log(signed(-8, -5));