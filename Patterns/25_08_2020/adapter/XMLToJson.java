package adapter;

public class XMLToJson {
    private Json json;

    public XMLToJson(XML xml) {
        this.json = new Json();
        json.setJson(xml.toString() + ":");
    }

    public Json getJson() {
        return json;
    }

    public void setJson(Json json) {
        this.json = json;
    }
}
