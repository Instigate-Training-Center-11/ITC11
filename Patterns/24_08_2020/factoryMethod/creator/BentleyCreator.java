package factoryMethod.creator;

import factoryMethod.cars.Bentley;
import factoryMethod.cars.Car;

public class BentleyCreator extends CarCreator {
    @Override
    public Car factoryMethod() {
        return new Bentley();
    }
}
