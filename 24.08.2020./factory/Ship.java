package factory;

public class Ship implements Car{
    @Override
    public void typeOfMoving() {
        System.out.println("Ship moves in the sea.");
    }
}
