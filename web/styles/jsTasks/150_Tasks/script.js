// Task 1
function getData() {
    var data = new Date();
    var day = data.getDay();
    var days = [
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday","Friday","Saturday"
    ];
    console.log("Data is: " + days[day]);

    var h = data.getHours();
    var m = data.getMinutes();
    var sec = data.getSeconds();

    var dayPart = (h >= 12) ? "PM" : "AM";
    h = (h >= 12) ? h - 12 : h;

    console.log(`Current Time: ${h} ${dayPart} : ${m} : ${sec}`);
};
getData();

// Task 2
function pr() {
    window.print();
};

// Task 3
function dayFormat() {
    var data = new Date();
    var d = data.getDate();
    var m = data.getMonth() + 1;
    var y = data.getFullYear();

    if (d < 10) {
        d = '0' + d;
    } 

    if (m < 10) {
        m = '0' + m;
    }

    data = m + '/' + d + '/' + y;
    console.log(data);
};
dayFormat();

// Task 4
function area(a, b, c) {
    var half = 0.5 * b;
    var h = Math.sqrt((a * a) - (half * half));
    var s = 0.5 * (h * c);
    console.log(s);
};
area(5, 6, 7);

// Task 5
function rotateStr() {
    var str = 'w3resource';
    var len = str.length;
    for (var i in str) {
        str = str.charAt(len - 1) + str.substring(0, len - 1);
    }
    console.log(str)
};
rotateStr();

// Task 6
function leap(year) {
    return new Date(year, 1, 29).getDate() === 29;
};
console.log(leap(2019));
console.log(leap(2020));

// Task 7
function sunday() {
    var start = 2014;
    var end = 2050;
    var days;

    while (start <= end) {
        days = new Date(start, 0, 1).getDay();
        if (days === 0) {
            console.log("Jan 1st of " + start + " is sunday");
        }
        start++;
    }
}
sunday();

// Task 8
function findNum() {
    var num = parseInt(Math.random() * 10 + 1);
    var inp = prompt('Input the number: 1 - 10');
 
    if(isNaN(inp)) {
        alert('Enter only number');
    } else {
        if(num == inp){
            console.log('Good Work');
        } else {
            console.log('Not matched');
        }
    }
};
// findNum();

// Task 9
function dayCount() {
    var oneMinute = 60 * 1000;
    var oneHour = oneMinute * 60;
    var oneDay = oneHour * 24;
    var today = new Date();
    var nextNewYear = new Date();
    nextNewYear.setMonth(11);
    nextNewYear.setDate(31);

    var daysCount = nextNewYear.getTime() - today.getTime();
    daysCount = Math.floor(daysCount / oneDay);
    console.log(daysCount);
};
dayCount();

// Task 10
function mul() {
    num1 = document.getElementById("first").value;
    num2 = document.getElementById("second").value;
    document.getElementById("result").innerHTML = num1 * num2;
};

function div() { 
    num1 = document.getElementById("first").value;
    num2 = document.getElementById("second").value;
    document.getElementById("result").innerHTML = num1 / num2;
};

// Task 11
function temperature() {
    var f = document.getElementById('f').value;
    document.getElementById("c").innerHTML = Math.floor((f - 32) / 1.8);
};

// Task 12
function url() {
    console.log(document.URL);
};
url();

// Task 14
function file(fileName) {
    if (fileName.indexOf('.') != -1) {
        var dotIndex = fileName.indexOf('.');
        return fileName.substring(0, dotIndex);
    }
};
console.log(file("script.js"));

// Task 15
function numsDiff(num) {
    if (num > 13) {
        return (num - 13) * 2;
    } else {
        return 13 - num;
    }
};
console.log(numsDiff(25));
console.log(numsDiff(8));

// Task 16 
function sum(a, b) {
    if (a === b) {
        return 3 * (a + b);
    } else {
        return a + b;
    }
};
console.log(sum(4, 5));
console.log(sum(5, 5));

