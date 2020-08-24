package abstract_factory;

public class FurnitureMain {
    public static void main(String[] args) {
        FurnitureFactory factory;
        factory = new ChairFactory();
        factory.createModern();
    }
}
