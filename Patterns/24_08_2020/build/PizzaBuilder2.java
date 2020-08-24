package build;

public class PizzaBuilder2 extends PizzaBuilder{
    @Override
    public void buildSize() {
        pizza.setSize("size2");
    }

    @Override
    public void buildCheese() {
        pizza.setCheese("cheese2");
    }

    @Override
    public void buildHam() {
        pizza.setHam("ham2");
    }

    @Override
    public void buildSauce() {
        pizza.setSauce("sauce2");
    }

    @Override
    public void buildMushRooms() {
        pizza.setMushrooms("mushRoom2");
    }
}
