interface IChair {
  hasLegs(): boolean;
  sitOn(): void;
}

interface ISofa {
  hasLegs(): boolean;
  sitOn(): void;
}

class ModernChair implements IChair {
  hasLegs(): boolean {
    return false;
  }
  sitOn(): void {
    console.log("ModernChair sitOn function");
  }
}

class ModernSofa implements IChair {
  hasLegs(): boolean {
    return false;
  }
  sitOn(): void {
    console.log("ModernSofa sitOn function");
  }
}

class VictorianChair implements IChair {
  hasLegs(): boolean {
    return true;
  }
  sitOn(): void {
    console.log("VictorianChair sitOn function");
  }
}

class VictorianSofa implements IChair {
  hasLegs(): boolean {
    return false;
  }
  sitOn(): void {
    console.log("VictorianSofa sitOn function");
  }
}

interface FurnitureFactory {
  createChair(): IChair;
  createSofa(): ISofa;
}

class ModernFurnitureFactort implements FurnitureFactory {
  createChair(): IChair {
    return new ModernChair();
  }
  createSofa(): ISofa {
    return new ModernSofa();
  }
}

class VictorianFurnitureFactort implements FurnitureFactory {
  createChair(): IChair {
    return new VictorianChair();
  }
  createSofa(): ISofa {
    return new VictorianSofa();
  }
}

function clientCode(factory: FurnitureFactory) {
  const chair = factory.createChair();
  const sofa = factory.createSofa();

  chair.sitOn();
  sofa.sitOn();
}

function main() {
  console.log("Modern\n");
  clientCode(new ModernFurnitureFactort());
  console.log("\nVictorian\n");
  clientCode(new VictorianFurnitureFactort());
}

main();
