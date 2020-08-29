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

  private asdf(): void {
    console.log("asdf");
  }

  fdsa() {
    this.asdf();
  }

  constructor(color: string) {
    super();
    this.color = color;
  }

  public clone(): Prototype {
    var cloned = Object.create(Prototype.prototype || null);
    Object.keys(this).map((key: string) => {
      cloned[key] = this[key];
    });

    return cloned;
  }
}

function main() {
  const ceil = new Prototype("green");
  const ceilClone = ceil.clone();
  console.log(ceil);
  console.log(ceilClone);
  ceil.fdsa();
  ceilClone.fdsa();
}

main();
