package factory;

public class Truck implements Car{
    @Override
    public void typeOfMoving() {
        System.out.println("Truck moves with weels.");
    }
}
