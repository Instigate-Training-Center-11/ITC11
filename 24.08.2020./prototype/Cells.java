package prototype;

import java.util.ArrayList;
import java.util.List;

public class Cells implements Cloneable{

    private List<String> cellsList = new ArrayList<String>();

    public Cells(List<String> list){
        this.cellsList = list;
    }

    public Cells() {
    }

    public void addData(){
        cellsList.add("One");
        cellsList.add("Two");
        cellsList.add("Thee");
        cellsList.add("Four");
    }
    public List<String> getCellList() {
        return cellsList;
    }

    @Override
    public Object clone() throws CloneNotSupportedException{
        List<String> temp = new ArrayList<String>();
        for(String s : this.getCellList()){
            temp.add(s);
        }
        return new Cells(temp);
    }
}
