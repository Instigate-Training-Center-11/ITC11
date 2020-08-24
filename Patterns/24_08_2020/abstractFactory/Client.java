package abstractFactory;

import abstractFactory.furnitureFactory.FurnitureFactory;
import abstractFactory.products.Chair;
import abstractFactory.products.CoffeeTable;
import abstractFactory.products.Sofa;

public class Client {
    private Chair chair;
    private CoffeeTable coffeeTable;
    private Sofa sofa;
    Client(FurnitureFactory furnitureFactory) {
        chair = furnitureFactory.createChair();
        coffeeTable = furnitureFactory.createCoffeeTable();
        sofa = furnitureFactory.createSofa();
    }

    @Override
    public String toString() {
        return "Client{" +
                "chair=" + chair +
                ", coffeeTable=" + coffeeTable +
                ", sofa=" + sofa +
                '}';
    }
}
