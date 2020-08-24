interface IBuilder {
  size(n: Number): Number;
  cheese(): string;
  sauce(): void;
  pepperoni(val: boolean): boolean;
  olives(val: boolean): boolean;
  mushrooms(val: boolean): boolean;
  reset(): void;
}

class ConcretPizzaBuilder implements IBuilder {
  pizza: Pizza1;
  reset(): void {
    this.pizza = new Pizza1();
  }
  size(n: Number): Number {
    return n;
  }
  cheese(): string {
    return "ConcretPizzaBuilder cheese";
  }
  sauce(): void {
    console.log("ConcretPizzaBuilder sauce");
  }
  pepperoni(val: boolean): boolean {
    return val;
  }
  olives(val: boolean): boolean {
    return val;
  }
  mushrooms(val: boolean): boolean {
    return val;
  }
  getResult() {
    this.reset();
    return this.pizza;
  }
}

class Pizza1 {
  sayHi() {
    console.log("Pizza1 ");
  }
}

class Pizza2 {
  sayHi() {
    console.log("Pizza2 ");
  }
}

class Director {
  builder: IBuilder;
  public setBuilder(builder: IBuilder): void {
    this.builder = builder;
  }

  public buildMinimalPizza(): void {
    this.builder.size(4);
    this.builder.cheese();
  }

  public buildFullPizza(): void {
    this.builder.size(8);
    this.builder.sauce();
    this.builder.cheese();
    this.builder.mushrooms(true);
  }
}

function clientCode(director: Director) {
  const builder = new ConcretPizzaBuilder();
  director.setBuilder(builder);

  console.log("Standard basic pizza:");
  director.buildMinimalPizza();
  builder.getResult().sayHi();

  console.log("Standard full pizza:");
  director.buildFullPizza();
  builder.getResult().sayHi();

  console.log("Custom product:");
  builder.size(6);
  builder.cheese();
  builder.getResult().sayHi();
}

const director = new Director();
clientCode(director);
