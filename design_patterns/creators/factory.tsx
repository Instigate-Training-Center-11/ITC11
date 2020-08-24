interface ICar {
  drive(): string;
}

class Car1 implements ICar {
  drive(): string {
    return "Car1 drive function";
  }
}

class Car2 implements ICar {
  drive(): string {
    return "Car2 drive function";
  }
}

abstract class Creator {
  public abstract createCar(): ICar;

  public anOperation(): string {
    const car = this.createCar();
    return car.drive();
  }
}

class ConcreteCarCreator1 extends Creator {
  public createCar(): ICar {
    return new Car1();
  }
}

class ConcreteCarCreator2 extends Creator {
  public createCar(): ICar {
    return new Car2();
  }
}

function initialize(creator: Creator) {
  console.log(creator.anOperation());
}

function main() {
  initialize(new ConcreteCarCreator1());
  initialize(new ConcreteCarCreator2());
}

main();
