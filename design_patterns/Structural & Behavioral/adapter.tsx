var convert = require("xml-js");

class Lib {
  json: string;
  setJson(data: string) {
    this.json = data;
  }

  stringify() {
    try {
      const data = JSON.stringify(this.json);
      console.log(data);
    } catch (error) {
      console.log("Error not valid json");
    }
  }

  parse() {
    try {
      const parsedData = JSON.parse(this.json);
      console.log(parsedData);
    } catch (error) {
      console.log("Error not valid json");
    }
  }
}

class XML {
  xml: string;
  setXML(data: string) {
    this.xml = data;
  }

  print() {
    console.log("This is XML data" + this.xml);
  }
}

class Json {
  json: Object;
  setJson(data: Object) {
    this.json = data;
  }

  print() {
    console.log("This is XML data" + this.json);
  }
}

class XMLToJSON extends Json {
  data: string;
  constructor(data: string) {
    super();
    this.data = data;
  }

  toJson() {
    return convert.xml2json(this.data, {
      compact: true,
      spaces: 4,
      ignoreDeclaration: true,
    });
  }
}

function main() {
  const exampleData =
    '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    "    <title>Happy</title>" +
    "    <todo>Work</todo>" +
    "    <todo>Play</todo>" +
    "</note>";
  const lib = new Lib();

  lib.setJson(exampleData);
  lib.parse();

  const adapter = new XMLToJSON(exampleData);
  console.log("\nAdapter\n");
  lib.setJson(adapter.toJson());
  lib.parse();
}

main();
