package adapter;

public class DownloadDependencies {
    public void download(Json json) {
        System.out.println("Downloading dependencies " + json.getJson());
    }
}
