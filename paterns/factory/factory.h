#include <iostream>
#include <vector>

/* Cars character class hierarchy */

class Car
{
public:
    virtual void info() = 0;
    virtual ~Car() {}
};

class Mercedes : public Car
{
public:
    void info()
    {
        std::cout << "Mercedes" << std::endl;
    };
};

class BMW : public Car
{
public:
    void info()
    {
        std::cout << "BMW" << std::endl;
    };
};

class Audi : public Car
{
public:
    void info()
    {
        std::cout << "Audi" << std::endl;
    };
};

/* Object factories */

class Factory
{
public:
    virtual Car *createCar() = 0;
    virtual ~Factory() {}
};

class MercedesFactory : public Factory
{
public:
    Car *createCar()
    {
        return new Mercedes;
    }
};

class BMWFactory : public Factory
{
public:
    Car *createCar()
    {
        return new BMW;
    }
};

class AudiFactory : public Factory
{
public:
    Car *createCar()
    {
        return new Audi;
    }
};