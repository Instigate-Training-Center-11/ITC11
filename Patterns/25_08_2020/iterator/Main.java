package iterator;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        int sum = 0;
        int multiplication = 1;
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i <= 5; i++) {
            list.add(i);
        }
        Iterator<Integer> iterator1 = list.iterator();
        Iterator<Integer> iterator2 = list.iterator();
        while (iterator1.hasNext() && iterator2.hasNext()) {
            sum += iterator1.next();
            multiplication *= iterator2.next();
        }
        System.out.println("sum is: " + sum);
        System.out.println("multiplication is is: " + multiplication);
    }
}
