#include <iostream>
#include <vector>

/*Abstract base classes of all Family of related products*/

class Chair
{
public:
    virtual void info() = 0;
    virtual ~Chair() {}
};

class Sofa
{
public:
    virtual void info() = 0;
    virtual ~Sofa() {}
};

class CoffeeTable
{
public:
    virtual void info() = 0;
    virtual ~CoffeeTable() {}
};

/* all furniture designed by artdeco */

class ArtDecoChair : public Chair
{
public:
    void info()
    {
        std::cout << "ArtDecoChair" << std::endl;
    }
};

class ArtDecoSofa : public Sofa
{
public:
    void info()
    {
        std::cout << "ArtDecoSofa" << std::endl;
    }
};

class ArtDecoCoffeeTable : public CoffeeTable
{
public:
    void info()
    {
        std::cout << "ArtDecoCoffeeTable" << std::endl;
    }
};

/* all furniture designed by Victorian */

class VictorianChair : public Chair
{
public:
    void info()
    {
        std::cout << "VictorianChair" << std::endl;
    }
};

class VictorianSofa : public Sofa
{
public:
    void info()
    {
        std::cout << "VictorianSofa" << std::endl;
    }
};

class VictorianCoffeeTable : public CoffeeTable
{
public:
    void info()
    {
        std::cout << "VictorianCoffeeTable" << std::endl;
    }
};

/* all furniture designed by Modern */

class ModernChair : public Chair
{
public:
    void info()
    {
        std::cout << "ModernChair" << std::endl;
    }
};

class ModernSofa : public Sofa
{
public:
    void info()
    {
        std::cout << "ModernSofa" << std::endl;
    }
};

class ModernCoffeeTable : public CoffeeTable
{
public:
    void info()
    {
        std::cout << "ModernCoffeeTable" << std::endl;
    }
};

/* Abstract factory for furniture production */

class FurnitureFactory
{
public:
    virtual Chair *createChair() = 0;
    virtual Sofa *createSofa() = 0;
    virtual CoffeeTable *createCoffeeTable() = 0;
    virtual ~FurnitureFactory() {}
};

/* Factory for the creation of Furniture of the ArtDeco design */

class ArtDecoFurnitureFactory : public FurnitureFactory
{
public:
    Chair *createChair()
    {
        return new ArtDecoChair;
    }
    Sofa *createSofa()
    {
        return new ArtDecoSofa;
    }
    CoffeeTable *createCoffeeTable()
    {
        return new ArtDecoCoffeeTable;
    }
};

/* Factory for the creation of Furniture of the Victorian design */

class VictorianFurnitureFactory : public FurnitureFactory
{
public:
    Chair *createChair()
    {
        return new VictorianChair;
    }
    Sofa *createSofa()
    {
        return new VictorianSofa;
    }
    CoffeeTable *createCoffeeTable()
    {
        return new VictorianCoffeeTable;
    }
};

/* Factory for the creation of Furniture of the Modern design */

class ModernFurnitureFactory : public FurnitureFactory
{
public:
    Chair *createChair()
    {
        return new ModernChair;
    }
    Sofa *createSofa()
    {
        return new ModernSofa;
    }
    CoffeeTable *createCoffeeTable()
    {
        return new ModernCoffeeTable;
    }
};

/* A class containing all types of furniture of a particular design */

class AllFurniture
{
public:
    ~AllFurniture()
    {
        int i;
        for (i = 0; i < vi.size(); ++i)
            delete vi[i];
        for (i = 0; i < va.size(); ++i)
            delete va[i];
        for (i = 0; i < vh.size(); ++i)
            delete vh[i];
    }
    void info()
    {
        int i;
        for (i = 0; i < vi.size(); ++i)
            vi[i]->info();
        for (i = 0; i < va.size(); ++i)
            va[i]->info();
        for (i = 0; i < vh.size(); ++i)
            vh[i]->info();
    }
    std::vector<Chair *> vi;
    std::vector<Sofa *> va;
    std::vector<CoffeeTable *> vh;
};

/* Furniture of one design or another is created here */
class Furniture
{
public:
    AllFurniture *createFurniture(FurnitureFactory &factory)
    {
        AllFurniture *p = new AllFurniture;
        p->vi.push_back(factory.createChair());
        p->va.push_back(factory.createSofa());
        p->vh.push_back(factory.createCoffeeTable());
        return p;
    };
};