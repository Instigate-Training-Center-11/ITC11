package iterator;

public class IteratorMain {
    public static void main(String[] args) {
        Numbers num = new Numbers();

        Integer sum = 0;
        Integer mult = 1;
        for(Iterator iter = num.getIterator(); iter.hasNext();){
            Integer integer = (Integer) iter.next();
            sum += integer;
        }
        for(Iterator iter = num.getIterator(); iter.hasNext();){
            Integer integer = (Integer) iter.next();
            mult *= integer;
        }
        System.out.println("Summary of elements is: " + sum);
        System.out.println("Multiplication of elements is: " + mult);
    }
}
