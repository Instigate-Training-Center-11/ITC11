#include <iostream>
#include <string>

class Furniture {
    public:
        virtual void getColor(std::string color) = 0;
};

class Chair: public Furniture {
    public:
        void getColor(std::string color) {
            std::cout << "Chair is "<< color << "\n";
        }
};

class Table: public Furniture {
    public:
        void getColor(std::string color) {
            std::cout << "Table is "<< color << "\n";
        }
};

class AbstractFactory {
    public:
        virtual Furniture* getChair() = 0;
        virtual Furniture* getTable() = 0;
};

class FurnitureFactory: public AbstractFactory {
    public:
        Furniture* getChair() {
            return new Chair;
        }
        Furniture* getTable() {
            return new Table;
        }
};

int main() {
	AbstractFactory *abstractFactory = new FurnitureFactory;

	Furniture* chair;
	chair = abstractFactory->getChair();
	chair->getColor("Blue");

    Furniture* table;
	table = abstractFactory->getTable();
	table->getColor("Green");
}