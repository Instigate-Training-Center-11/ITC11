class Json {
    toJson(jsonData) {
        console.log(jsonData);
    }
    print() {
        console.log('json format');
    }
}

class Xml {
    toXml(xmlData) {
        console.log(xmlData);
    }
    print() {
        console.log('xml format');
    }
}

class Adapter extends Json {
    constructor(xml) {
        super();
        this.xml = xml;
    }
    toJson(xmlData) {
        return this.xml.toXml(xmlData);
    }
}

let xml = new Xml();
let adapter = new Adapter(xml);
adapter.print();
adapter.toJson('XML to JSON');