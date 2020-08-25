class CreateJson {
    makeJson(json) {
        return json;
    }

    getJson() {
        return this.json;
    }

    setJson(newJson) {
        this.json = newJson;
    }

    printFormat() {
        console.log('Format is', this.makeJson('JSON'));
    }
}

class CreateXml {
    makeXml(xml) {
        return xml;
    }

    getXml() {
        return this.xml;
    }

    setJson(newXml) {
        this.xml = newXml;
    }

    printFormat() {
        console.log('Format is', this.makeXml('XML'));
    }
}

class Adapter extends CreateJson {
    constructor(xml) {
        super();
        this.xml = xml;
    }

    makeJson(xml) {
        return this.xml.makeXml(xml);
    }
}

let xml = new CreateXml();
let adapter = new Adapter(xml);
adapter.setJson('New json');
console.log(adapter.getJson());
adapter.printFormat();
