#include <iostream>
#include <string>
using namespace std;

class Furniture {
public:
	virtual void makeFurniture(string data) = 0;	
};

class Chair : public Furniture {
public:
	void makeFurniture(string name) {
		cout << "Make " << name << endl;
	}
};

class Table : public Furniture {
public:
	void makeFurniture(string name) {
		cout << "Make " << name << endl;
	}
};

class AbstractFurniture {
public:
	virtual Furniture* get(string) = 0;
};

class FurnitureAbstractFactory : public AbstractFurniture {
public:
	Furniture* get(string name) {
		if (name == "chair") {
			return new Chair;
		} else if(name == "table") {
			return new Table;
		} else {
            return NULL;
        }
	}
};

int main()
{
	AbstractFurniture *abstractfurniture = new FurnitureAbstractFactory;
	Furniture* furniture = abstractfurniture->get("chair");	
	furniture->makeFurniture("chair");
}