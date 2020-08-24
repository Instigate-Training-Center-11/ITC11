#include <iostream>

class Victorian {
    public:
    virtual void info() = 0;
    virtual ~Victorian() {}
};

class Modern {
    public:
    virtual void info() = 0;
    virtual ~Modern() {}
};

class VictorianChair: public Victorian {
    public:
    void info() {
        std::cout << "Victorian Chair" << std::endl;
    }
};

class ModernChair: public Modern {
    public:
    void info() {
        std::cout << "Modern Chair" << std::endl;
    }
};

class VictorianSofa: public Victorian {
    public:
    void info() {
        std::cout << "Victorian Sofa" << std::endl;
    }
};

class ModernSofa: public Modern {
    public:
    void info() {
        std::cout << "Modern Sofa" << std::endl;
    }
};

class FurnitureFactory
{
    public:
    virtual Victorian* createVictorian() = 0;
    virtual Modern* createModern() = 0;
    virtual ~FurnitureFactory() {}
};

class ChairFactory: public FurnitureFactory {
    public:
    Victorian* createVictorian() {
        return new VictorianChair;
    }
    Modern* createModern() {
        return new ModernChair;
    }
};

class SofaFactory: public FurnitureFactory {
    public:
    Victorian* createVictorian() {
        return new VictorianSofa;
    }
    Modern* createModern() {
        return new ModernSofa;
    }
};

int main() {
    ChairFactory* chair = new ChairFactory;
    SofaFactory* sofa = new SofaFactory;

    Victorian* newVictorianChair = chair->createVictorian();
    Modern* newModernChair = chair->createModern();
    newVictorianChair->info();
    newModernChair->info();

    Victorian* newVictorianSofa = sofa->createVictorian();
    Modern* newModernSofa = sofa->createModern();
    newVictorianSofa->info();
    newModernSofa->info();
}