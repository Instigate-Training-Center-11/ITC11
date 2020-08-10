/*1. Write a JavaScript program to display the current day and time in the following format.
    Sample Output : Today is : Tuesday.
    Current time is : 10 PM : 30 : 38*/
console.log("Today is: " + new Date().toString().split(' ')[0] + '\n' +
    "Current time is: " + new Date().toString().split(' ')[4]);

/*2. Write a JavaScript program to print the contents of the current window.*/

//TODO <button onclick="printCurrentPage()">Print</button>
function printCurrentPage() {
        window.print();
}

/*3. Write a JavaScript program to get the current date.  Expected Output :
    mm-dd-yyyy, mm/dd/yyyy or dd-mm-yyyy, dd/mm/yyyy*/
let date = new Date();
let splitDate = date.toString().split(' ');
console.log(date.getMonth() + '-' + splitDate[2] + '-' + splitDate[3]);
console.log(date.getMonth() + '/' + splitDate[2] + '/' + splitDate[3]);

/*4. Write a JavaScript program to find the area of a triangle where lengths of the three of its sides are 5, 6, 7.*/
function area(a, b, c) {
    let p = (a + b + c) / 2;
    return  (Math.sqrt(p * (p - a) * (p - b) * (p -c)));
}
console.log(area(5, 6, 7));

/*5. Write a JavaScript program to rotate the string 'w3resource' in right direction by periodically removing one letter from the end of the string and attaching it to the front.*/
let word = "w3resource";
let len = word.length;
let temp = "";
for(let i = 0; i < len; ++i) {
    temp += word[len - 1 - i];
}
console.log(temp);
/*6. Write a JavaScript program to determine whether a given year is a leap year in the Gregorian calendar.*/
let  isLeapYear = (y) => (y - 2020) % 4 === 0;
console.log(isLeapYear(2024));
console.log(isLeapYear(2017));

/*7. Write a JavaScript program to find 1st January is being a Sunday between 2014 and 2050.*/
for(let i = 2014; i < 2050; ++i) {
    if(new  Date(i, 0).getDay() === 0) {
        console.log(i);
    }
}
/*8. Write a JavaScript program where the program takes a random integer between 1 to 10, the user is then prompted to input a guess number. If the user input matches with guess number, the program will display a message "Good Work" otherwise display a message "Not matched".*/

/*<input type="number" id="myText" min="0" max="10">
    <button onclick="myFunction()">Try it</button>
<p id="demo"></p>*/

    function myFunction() {
        let number = document.getElementById("myText").value;
        let guessNumber = (n) => n === 5;
        document.getElementById("demo").innerHTML = guessNumber(parseInt(number));
    }

/*9. Write a JavaScript program to calculate days left until next Christmas.*/
/*let datee = new Date();
console.log(((datee.toString().split(' ')[3], 12, 31) - datee));*/

/*10. Write a JavaScript program to calculate multiplication and division of two numbers (input from user).*/
let multiplication = (a, b) => a * b;
let div = (a, b) =>  a / b;
let f = (str) => {
    let mult =str.toString().split('*');
    let di = str.toString().split('/');
    return di[1] !== undefined ? div(di[0], di[1]) : multiplication(mult[0], mult[1]);
};
console.log(f('54/5'));

/*11. Write a JavaScript program to convert temperatures to and from Celsius, Fahrenheit.

    [ Formula : c/5 = (f-32)/9 [ where c = temperature in Celsius and f = temperature in Fahrenheit ]
Expected Output :
    60°C is 140 °F
45°F is 7.222222222222222°C*/
let celsius = (far) => 5 * ((far - 32) / 9);
console.log("45 F is " + celsius(45) + " C" );

/*12. Write a JavaScript program to get the website URL (loading page).*/
/*
* <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>Get Current URL in JavaScript</title>
</head>
<body>
<script>*/
    function getURL() {
        alert("The URL of this page is: " + window.location.href);
    }
/*</script>

<button type="button" onclick="getURL();">Get Page URL</button>
</body>
</html>*/

/*13. Write a JavaScript exercise to create a variable using a user-defined name.*/
let createVariable = (name, value) => {
    return {
        name: value
    }
};
console.log(createVariable("my", 7));

