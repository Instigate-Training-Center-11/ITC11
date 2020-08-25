package adapter;

public class Json {
    private String json;

    public String getJson() {
        return json;
    }

    public void setJson(String json) {
        this.json = json;
    }

    @Override
    public String toString() {
        return "Json{" +
                "json='" + json + '\'' +
                '}';
    }
}
