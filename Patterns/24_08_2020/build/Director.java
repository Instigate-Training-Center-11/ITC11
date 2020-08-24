package build;

public class Director {
    private PizzaBuilder pizzaBuilder;

    public PizzaBuilder getPizzaBuilder() {
        return pizzaBuilder;
    }

    public void setPizzaBuilder(PizzaBuilder pizzaBuilder) {
        this.pizzaBuilder = pizzaBuilder;
    }

    public void constructPizza() {
        pizzaBuilder.createNewPizzaProduct();
        pizzaBuilder.buildCheese();
        pizzaBuilder.buildSauce();
        pizzaBuilder.buildHam();
        pizzaBuilder.buildMushRooms();
        pizzaBuilder.buildSize();
    }
}
