package builder;

import org.w3c.dom.ls.LSOutput;

public class main {
        Pizza pizza = new PizzaBuilder()
                .withSize(20)
                .withChees(5)
                .withSauce(5)
                .withPeperoni(3)
                .withHam(10)
                .withOlives(5)
                .withMashroom(20)
                .withHam(10)
                .build();

}
