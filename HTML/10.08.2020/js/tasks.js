// ==============================Task__1=======================================
const getCurrentTime = function() {
    const today = new Date();
    const days = {
        1: 'Sunday',
        2: 'Monday',
        3: 'Tuesday',
        4: 'Wednesday',
        5: 'Thursday',
        6: 'Friday',
        7: 'Saturday'
    }

    const day = today.getDay();
    const hour = today.getHours();
    const minute = today.getMinutes();
    const second = today.getSeconds();

    console.log('Today is : ' + days[day] + '.');
    if(hour >= 12) {
        console.log('Current time is ', hour, 'PM : ', minute, ' : ', second);
    } else {
        console.log('Current time is 0' + hour, 'AM : ', minute.toString(), ' : ', second.toString());
    }
}

// ==============================Task__2=======================================
const printCurrentPage = function() {
    this.print(); //or window.print()
}

// ==============================Task__3=======================================
const getCurrentDate = function() {
    const today = new Date();
    const year = today.getFullYear();
    let month = today.getMonth() + 1;
    let day = today.getDay();

    if(month < 10) {
        month = '0' + month;
    }

    if(day < 10) {
        day = '0' + day;
    }

    console.log(month + '-' + day + '-' + year);
    console.log(month + '/' + day + '/' + year);
    console.log(day + '-' + month + '-' + year);
    console.log(day + '/' + month + '/' + year);
}

// ==============================Task__4=======================================
const calculateTriangleArea = function(side1=5, side2=6, side3=7) {
    const s = (side1 + side2 + side3)/2;
    const area =  Math.sqrt(s*((s-side1) * (s-side2) * (s-side3)));
    console.log(area);
}

// =============================Task__5=======================================
const reverseString = function (str='w3resource') {
    for(let i = 0; i < text.length; ++i){
        str = str[str.length - 1] + str.substring(0, str.length - 1);
    }
}

// =============================Task__6=======================================
const isLeapYear = function (year=2020) {
    let flag = false;
    if(year % 100 === 0) {
        if(year % 400 === 0) {
            flag = true;
        }
    } else {
        if(year % 4 === 0) {
            flag = true;
        }
    }

    if(flag) {
        console.log(year  +' is leap year');
    } else {
        console.log(year + ' is not leap year');
    }

}

// =============================Task__7=======================================
const findJanuary1 = function() {
    let startYear = 2015;
    const lastYear = 2050;
    let countOfSunday = 0

    while(startYear < lastYear) {
        const date = new Date(startYear, 0, 1);
        if(date.getDay() === 0) {
            console.log('1st January is being a Sunday  ' + startYear);
            countOfSunday++
        }
        startYear++;
    }

    console.log('From 2015 year to 2050 1st January is being a Sunday count is: ', countOfSunday);
}

// =============================Task__8=======================================
const goodWork = function() {
    const rand = Math.ceil(Math.random() * 10);
    const num = prompt('Enter the number between 1 and 10');

    if(rand === num) {
        console.log('Good Work');
    } else {
        console.log('Not matched');
    }
}

// =============================Task__9=======================================
const getDayCountUntilChristmas = function() {
    today = new Date();
    let cmas=new Date(2020, 11, 25); //2020 December 25

    if (today.getMonth() === 4 && today.getDate() > 27) {
        cmas.setFullYear(cmas.getFullYear()+1);
    }
    const one_day=1000*60*60*24;
    console.log(Math.ceil((cmas.getTime()-today.getTime())/(one_day))+" days left until Christmas!");
}

// =============================Task__10=======================================
const calculate = function() {
    const num1 = prompt('Enter first number');
    const num2 = prompt('Enter second number');

    console.log(num1, '+', num2, '=', parseInt(num1) + parseInt(num2));
    console.log(num1, '-', num2, '=', parseInt(num1) - parseInt(num2));
    console.log(num1, '*', num2, '=', parseInt(num1) * parseInt(num2));
    if(num2 != 0) {
        console.log(num1, '/', num2, '=', parseInt(num1) / parseInt(num2));
    } else {
        console.log('Cannot division on 0');
    }
}

// =============================Task__11=======================================
const celsiusToFahrenheit = function(celsius) {
    console.log(celsius + ' Celsius To Fahrenheit is : ' + (celsius * 9 / 5 + 32) + ' degree');
}

const fahrenheitToCelsius = function(fahrenheit) {
    console.log(fahrenheit + 'Fahrenheit To Celsius is : ' + ((fahrenheit -32) * 5 / 9) + ' degree');
}

// =============================Task__12=======================================
const webPageURL = function() {
    console.log(document.URL);
}

// =============================Task__13=======================================
const createVariable = function() {
    const name = prompt('Enter variable name');
    this[name] = 'New Variable'

    console.log(name + ' = ' + this[name]);
}

