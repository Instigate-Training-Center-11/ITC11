package adapter;

public class XML {
    private String doc;

    public String getDoc() {
        return doc;
    }

    public void setDoc(String doc) {
        this.doc = doc;
    }

    @Override
    public String toString() {
        return "XML{" +
                "doc='" + doc + '\'' +
                '}';
    }
}
