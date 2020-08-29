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

function initialize(type: string) {
  if (type === "car1") {
    return new ConcreteCarCreator1();
  } else if (type === "car2") {
    return new ConcreteCarCreator2();
  }
}

function main() {
  const carFactory = initialize("car1");
  const car = carFactory.anOperation();
  console.log(car);
}

main();
