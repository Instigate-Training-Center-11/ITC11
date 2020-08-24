package build;

public class Main {
    public static void main(String[] args) {
        Director director = new Director();
        PizzaBuilder pizzaBuilder1 = new PizzaBuilder1();
        director.setPizzaBuilder(pizzaBuilder1);
        director.constructPizza();
        Pizza pizza = director.getPizzaBuilder().getPizza();
        System.out.println(pizza);
    }
}