/*14. Write a JavaScript exercise to get the extension of a filename.*/

/*15. Write a JavaScript program to get the difference between a given number and 13, if the number is greater than 13 return double the absolute difference.*/
let diff = (num) => num > 13 ? (num - 13) * 2 : (13 - num);
console.log(diff(15));
console.log(diff(10));

/*16. Write a JavaScript program to compute the sum of the two given integers. If the two values are same, then returns triple their sum.*/
let summm = (a, b) => a === b ? 6 * a : (a + b);

/*17. Write a JavaScript program to compute the absolute difference between a specified number and 19. Returns triple their absolute difference if the specified number is greater than 19.*/
let difff = (n) => n <= 19 ? 19 - n : 3 * (n - 19);

/*18. Write a JavaScript program to check two given numbers and return true if one of the number is 50 or if their sum is 50.*/
let b = (a, b) => a === 50 || b === 50 || (a + b) === 50;
console.log(b(5, 50))

/*19. Write a JavaScript program to check whether a given integer is within 20 of 100 or 400.*/
let checkWithin = (n) => (n >= 20 && n <=100) || n ===400;
console.log(checkWithin(200));
console.log(checkWithin(90));
console.log(checkWithin(400));

/*20. Write a JavaScript program to check from two given integers, whether one is positive and another one is negative.*/
let ch = (a, b) => (a >= 0 && b < 0) || (b >= 0 && a < 0);
console.log(ch(5, -1));
console.log(ch(5, 1));

/*21. Write a JavaScript program to create a new string adding "Py" in front of a given string. If the given string begins with "Py" then return the original string.*/
let addPy = (s) => s[0] === 'p' && s[1] === 'y' ? s : "py" + s;
console.log(addPy("pyu"));
console.log(addPy("dadu"));

/*22. Write a JavaScript program to remove a character at the specified position of a given string and return the new string.*/
let rmCh = (s, pos) => s.slice(0, pos) + s.slice(pos + 1);
console.log(rmCh("kliop", 1));

/*23. Write a JavaScript program to create a new string from a given string changing the position of first and last characters. The string length must be greater than or equal to 1.*/
let changeCh = (s) => s.length ===1 ? s : s[s.length - 1] + s.slice(1, s.length - 1) + s[0];
console.log(changeCh("klor"));
console.log(changeCh("k"));

/*24. Write a JavaScript program to create a new string from a given string with the first character of the given string added at the front and back.*/
let addFirstEnd = (s) => s[0] + s + s[0];
console.log(addFirstEnd("sc"));

/*25. Write a JavaScript program to check whether a given positive number is a multiple of 3 or a multiple of 7.*/
let checkNum = (n) => (n % 3) === 0 && (n % 7) === 0;
console.log(checkNum(21));

/*26. Write a JavaScript program to create a new string from a given string taking the last 3 characters and added at both the front and back. The string length must be 3 or more.*/
let addSim = (s) => s.length <= 3 ? s : s.slice(s.length - 4, s.length - 1) + s + s.slice(s.length - 4, s.length - 1);
console.log(addSim("frfr"));
console.log(addSim("fr"));

/*27. Write a JavaScript program to check whether a string starts with 'Java' and false otherwise.*/
let isStartsJava = (s) => s.toString().startsWith("Java");
console.log(isStartsJava("Javajkbn"));

/*28. Write a JavaScript program to check whether two given integer values are in the range 50..99 (inclusive). Return true if either of them are in the said range.*/
let checkRange = (a, b) => (a > 50 && a < 99) || (b > 50 && b < 99);
console.log(checkRange(5, 78));
console.log(checkRange(5, 3));

/*29. Write a JavaScript program to check whether three given integer values are in the range 50..99 (inclusive). Return true if one or more of them are in the said range.*/
let checkRangeForTree = (a, b, c) => (a > 50 && a < 99) || (b > 50 && b < 99) || (c > 50 && c < 99);

/*30. Write a JavaScript program to check whether a string "Script" presents at 5th (index 4) position in a given string, if "Script" presents in the string return the string without "Script" otherwise return the original one.*/
let isPresentStr = (s) => s.slice(5, s.length).includes("Script") ? s.slice(0, 5) + s.slice(11, s.length) : s;
console.log(isPresentStr("Java Script lol"));

