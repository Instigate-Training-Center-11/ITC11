package adapter;


import org.json.XML;

public class XMLToJson {
    private Json json;

    public XMLToJson(XML xml) {
        this.json = new Json();
        json.setJson(XML.toJsonObject(xml.getDoc()));
    }

    public Json getJson() {
        return json;
    }

    public void setJson(Json json) {
        this.json = json;
    }
}