// =============================Task__14=======================================
const getFileExtension = function(fName='task.js') {
    const extension = fName.split('.');
    console.log(fName + ' file extension is: ' + extension[1]);
}


// =============================Task__15=======================================
const difference = function (num) {
    if (num <= 13) {
        return 13 - num;
    }

    return (num - 13) * 2;
}

// =============================Task__16=======================================
const sum = function(num1, num2) {
    if(num1 === num2) {
        return num1 * 3;
    }

    return num1 + num2;
}

// =============================Task__17=======================================
const differenceTwo = function(num) {
    if(num <= 19) {
        return 19 - num;
    }

    return (num - 19) * 3;
}

// =============================Task__18=======================================
const checkFor50 = function(num1, num2) {
    return (num1 === 50 || num2 === 50 || (num1 + num2) === 50);
}

// =============================Task__19=======================================
const numRange = function (num) {
    return ((Math.abs(100 - num) <= 20) || (Math.abs(400 - num) <= 20));
}

// =============================Task__20=======================================
const checkNum = function(num1, num2) {
    if(num1 * num2 < 0) {
        return true;
    }
    return false;
}

// =============================Task__21=======================================
const addPy = function(str) {
    if(str.substr(0, 2) === 'py') {
        return str;
    }

    return 'py' + str;
}

// =============================Task__22=======================================
const removeSymbolInPosition = function(str, pos) {
    if(pos >= str.length) {
        return 'incorrect position';
    }

    return str.slice(0, pos) + str.slice(pos + 1, str.length);
}

// =============================Task__23=======================================
const changingPosition = function(str) {
    if(str.lastYear <= 1) {
        return str;
    }

    return str[str.length - 1] + str.slice(1, str.length - 1) + str[0];
}

// =============================Task__24=======================================
const changeString = function(str) {
    return str[0] + str + str[0];
}

// =============================Task__25=======================================
const multiple3or7 = function(num) {
    return (num % 7 === 0 || num % 3 === 0);
}

// =============================Task__26=======================================
const changeString1 = function(str) {
    if(str.length < 3) {
        return str;
    }

    return str.slice(str.length  - 3, str.length) + str;
}

// =============================Task__27=======================================
const checkJava = function(str) {
    return str.slice(0, 4) === 'java';
}

// =============================Task__28=======================================
const check55From99and = function(num1, num2) {
    return (num1 >= 55 && num1 <= 99) && (num2 >= 55 && num2 <= 99);
}

// =============================Task__29=======================================
const check55From99or = function(num1, num2) {
    return (num1 >= 55 && num1 <= 99) || (num2 >= 55 && num2 <= 99);
}

// =============================Task__30=======================================
const checkScript = function(str) {
    if (str.length < 6) {
        return str;
    }

    if (str.substring(10, 4) == 'Script') {
        return str.substring(0, 4) + str.substring(10,str.length);
    }

    return ' ';
}

// =============================Task__31=======================================
const max = function(num1, num2, num3) {
    if(num1 > num2 ) {
        if(num1 > num3) {
            return num1;
        } else {
            return num3;
        }
    } else if(num2 > num3) {
        return num2;
    } else {
        return num3;
    }
}

// =============================Task__32=======================================
const near_100 = function(num1, num2) {
    if(num1 !== num2) {
        absNum1 = Math.abs(num1 - 100);
        absNum2 = Math.abs(num2 - 100);

        if(num1 > num2) {
            return num1;
        }

        if(num2 > num1) {
            return num2;
        }

        return 0;
    }

    return false;
}


// =============================Task__33=======================================
const numbersRanges = function (num1, num2) {
    if ((num1 >= 40 && num1 <= 60 && num2 >= 40 && num2 <= 60) || (num1 >= 70 && num1 <= 100 && num2 >= 70 && num2 <= 100)) {
      return true;
    }

    return false;
}

// =============================Task__34=======================================
const maxTowNumbersRange = function(num1, num2){
    if( (num1 >= 40) && (num1 <= 60) && (num2 >= 40 && num2 <= 60) ){
        if(num1 === num2){
            return "Numbers are the same";
        }else if (num1 > num2){
            return num1;
        }else{
            return num2;
        }
    }else{
        return "Numbers don't fit in range";
    }
}

// =============================Task__35=======================================
const checkChar = function (str, char) {
    for(let i = 1; i < 4; ++i) {
        if(str[i] === char) {
            return true
        }
    }

    return false;
}

// =============================Task__36=======================================
const lastDigit = function(num1, num2, num3) {
    if(num1 > 0 && num2 > 0 && num3 > 0) {
        return (num1 % 10 == num2 % 10 && num2 % 10 == num3 % 10 && num1 % 10 == num3 % 10)
    }

    return false;
}

console.log(max(15, 7, 9));