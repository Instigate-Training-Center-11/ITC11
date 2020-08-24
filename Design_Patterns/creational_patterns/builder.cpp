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
        void sizeP(const std::string &size_p) {
            size = size_p;
        }
        void cheeseP(const std::string &cheese_p) {
            cheese = cheese_p;
        }
        void sauceP(const std::string &sauce_p) {
            sauce = sauce_p;
        }
        void pepperoniP(const std::string &pepperoni_p) {
            pepperoni = pepperoni_p;
        }
        void hamP(const std::string &ham_p) {
            ham = ham_p;
        }
        void olivesP(const std::string &olives_p) {
            olives = olives_p;
        }
        void mushroomsP(const std::string &mushrooms_p) {
            mushrooms = mushrooms_p;
        }
        void getPizza() {
            std::cout << "Pizza " << size + " " + cheese + " " + sauce +
            " " + pepperoni + " " + ham + " " + olives + " " + mushrooms + " " +
            " have been created" << "\n";
        }
};

class Builder {
    protected:
        Pizza pizza;
    public:
        Pizza getProduct() {
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

class ConcreateBuilder1: public Builder {
    public:
        void buildSize() {
            pizza.sizeP("Big");
        }
        void buildCheese() {
            pizza.cheeseP("cheese (+)");
        }
        void buildSauce() {
            pizza.sauceP("sauce (+)");
        }
        void buildPepperoni() {
            pizza.pepperoniP("peperoni (-)");
        }
        void buildHam() {
            pizza.hamP("ham (-)");
        }
        void buildOlives() {
            pizza.olivesP("olives (+)");
        }
        void buildMushrooms() {
            pizza.mushroomsP("mushrooms (-)");
        }
};

class ConcreateBuilder2: public Builder {
    public:
        void buildSize() {
            pizza.sizeP("Small");
        }
        void buildCheese() {
            pizza.cheeseP("cheese (+)");
        }
        void buildSauce() {
            pizza.sauceP("sauce (-)");
        }
        void buildPepperoni() {
            pizza.pepperoniP("peperoni (-)");
        }
        void buildHam() {
            pizza.hamP("ham (+)");
        }
        void buildOlives() {
            pizza.olivesP("olives (+)");
        }
        void buildMushrooms() {
            pizza.mushroomsP("mushrooms (+)");
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
            return builder->getProduct();
        }

        void construct() {
            builder->buildSize();
            builder->buildCheese();
            builder->buildSauce();
            builder->buildPepperoni();
            builder->buildHam();
            builder->buildOlives();
            builder->buildMushrooms();
        }
    private:
        Builder *builder = nullptr;
};

int main() {
    Director director;
    director.setBuilder(new ConcreateBuilder1);
    director.construct();

    Pizza pizza1 = director.getProduct();
    pizza1.getPizza();

    director.setBuilder(new ConcreateBuilder2);
    director.construct();

    Pizza pizza2 = director.getProduct();
    pizza2.getPizza();
}