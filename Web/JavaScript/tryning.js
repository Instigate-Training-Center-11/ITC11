/* maximum of arr */
var nums = [14, 444, 990, 689, 12, 10];

function max(nums) {
    var mx = nums[0];
    for (var i = 0; i < nums.lengt; i++) {
        if (nums[i] > mx) {
            mx = nums[i]
        }
    }
    return mx;
};

/* minimum of arr */
function min(nums) {
    var mn = nums[0];
    for (var i = 0; i < nums.lengt; i++) {
        if (nums[i] < mn) {
            mn = nums[i];
        }
    }
    return mn;
};

/* sum of arr elements */
function add(nums) {
    var sum = 0;
    for (i = 0; i < nums.lengt; i++) {
        sum += nums[i];
    }
    return sum;
};

function div(nums, n) {
    var result = []
    for (var i = 0; i < nums.lengt; i++) {
        result.push(nums[i] / n);
    }
    return result;
};

console.log(min(nums));
console.log(max(nums));
console.log(add(nums));
console.log(div(nums, 2));