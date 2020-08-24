#include <iostream>

class Car {
    public:
        virtual void speed() = 0;
        virtual void color() = 0;
};

class Car1: public Car {
    public:
        void speed() {
            std::cout << "Car1 whit speed 200km-h\n";
        }
        void color() {
            std::cout << "Car1 whit blue color\n";
        }
};

class Car2: public Car {
    public:
        void speed() {
            std::cout << "Car2 whit speed 185km-h\n";
        }
        void color() {
            std::cout << "Car2 whit green color\n";
        }
};

int main() {
    std::cout << "car1 -->>>" << "\n";
    Car1 car1;
    car1.speed();
    car1.color();

    std::cout << "car2 -->>>" << "\n";
    Car2 car2;
    car2.speed();
    car2.color();
} 