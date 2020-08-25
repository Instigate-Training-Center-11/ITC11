package adapter;

public class TextAdapter implements TextReader {

    JsonReader jsonReader;

    public TextAdapter(String textType){
        jsonReader = new JsonReader();
    }

    @Override
    public void toread(String audioType, String fileName) {
        if(audioType == "json"){
            jsonReader.readJson(fileName);
        }
    }
}
