package factory;

public class CarFactory {
    public Car getCar (String carType) {
        if (carType == null){
            return null;
        }
        if (carType == "Truck"){
            return new Truck();
        }
        else if (carType == "Ship"){
            return new Ship();
        }
        return null;
    }
}
