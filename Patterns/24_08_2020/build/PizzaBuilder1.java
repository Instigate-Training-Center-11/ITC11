package build;

public class PizzaBuilder1 extends PizzaBuilder{
    @Override
    public void buildSize() {
        pizza.setSize("size1");
    }

    @Override
    public void buildCheese() {
        pizza.setCheese("cheese1");
    }

    @Override
    public void buildHam() {
        pizza.setHam("ham1");
    }

    @Override
    public void buildSauce() {
        pizza.setSauce("sauce1");
    }

    @Override
    public void buildMushRooms() {
        pizza.setMushrooms("mushRoom1");
    }
}
