package prototype;

import java.util.List;

public class PrototypeMain {
    public static void main(String[] args) throws CloneNotSupportedException {
        Cells cell = new Cells();
        cell.addData();

        /*I am using the clone method to get the cells object */
        Cells cellNew = (Cells) cell.clone();
        Cells cellNew1 = (Cells) cell.clone();
        List<String> list = cellNew.getCellList();
        list.add("Five");
        List<String> list1 = cellNew1.getCellList();


        System.out.println("cells List: "+cell.getCellList());
        System.out.println("cellsNew List: "+list);
        System.out.println("cellsNew1 List: "+list1);
    }
}
