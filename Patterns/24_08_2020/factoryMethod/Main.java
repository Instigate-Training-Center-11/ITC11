package factoryMethod;

import factoryMethod.creator.AudiCreator;
import factoryMethod.creator.BentleyCreator;
import factoryMethod.creator.CarCreator;
import factoryMethod.creator.FerrariCreator;

public class Main {
    public static void main(String[] args) {
        CarCreator carCreators [] = {new BentleyCreator(), new FerrariCreator(), new AudiCreator()};
        for(CarCreator carCreator: carCreators) {
            System.out.print("Created new ");
            System.out.println(carCreator.factoryMethod());
        }
    }
}
