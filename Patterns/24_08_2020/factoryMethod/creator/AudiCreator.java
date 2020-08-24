package factoryMethod.creator;

import factoryMethod.cars.Car;
import factoryMethod.cars.Audi;

public class AudiCreator extends CarCreator {
    @Override
    public Car factoryMethod() {
        return new Audi();
    }
}
