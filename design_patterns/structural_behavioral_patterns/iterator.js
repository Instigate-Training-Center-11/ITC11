class SumIterator {
    constructor(setArray) {
        this.array = setArray;
        this.index = 0;
    }

    next() {
        return this.array[this.index++];
    }

    isNext() {
        return this.index < this.array.length;
    }

    act() {
        let sum = 0;
        for(;;) {
            if(this.isNext()) {
                sum += this.next();
            } else {
                break;
            }
        }

        return sum;
    }

    print() {
        console.log('Sum is', this.act())
    }
}

class MulIterator extends SumIterator {
    constructor(array) {
        super(array);
    }

    act() {
        let multiple = 1;
        for(;;) {
            if(this.isNext()) {
                multiple *= this.next();
            } else {
                break;
            }
        }

        return multiple;
    }

    print() {
        console.log('Multiple is', this.act())
    }
}

let array = [5, 10, 15, 20];
let itom1 = new SumIterator(array);
let itom2 = new MulIterator(array);
itom1.print();
itom2.print();