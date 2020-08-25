package adapter;

public class XMLReader implements TextReader {
    TextAdapter textAdapter;

    @Override
    public void toread(String textType, String fileName) {
        if(textType == "xml"){
            System.out.println("Reading xml file: " + fileName);
        }

        else if(textType == "json"){
            textAdapter = new TextAdapter(textType);
            textAdapter.toread(textType, fileName);
        }

        else{
            System.out.println("This format not supported: " + textType);
        }
    }
}
