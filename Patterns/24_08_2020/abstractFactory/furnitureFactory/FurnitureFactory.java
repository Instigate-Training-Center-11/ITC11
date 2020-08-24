package abstractFactory.furnitureFactory;

import abstractFactory.products.Chair;
import abstractFactory.products.CoffeeTable;
import abstractFactory.products.Sofa;

public interface FurnitureFactory {
    Chair createChair();
    CoffeeTable createCoffeeTable();
    Sofa createSofa();
}
