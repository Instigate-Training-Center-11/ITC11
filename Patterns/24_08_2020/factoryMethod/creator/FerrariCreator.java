package factoryMethod.creator;

import factoryMethod.cars.Car;
import factoryMethod.cars.Ferrari;

public class FerrariCreator  extends CarCreator {
    @Override
    public Car factoryMethod() {
        return new Ferrari();
    }
}
