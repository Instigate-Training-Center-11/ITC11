abstract class Ceil {
  color: string;
  height: number;
  width: number;

  constructor() {
    this.color = "red";
    this.height = 100;
    this.width = 200;
  }

  abstract clone(): Ceil;
}

class Prototype extends Ceil {
  color: string;

  constructor(color: string) {
    super();
    this.color = color;
  }

  clone(): Prototype {
    return { ...this };
  }
}

function main() {
  const ceil = new Prototype("green");
  const ceilClone = ceil.clone();
  console.log(ceil);
  console.log(ceilClone);
}

main();
