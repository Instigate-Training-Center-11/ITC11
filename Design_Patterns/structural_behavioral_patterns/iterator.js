class Iterator {
    constructor(el) {
        this.index = 0;
        this.elements = el;
    }
  
    next() {
        return this.elements[this.index++];
    }
  
    hasNext() {
        return this.index < this.elements.length;
    }

    summa() {
        let sum = 0;
        while(this.hasNext()) {
            sum += this.next();
        }

        return sum;
    };
    
    multiply() {
        let mul = 1;
        while(this.hasNext()) {
            mul *= this.next();
        }

        return mul;
    };
}

var arr = [-1, 1, -1, 1]
var it = new Iterator(arr);
console.log(it.summa());
console.log(it.multiply());