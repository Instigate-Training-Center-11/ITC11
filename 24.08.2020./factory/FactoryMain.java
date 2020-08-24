package factory;

public class FactoryMain {
    public static void main(String[] args) {
        CarFactory carFactory = new CarFactory();

        Car car1 = carFactory.getCar("Truck");
        car1.typeOfMoving();

        Car car2 = carFactory.getCar("Ship");
        car2.typeOfMoving();

    }
}
