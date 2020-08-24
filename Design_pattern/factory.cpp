#include <iostream>

class Car {
    public:
    virtual void brend() = 0;
    virtual ~Car() {}
};

class Mercedes: public Car {
    public:
    void brend() {
        std::cout << "Mercedes" << std::endl;
    }
};

class Bmw: public Car {
    public:
    void brend() {
        std::cout << "Bmw" << std::endl;
    }
};

class Audi: public Car {
    public:
    void brend() {
        std::cout << "Audi" << std::endl;
    }
};

// Car Factory
class Factory {
    public:
    virtual Car* createCar() = 0;
    virtual ~Factory() {}
};

class MercedesFactory: public Factory {
    public:
    Car* createCar() {
        return new Mercedes;
    }
};

class BmwFactory: public Factory {
    public:
    Car* createCar() {
        return new Bmw;
    }
};

class AudiFactory: public Factory {
    public:
    Car* createCar() {
        return new Audi;
    }
};

int main() {
    MercedesFactory* mercedes_factory = new MercedesFactory;
    BmwFactory* bmw_factory  = new BmwFactory ;
    AudiFactory* audi_factory  = new AudiFactory;

    Car* w202 = mercedes_factory->createCar();
    Car* e38 =  bmw_factory->createCar();
    Car* rs7 = audi_factory->createCar();

    w202->brend();
    e38->brend();
    rs7->brend();
}