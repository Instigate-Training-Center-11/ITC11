package adapter;

public class AdapterMain {
    public static void main(String[] args) {
        XMLReader xmlReader = new XMLReader();

        xmlReader.toread("xml", "people.xml");
        xmlReader.toread("json", "employer.json");
        xmlReader.toread("csv", "someone.csv");
        xmlReader.toread("png", "image.png");
        xmlReader.toread("jpg", "picture.jpg");
        xmlReader.toread("html", "index.html");

    }
}
