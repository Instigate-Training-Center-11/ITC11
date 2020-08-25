package adapter;



public class Main {
    public static void main(String[] args) {
        XML xml = new XML();
        Json json = new XMLToJson(xml).getJson();
        DownloadDependencies dependencies = new DownloadDependencies();
        dependencies.download(json);
    }
}
