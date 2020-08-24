package builder;

public class PizzaBuilder {

    Pizza pizza = new Pizza();

    public PizzaBuilder withSize(int size) {
        pizza.setSize(size);
        return this;
    }

    public PizzaBuilder withChees(int chees) {
        pizza.setCheese(chees);
        return this;
    }

    public PizzaBuilder withOlives(int olives) {
        pizza.setOlives(olives);
        return this;
    }

    public PizzaBuilder withSauce(int sauce) {

        return this;
    }

    public PizzaBuilder withMashroom(int mashroom){
        pizza.setMashroom(mashroom);
        return this;
    }

    public PizzaBuilder withPeperoni(int peperoni){
        pizza.setPepperoni(peperoni);
        return this;
    }

    public PizzaBuilder withHam(int ham){
        pizza.setHam(ham);
        return this;
    }

    public Pizza build() {
        return pizza;
    }
}
