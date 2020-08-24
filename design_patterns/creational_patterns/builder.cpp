#include <iostream>
#include <string>
class Pizza {
    private:
        std::string size;
        std::string cheese;
        std::string sauce;
        std::string pepperoni;
        std::string ham;
        std::string olives;
        std::string mushrooms;
    public:
        void sizePizza(const std::string newSize) {
            size = newSize;
        }
        void cheesePizza(const std::string newCheese) {
            cheese = newCheese;
        }
        void saucePizza(const std::string newSauce) {
            sauce = newSauce;
        }
        void pepperoniPizza(const std::string newPepperoni) {
            pepperoni = newPepperoni;
        }
        void hamPizza(const std::string newHam) {
            ham = newHam;
        }
        void olivesPizza(const std::string newOlives) {
            olives = newOlives;
        }
        void mushroomsPizza(const std::string newMushrooms) {
            mushrooms = newMushrooms;
        }
        void createPizza() {
            std::cout << size + "\n" + cheese + "\n" + sauce +
            "\n" + pepperoni + "\n" + ham + "\n" + olives + "\n" + mushrooms + "Pizza is created" << "\n";
        }
};

class Builder {
    protected:
        Pizza pizza;
    public:
        Pizza returnPizza() { 
            return pizza; 
        }
        virtual void buildSize() = 0;
        virtual void buildCheese() = 0;
        virtual void buildSauce() = 0;
        virtual void buildPepperoni() = 0;
        virtual void buildHam() = 0;
        virtual void buildOlives() = 0;
        virtual void buildMushrooms() = 0;


};
class Builder1: public Builder {
    public:
        void buildSize() {
            pizza.sizePizza("Medium");
        }
        void buildCheese() {
            pizza.cheesePizza("Lori cheese");
        }
        void buildSauce() {
            pizza.saucePizza("sauce +");
        }
        void buildPepperoni() {
            pizza.pepperoniPizza("peperoni -");
        }
        void buildHam() {
            pizza.hamPizza("ham +");
        }
        void buildOlives() {
            pizza.olivesPizza("olives +");
        }
        void buildMushrooms() {
            pizza.mushroomsPizza("mushrooms -");
        }
};
class Builder2: public Builder {
    public:
        void buildSize() {
            pizza.sizePizza("Big");
        }
        void buildCheese() {
            pizza.cheesePizza("Chanax cheese");
        }
        void buildSauce() {
            pizza.saucePizza("sauce -");
        }
        void buildPepperoni() {
            pizza.pepperoniPizza("peperoni +");
        }
        void buildHam() {
            pizza.hamPizza("ham +");
        }
        void buildOlives() {
            pizza.olivesPizza("olives +");
        }
        void buildMushrooms() {
            pizza.mushroomsPizza("mushrooms +");
        }
};
class Director {
    public:
        void setBuilder(Builder *b) {
            if (builder) {
            delete builder;
            }
            builder = b;
        }
        Pizza getProduct() { 
            return builder->returnPizza(); 
        }
        void construct() {
            builder->buildSize();
            builder->buildCheese();
            builder->buildSauce();
            builder->buildPepperoni();
            builder->buildHam();
            builder->buildOlives();
        }
    private:
        Builder *builder = nullptr;
};

int main() {
    Director director;
    director.setBuilder(new Builder1);
    director.construct();
    Pizza pizza1 = director.getProduct();
    pizza1.createPizza();

    std::cout << std::endl;

    director.setBuilder(new Builder2);
    director.construct();
    Pizza pizza2 = director.getProduct();
    pizza2.createPizza();
}