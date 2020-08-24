package build;

abstract class PizzaBuilder {
    protected Pizza pizza;

    public Pizza getPizza() {
        return pizza;
    }
    public void createNewPizzaProduct() {
        pizza = new Pizza();
    }

    public abstract void buildSize();
    public abstract void buildCheese();
    public abstract void buildHam();
    public abstract void buildSauce();
    public abstract void buildMushRooms();
}
