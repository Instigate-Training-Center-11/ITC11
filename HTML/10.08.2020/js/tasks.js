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

createVariable()