/*31. Write a JavaScript program to find the largest of three given integers.*/
let largest = (a, b, c) => (a > b) && (a > c) ? a : (b > c) && (b > a) ? b : c;
console.log(largest(1, 2, 3));
console.log(largest(1, 3, 2));
console.log(largest(3, 1, 2));

/*32. Write a JavaScript program to find a value which is nearest to 100 from two different given integer values.*/
let neaner = (a, b) => Math.abs(a - 100) > Math.abs(b - 100) ? b : a;
console.log(neaner(95, 104));

/*33. Write a JavaScript program to check whether two numbers are in range 40..60 or in the range 70..100 inclusive.*/
let between = (a, b) => ((a > 40 && a < 60) || (a > 70 && a < 100)) || ((b > 40 && b < 60) || (b > 70 && b < 100));
console.log(between(41, 71));
console.log(between(41, 101));
console.log(between(39, 101));

/*34. Write a JavaScript program to find the larger number from the two given positive integers, the two numbers are in the range 40..60 inclusive.*/
let larger = (a, b) => a > b ? a : b;
console.log(larger(24, 47));

/*35. Write a program to check whether a specified character exists within the 2nd to 4th position in a given string.*/
let posit = (ch, s) => s[1] === ch || s[3] === ch;
console.log(posit('a', "barth"))
console.log(posit('a', "bsasrth"))
console.log(posit('a', "bsaarth"))

/*36. Write a JavaScript program to check whether the last digit of the three given positive integers is same.*/
let lastDigit = (a, b, c) => a % 10 === b % 10 && a % 10 === c % 10;
console.log(lastDigit(54, 64, 14));
console.log(lastDigit(55555, 64, 14));

/*37. Write a JavaScript program to create new string with first 3 characters are in lower case from a given string. If the string length is less than 3 convert all the characters in upper case.*/
let toLower = (s) => s.length < 3 ? s.toUpperCase() : s.slice(0, 3).toLowerCase() + s.slice(3, s.length);
console.log(toLower("hj"));
console.log(toLower("KLOjknkj"));

/*38. Write a JavaScript program to check the total marks of a student in various examinations. The student will get A+ grade if the total marks are in the range 89..100 inclusive, if the examination is "Final-exam." the student will get A+ grade and total marks must be greater than or equal to 90. Return true if the student get A+ grade or false otherwise.*/
let isFinalExam = true;
let isAPlus = (booll, total) => (total >= 89 && total <= 100 && booll) || (total >= 90);
console.log(isAPlus(isFinalExam, 70));
console.log(isAPlus(isFinalExam, 89));
console.log(isAPlus(false, 90));

/*39. Write a JavaScript program to compute the sum of the two given integers, If the sum is in the range 50..80 return 65 other wise return 80.*/
let isInRange = (a, b) => (a + b) > 50 && (a + b) < 80 ? 65 : 80;
console.log(isInRange(25, 30));
console.log(isInRange(15, 30));

/*40. Write a JavaScript program to check from two given integers whether one of them is 8 or their sum or difference is 8.*/
let isEight = (a, b) => a === 8 || b === 8 || Math.abs(a - b) === 8 || a + b === 8;
console.log(isEight(8, 0));
console.log(isEight(9, 1));
console.log(isEight(9, 2));

/*41. Write a JavaScript program to check three given numbers, if the three numbers are same return 30 otherwise return 20 and if two numbers are same return 40.*/
let checkThreeNumbers = (a, b, c) => (a ===b && a === c) ? 30 : (a === b || b === c || a === c) ? 40 : 20;
console.log(checkThreeNumbers(10, 20, 10));
console.log(checkThreeNumbers(10, 10, 10));
console.log(checkThreeNumbers(10, 20, 30));

/*42. Write a JavaScript program to check whether three given numbers are increasing in strict mode or in soft mode.

    Note: Strict mode -> 10, 15, 31 : Soft mode -> 24, 22, 31 or 22, 22, 31*/
let checkStrict = (a, b, c) => (c - b) > (b - a);
console.log(checkStrict(10, 15, 31));
