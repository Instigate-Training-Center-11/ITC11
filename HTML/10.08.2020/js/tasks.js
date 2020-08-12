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
    if(year % 100 === 0 && year % 400 === 0) {
        flag = true;
    } else if(year % 4 === 0) {
        flag = true;
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

// =============================Task__37=======================================
const upperLower = function(str) {
    if(str.length <= 3) {
        return str.toUpperCase();
    } else {
        return str.substring(0, 3).toLowerCase() + str.substring(3, str.length);
    }

}

// =============================Task__38=======================================
const exam_status = function (totalMarks,isExam) {
    if (isExam) {
        return totalMarks >= 90;
    }

    return (totalMarks >= 89 && totalMarks <= 100);
}

// =============================Task__39=======================================
const sortSum = function (num1, num2) {
    const sum = num1 + num2;
    if (sum >= 50 && sum <= 80) {
        return 65;
    }

        return 80;
}

// =============================Task__40=======================================
const check8 = function(num1, num2) {
    if(num1 === 8 || num2 === 8){
        return true;
    }

    if(num1 + num2 === 8 || Math.abs(num1 - num2) === 8) {
        return true;
    }

    return false;
}

// =============================Task__41=======================================
const three_numbers = function(num1, num2, num3) {
    if(num1 === num2 && num1 === num3) {
        return 30
    }

    if(num1 === num2 || num1 === num3 || num2 === num3) {
        return 40;
    }

    return 20;
}

// =============================Task__42=======================================
const numbers = function(num1, num2, num3) {
    if(num1 < num2 && num2 < num3) {
        return "Strict mode";
    }

    if(num3 > num2) {
        return "Soft mode"
    }

    return "Undefined mode"
}

// =============================Task__43=======================================
const sameLastDigit = function(num1, num2, num3) {
    return (num1 % 10 === num2 % 10) || (num1 % 10 === num3 % 10) || (num2 % 10 === num3 % 10);
}

// =============================Task__44=======================================
const lessBy20 = function(num1, num2, num3) {
    return (num1 >= 20 && (num1 < num2 || num1 < num3)) ||
            (num2 >= 20 && (num2 < num1 || num2 < num3)) ||
            (num3 >= 20 && (num3 < num1 || num3 < num2));
}

// =============================Task__45=======================================
const testNumber = function(num1, num2) {
    return (num1 === 15 || num2 === 15 || num1 + num2 === 15 || Math.abs(num1 - num2) === 15);
}

// =============================Task__46=======================================
const valCheck = function(num1, num2) {
    if (!((num1 % 7 == 0 || num1 % 11 == 0) && (num2 % 7 == 0 || num2 % 11 == 0))) {
        return ((num1 % 7 == 0 || num1 % 11 == 0) || (num2 % 7 == 0 || num2 % 11 == 0));
    }
    return false;
}

// =============================Task__47=======================================
const test_digit = function(num1, num2, num3) {
    if(num3 < 40 || num3 > 10000) {
        return false;
    } else if(num3 >= num1 && num3 <= num2){
        return true;
    }

    return false;
}

// =============================Task__48=======================================
const stringReverse = function(str) {
    return str.split('').reverse().join('');
}

// =============================Task__49=======================================
const changeString3 = function(str) {
    let newString  = '';
    for (let i = 0; i < str.length; ++i) {
        if (64 < str.charCodeAt(i) && str.charCodeAt(i) < 123) {
            newString += String.fromCharCode(str.charCodeAt(i) + 1);
        }
    }
    return newString;
}


// =============================Task__50=======================================
const capitalLetter = function (str) {
    str = str.split(" ");

    for (let i = 0; i < str.length; ++i) {
        str[i] = str[i][0].toUpperCase() + str[i].substr(1);
    }

    return str.join(" ");
}

// =============================Task__51=======================================
const timeConvert = function(time) {
    const hours = Math.floor(time / 60);
    const minutes = time % 60;
  return hours + ":" + minutes;
}

// =============================Task__52=======================================
const alphabetSoup = function(str) {
    return str.split("").sort().join("");
}

// =============================Task__53=======================================
const abCheck = function(str) {
    num1 = str.indexOf('a')
}

// =============================Task__54=======================================
const ab_Check =function(str) {
    const patt1 = new RegExp('a...b');
    const patt2 = new RegExp('b...a');
    return patt1.test(str) || patt2.test(str);
}

// =============================Task__55=======================================
const equal_pt = function(str) {
    const p = str.split('p');
    const t = str.split('t');

    return p.length === t.length;
}

// =============================Task__56=======================================
const division_string = function(num1, num2) {
    let div = Math.round(num1 / num2).toString();
    let res = div.split("");

    if (div >= 1000) {
        for (var i = div.length - 3; i > 0; i -= 3) {
            res.splice(i, 0, ",");
        }
    }

    return res;
}

// =============================Task__57=======================================
const stringCopies = function(str, n) {
    if (n < 0 || str.length === 0) {
        return false;
    }

    return str.repeat(n);
}

// =============================Task__58=======================================
const copyLast3Symbols = function(str) {
    if(str.length >= 3) {
        return str.substring(str.length - 3).repeat(4);
    }

    return false;
}

// =============================Task__59=======================================
const firstHalf = function(str) {
    if(str.length % 2 === 0) {
        return str.substring(0, str.length/2)
    }

    return false;
}

// =============================Task__60=======================================
const withoutFirstEnd = function(str) {
    return str.substring(1, str.length - 1)
}

// =============================Task__61=======================================
const concatenate = function(str1, str2) {
    return str1.substring(1, str.length - 1) + str2.substring(1, str.length - 1);
}

// =============================Task__62=======================================
const rightThree = function(str) {
    if(str.length > 3) {
        return str.substring(str.length - 3, str.length) + str.substring(0, str.length - 3);
    }

    return str;
}

// =============================Task__63=======================================
const middle_three = function(str) {
    if(str.length >= 3 && str.length % 2 !== 0) {
        let mid = (str.length - 3)/2;
        return str.substr(mid, 3);
    }
}

// =============================Task__64=======================================
const strConcat = function(str1, str2) {
    const min = Math.min(str1.length, str2.length);

    return str1.substring(str1.length - min) + str2.substring(str2.length - min);
}

// =============================Task__65=======================================
const findScript = function(str) {
    if(str.length >= 6) {
        return str.substring(str.length - 6) === 'Script';
    }
}

// =============================Task__66=======================================
const cityName = function(str) {
    if(str.length >= 3 && (str.substring(0, 3) === 'Los' || str.substring(0, 3) === 'New')) {
        return str;
    }

    return '';
}

// =============================Task__67=======================================
const deleteP = function(str) {
    if(str[0] === 'P' && str[str.length - 1] === 'P') {
        return str.slice(1, str.length - 1);
    }

    return str;
}

// =============================Task__68=======================================
const two_string = function(str, n) {
    if(n <= str.length/2) {
        return str.slice(0, 2) + str.slice(str.length - 2, str.length);
    }

    return false;
}

// =============================Task__69=======================================
const sum_three =function(nums) {
    return nums[0] + nums[1] + nums[2];
}

// =============================Task__70=======================================
function shiftLeft(array) {
    return [array[1], array[2], array[0]];
}

// =============================Task__71=======================================
const first_last_1 = function(arr) {
    return arr[0] === 1 || arr[arr.length - 1] === 1;
}

// =============================Task__72=======================================
const first_last_same = function(arr) {
    if(arr.length > 1) {
        return arr[0] === arr[arr.length - 1];
    }

    return false;
}

// =============================Task__73=======================================
const reverse3 = function(arr) {
    return [arr[2], arr[1], arr[0]];
}

// =============================Task__74=======================================
const all_max = function(nums) {
    const max = nums[0] > nums[2] ? nums[0] : nums[2];

    nums[0] = max;
    nums[1] = max;
    nums[2] = max;

    return nums;
}

// =============================Task__75=======================================
const middle_elements = function(arr1, arr2) {
    if(arr1.length > 1 && arr2.length > 1) {
        return [arr1[1], arr2[1]];
    }
}

// =============================Task__76=======================================
const started = function(arr) {
    return [arr[0], arr[arr.length - 1]];
}

// =============================Task__77=======================================
const contins13 = function(arr) {
    if(arr.length > 1 && (arr.indexOf(1) !== -1 || arr.indexOf(3) !== -1)) {
        return true;
    }

    return false;
}
// =============================Task__78=======================================
const is13 = function(arr) {
    if(arr.length > 1 && (arr.indexOf(1) === -1 || arr.indexOf(3) === -1)) {
        return true;
    }

    return false;
}
// =============================Task__79=======================================
const twice3040 = function(arr) {
    if(arr.length <= 2) {
        return (arr[0] === 30 && arr[1] === 30) || (arr[0] === 40 && arr[1] === 40);
    }

    return false;
}

// =============================Task__80=======================================
const swap = function(arr) {
    return [arr[0], arr[arr.length - 1]] = [arr[arr.length - 1], arr[0]];
}

// =============================Task__81=======================================
const add_two_digits = function(n) {
      return n % 10 + Math.floor(n / 10);
}


// =============================Task__82=======================================
function add_two_int_without_carrying(num1, num2) {
    let res = 0;
    let pow = 1;
    while (num1 > 0 && num2 > 0) {
        res += pow * ((num1 + num2) % 10);
        num1 = Math.floor(num1 / 10);
        num2 = Math.floor(num2 / 10);
        pow *= 10;
    }
    return res;
}

// =============================Task__83=======================================
const longest_string = function(arr) {
    let max = arr[0].length;
    let index = 0;

    for(let i = 1; i < arr.length; ++i) {
        if(arr[i].length > max) {
            max = arr[i].length;
            index = i;
        }
    }

    return arr[index];
}


// =============================Task__84=======================================
const alphabet_char_Shift = function(str) {
    let newString  = '';
    for (let i = 0; i < str.length; ++i) {
        if (64 < str.charCodeAt(i) && str.charCodeAt(i) < 122 && str.charCodeAt(i)  !== 90) {
            newString += String.fromCharCode(str.charCodeAt(i) + 1);
        } else if(str[i] === 'z') {
            newString += 'a'
        } else if(str[i] === 'Z') {
            newString += 'A'
        }
    }
    return newString;
}

// =============================Task__85=======================================
const alternate_Sums = function(arr) {
    let res = [ 0, 0]
    for(let i = 0; i < arr.length; ++i) {
        if(i % 2 == 0) {
            res[1] += arr[i];
        } else {
            res[0] += arr[i];
        }
    }

    return res;
}

// =============================Task__86=======================================
const angle_Type = function(angle) {
    if(angle < 90) {
        return "Acute angle.";
    }
    if(angle === 90) {
        return "Right angle.";
    }
    if(angle < 180) {
        return "Obtuse angle.";
    }

    return "Straight angle.";
}

// =============================Task__87=======================================
const array_checking = function(arr1, arr2) {
    if(arr1.length !== arr2.length) {
        return false;
    }
    let diff = 0;

    for(let i = 0; i < arr1.length; ++i) {
        if(arr1[i] !== arr2[i]) {
            diff++;
        }
    }

    return diff < 3 ;
}

// =============================Task__88=======================================
const checking_numbers = function(num1, num2, divisor) {
    return (num1 % divisor === 0 && num2 % divisor === 0 || num1 % divisor !== 0 && num2 % divisor !== 0)
}

// =============================Task__89=======================================
const check_arithmetic_Expression = function(num1, num2, result) {
    return (num1 + num2 === result || num1 - num2 === result || num1 * num2 === result || num1 / num2 === result);
}

// =============================Task__90=======================================
function Kth_greatest_in_array(arr, k) {
    arr = arr.sort((a, b) => a - b);

    return arr[arr.length - k]
}

// =============================Task__91=======================================
const array_max_consecutive_sum = function(arr, k) {
    let res = 0;
    for(i = 0; i < arr.length; ++i) {
        let tmp = 0;
        for(let j = 0; j < k; ++j) {
            tmp += arr[i + j]
        }
        if(res < tmp) {
            res = tmp;
        }
    }
    return res;
}

// =============================Task__92=======================================
const max_difference = function(arr) {
    let max = -1;
    for (let i = 0; i < arr.length - 1; ++i) {
        max = Math.max(max, Math.abs(arr[i] - arr[i + 1]));
    }

    return max;
}

// =============================Task__93=======================================
const array_max_diff = function(arr) {
    arr = arr.sort((a, b) => a - b);

    return Math.abs(arr[0] - arr[arr.length - 1]);
}

// =============================Task__94=======================================
const array_element_mode = function(arr) {
    const arr1 = [];
    let res = arr[0];
    let max = -1;
    for(let i = 0; i < arr.length - 1; ++i) {
        let count = 0;
        for(let j = i + 1; j < arr.length; ++j){
            if(arr1.indexOf(arr[i]) === -1 && arr[i] === arr[j]) {
                count++
            }
        }
        arr1.push(arr[i]);
        if(max < count) {
            max = count;
            res = arr[i];
        }
    }
    return res
}

// =============================Task__95=======================================
const array_element_replace = function(arr, old_value, new_value) {
    for (let i = 0; i < arr.length; ++i) {
        if(arr[i] === old_value) {
            arr[i] = new_value;
        }
    }

    return arr;
}

// =============================Task__96=======================================
function sum_adjacent_difference(arr) {
    let result = 0;
    for (let i = 1; i < arr.length; ++i) {
        result += Math.abs(arr[i] - arr[i - 1]);
    }

    return result;
}

// =============================Task__97=======================================
const build_Palindrome = function(str) {
    let dict = new Map();

    for(let i = 0; i < str.length; ++i){
        if(str.indexOf(str[i], i + 1) !== -1) {
            dict.set(i, str[i]);
            dict.set(str.indexOf(str[i], i + 1), str[i]);
        } else {
            dict.set(i, str[i]);
        }
    }

    let prev = {
        key : '',
        val : ''
    };
    let index = -1;
    let arr = [];
    for (let [key, value] of dict) {
        if(prev.val == value) {
            arr.push(key - prev.key);
            if(index === -1) {
                index = prev.key;
            }
        }

        prev.key = key;
        prev.val = value
    }

    flag = false;
    for(let i = 0; i < arr.length - 1; ++i) {
        if(arr[i] < arr[i + 1]) {
            flag = true;
            break;
        }
    }

    if(arr.length === 0 || flag) {
        return str + stringReverse(str);
    } else if(arr.length !== Math.floor(str.length/2)) {e
        return str + stringReverse(str.substring(0, index));
    }

    return str;
}

// =============================Task__98=======================================
const change_case =function(str) {
    let numUpperCase = 0;
    let numLowerCase = 0;

    for (var i = 0; i < str.length; i++) {
        if (/[A-Z]/.test(str[i])) {
            numUpperCase++;
        } else {
            y++;
        }
    }

    if (numLowerCase > numUpperCase) {
        return str.toLowerCase();
    }

    return str.toUpperCase();
}

// =============================Task__99=======================================
const rearrangement_characters =function(str1, str2) {
    let firstSymbols = str1.split('');
    let secondSymbols = str2.split('');
    let result = true;

    firstSymbols.sort();
    secondSymbols.sort();

    for (let i = 0; i < Math.max(firstSymbols.length, secondSymbols.length); ++i) {
        if(firstSymbols[i] !== secondSymbols[i]) {
            result = false;
        }
    }

    return result;
}

// =============================Task__100=======================================
const check_common_element = function(arra1, arra2) {
    for (let i = 0; i < arra1.length; ++i) {
        if(arra2.indexOf(arra1[i]) != -1) {
            return true;
        }
    }

    return false;
}

// =============================Task__101=======================================
const test_string = function(str) {
    const is_lower_case = function(symbol) {
        if('a' <= symbol && symbol <= 'z') {
            return true;
        }

        return false;
    }

    const is_upper_case = function(symbol) {
        if ('A' <= symbol && symbol <= 'Z') {
            return true;
        }
        return false;
    }

    let upperCaseCount = 0;

    for(let i = 0; i < str.length; ++i) {
        if(is_upper_case(str[i])) {
            ++upperCaseCount;
        } else if(is_lower_case(str[i])) {
            upperCaseCount = 0;
        } else {
            return false;
        }

        if(upperCaseCount == 2) {
            return false;
        }
    }

    return true;
}

// =============================Task__102=======================================
const number_of_InversionsNaive = function(arr) {
    let count = 0;
    for(let i = 0; i < arr.length; ++i) {
        for(let j = i + 1; j < arr.length; ++j) {
            if(arr[i] > arr[j]) {
                ++count;
            }
        }
    }

    return count;
}

// =============================Task__103=======================================
const digit_delete = function(num) {
    let result = 0;
    const digits = [];
    while (num) {
        digits.push(num % 10);
        num = Math.floor(num / 10);
    }

    for (let i = 0; i < digits.length; ++i) {
        let n = 0;
        for (let j = digits.length - 1; j >= 0; --j) {
            if (j !== i) {
                n = n * 10 + digits[j];
            }
        }
        result = Math.max(n, result);
    }
    return result;
}

// =============================Task__104=======================================
const different_values = function(ara, n) {
    let max = -1;
    for (let i = 0; i < ara.length; ++i) {
        for (let j = i + 1; j < ara.length; ++j) {
            let diff = Math.abs(ara[i] - ara[j]);
            if (diff <= n) {
                max = Math.max(max, diff);
            }
        }
    }

    return max;
}

// =============================Task__105=======================================
const digit_to_one = function(num) {
    const digitSum = function(num) {
        let digit_sum = 0;
        while (num) {
            digit_sum += num % 10;
            num = Math.floor(num / 10);
        }

        return digit_sum;
    };

    let result = 0;

    while (num >= 10) {
        ++result;
        num = digitSum(num);
    }

    return result;
}

// =============================Task__106=======================================
const divide_digit = function(num, d) {
    if(d === 1) {
        return num;
    } else {
        while(num % d === 0) {
            num /= d;
        }

        return num;
    }
}

// =============================Task__107=======================================
const arr_pairs = function(arr) {
    let result = 0;
    for(let i = 0; i < arr.length; ++i) {
        for(let j = i + 1; j < arr.length; ++j) {
            if(arr[i] % arr[j] === 0 || arr[j] % arr[i] === 0) {
                result++;
            }
        }
    }

    return result;
}

// =============================Task__108=======================================
const dot_product = function (vector1, vector2) {
    if(vector1.length > 3 || vector2.length > 3) {
        return false;
    }

    let result = 0;
    for (let i = 0; i < 3; ++i) {
        result += vector1[i] * vector2[i];
    }

    return result;
}

// =============================Task__109=======================================
const sort_prime = function(num) {
    let prime_num1 = [];
    let prime_num2 = [];
    for (let i = 0; i <= num; ++i) {
      prime_num2.push(true);
    }

    for (let i = 2; i <= num; ++i) {
        if(prime_num2[i]) {
            prime_num1.push(i);
            for(let j = 1; i * j <= num; ++j) {
                prime_num2[i * j] = false;
            }
        }
    }

    return prime_num1;
}

// =============================Task__110=======================================
const find_numbers = function(arr, num) {
    let result = 0;
    for (let i = 0; i < arr.length; ++i) {
        if (arr[i] % 2 === 0 && arr[i] !== num) {
            result++;
        }
        if (arr[i] === num) {
            return result;
        }
    }

    return -1;
}