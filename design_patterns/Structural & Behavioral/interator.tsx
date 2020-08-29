interface MyIterator {
  next(): number;
  hasNext(): boolean;
  sum(): number;
  mult(): number;
}

interface IterableCollection {
  createIterator(): MyIterator;
}

class ConcretIterator implements MyIterator {
  collection: MyCollection;
  position = 0;
  constructor(arr: MyCollection) {
    this.collection = arr;
  }

  next(): number {
    const item = this.collection.getItems()[this.position];
    this.position++;
    return item;
  }

  hasNext(): boolean {
    return this.position < this.collection.getCount();
  }

  sum(): number {
    let sum = 0;
    while (this.hasNext()) {
      sum += this.next();
    }
    return sum;
  }
  mult(): number {
    let mult = 1;
    while (this.hasNext()) {
      mult *= this.next();
    }
    return mult;
  }
}

class MyCollection implements IterableCollection {
  items: number[] = [];
  createIterator(): MyIterator {
    return new ConcretIterator(this);
  }

  getItems() {
    return this.items;
  }

  addItem(item: number) {
    this.items.push(item);
  }

  getCount() {
    return this.items.length;
  }
}

function start() {
  const arr = new MyCollection();
  for (let i = 0; i < 10; i++) {
    arr.addItem(i);
  }
  const iterator = arr.createIterator();
  console.log(iterator.sum());
  console.log(iterator.mult());
}

start();
