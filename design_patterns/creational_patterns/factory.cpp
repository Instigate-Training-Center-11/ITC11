#include <iostream>
#include <string>

// enum Car_ID {
//     Mersedes_ID = 0,
//     AudiTT_ID
// };

class Car {
    public:
        virtual void countSeedsDoors() = 0; 
        Car* createCar( std::string );

};

class Mersedes : public Car{
private:
    int seeds = 0;
    int doors = 0;
public:
    Mersedes(int seeds, int doors) {
        this->seeds = seeds;
        this->doors = doors;
    }
    void countSeedsDoors() {
        std::cout << "Seeds count in Mersedes is " << seeds << '\n';
        std::cout << "Doors count in Mersedes is " << doors << '\n';
    }
};

class AudiTT : public Car {
private:
    int seeds = 0;
    int doors = 0;
public:
    AudiTT(int seeds, int doors) {
        this->seeds = seeds;
        this->doors = doors;
    }

    void countSeedsDoors() {
        std::cout << "Seeds count in AudiTT is " << seeds << '\n';
        std::cout << "Doors count in AudiTT is " << doors << '\n';
    }
};

Car* Car::createCar(std::string name) {
    Car * car;
    if (name == "Mersedes") {
        car = new Mersedes(4, 4); 
    } else if (name == "AudiTT") {           
        car = new AudiTT(2, 2);           
    } else {        
        car = NULL;
    }

    return car;
};

int main () {
    Car* car1;
    Car* car2;
    car1->createCar("Mersedes")->countSeedsDoors();
    car2->createCar("AudiTT")->countSeedsDoors();
    return 0;
}