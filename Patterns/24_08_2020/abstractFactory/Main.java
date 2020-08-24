package abstractFactory;

import abstractFactory.furnitureFactory.ArtDecoFurnitureFactory;
import abstractFactory.furnitureFactory.FurnitureFactory;
import abstractFactory.furnitureFactory.ModernFurnitureFactory;
import abstractFactory.furnitureFactory.VictorianFurnitureFactory;

public class Main {
    public static void main(String[] args) {
        FurnitureFactory furnitureFactory1 = new VictorianFurnitureFactory();
        FurnitureFactory furnitureFactory2 = new ModernFurnitureFactory();
        FurnitureFactory furnitureFactory3 = new ArtDecoFurnitureFactory();
        Client client1 = new Client(furnitureFactory1);
        Client client2 = new Client(furnitureFactory2);
        Client client3 = new Client(furnitureFactory3);
        System.out.println(client1.toString());
        System.out.println(client2.toString());
        System.out.println(client3.toString());
    }
}