// Task 17
function absDiff(num) {
    if (num > 19) {
        return 3 * Math.abs(num - 19);
    } else {
        return Math.abs(num - 19);
    }
};
console.log(absDiff(5));
console.log(absDiff(29));

// Task 18
function twoNums(a, b) {
    if (a === 50 || b === 50 || a + b === 50) {
        return true;
    } else {
        return false;
    }
};
console.log(twoNums(10, 40));
console.log(twoNums(10, 50));
console.log(twoNums(1, 2));

// Task 19
function interval(num) {
    if (num >= 20 && num < 100 || num >= 20 && num < 400) {
        return true;
    } else {
        return false;
    }
};
console.log(interval(10));
console.log(interval(80));

// Task 20
function positiv_negativ(a, b) {
    if (a >= 0 && b < 0 || a < 0 && b >= 0) {
        return true;
    } else {
        return false;
    }
};
console.log(positiv_negativ(5, -5));
console.log(positiv_negativ(-5, -5));
console.log(positiv_negativ(-5, 5));

// Task 21
function addStr(str) {
    if (str.indexOf('Py') != -1) {
        return str;
    } else {
        return 'Py' + str;
    }
};
console.log(addStr('Python'));
console.log(addStr('thon_and_JS'));

// Task 22
function delSymbol(str, pos) {
    var len = str.length;
    return str.substring(0, pos) + str.substring(pos + 1, len);
};
console.log(delSymbol('summer', 2));

// Task 23
function newStr(str) {
    var len = str.length;
    var first = str[0];
    if (len >= 1) {
        return str[len - 1] + str.substring(1, len - 1) + str[0];
    } 
};
console.log(newStr('Summer'));

// Task 24
function strFrontBack(str) {
    return str[0] + str + str[0];
};
console.log(strFrontBack('SUMMER'));

// Task 25
function multiple(num) {
    if (num % 3 === 0 || num % 7 === 0) {
        return true;
    } else {
        return false;
    }
};
console.log(multiple(21));
console.log(multiple(17));
console.log(multiple(14));

// Task 26
function lastThree(str) {
    var len = str.length;
    var last = str.substring(len - 3, len);
    if (len >= 3) {
        return last + str + last;
    }
};
console.log(lastThree("123456789"));

// Task 27
function start(str) {
    var len = str.length;
    var start = str.substring(0, 4);
    if (len >= 4) {
        if (start == 'Java') {
            return true;
        } else {
            return false;
        }
    }
};
console.log(start('123456789'));
console.log(start('Java'));
console.log(start('Java_Script'));

// Task 28
function intervalTwoNum(a, b) {
    if ((a >= 50 && a <= 99) || (b >= 50 && b <= 99)) {
        return true;
    } else {
        return false;
    }
};
console.log(intervalTwoNum(70, 80));
console.log(intervalTwoNum(40, 80));
console.log(intervalTwoNum(70, 180));
console.log(intervalTwoNum(7, 180));

// Task 29
function intervalThreeNum(a, b, c) {
    if ((a >= 50 && a <= 99) || (b >= 50 && b <= 99) || (c >= 50 && c <= 99)) {
        return true;
    } else {
        return false;
    }
};
console.log(intervalThreeNum(1, 2, 60));
console.log(intervalThreeNum(1, 60, 70));
console.log(intervalThreeNum(1, 60, 2));
console.log(intervalThreeNum(70, 1, 2));
console.log(intervalThreeNum(7, 1, 2));

// Task 30
function findStr(str) {
    var subStr = 'Script';
    var arr = str.split(' ');
    for (var i in arr) {
        if (arr[i] == subStr) {
            arr.splice(i, 1);
            return arr.join(' ');
        } else {
            return arr.join(' ');
        }
    }
};
console.log(findStr('aaa bbb ccc Script ddd'));
console.log(findStr('summer, sun'));