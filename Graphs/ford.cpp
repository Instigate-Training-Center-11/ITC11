#include <iostream>
#include <list>
using namespace std;

class Weight;

class Node {
	string name;
	list<Node> *nextElements;

public:
	string getName() {
		return this -> name;
	}

	void setName(string name) {
		this -> name = name;
	}

	list<Node>* getNextElements() {
		return this -> nextElements;
	}

	void setNextElements(list<Node> *nextElements) {
		this -> nextElements = nextElements;
	}

	Node(string name, list<Node> *nextElements = NULL) {
		setNextElements(nextElements);
		setName(name);
	}
};

class Weight {
	Node *nodeFrom;
	Node *nodeTo;
	int weight;
public:
	Node* getNodeFrom() {
		return this -> nodeFrom; 
	}

	void setNodeFrom(Node *node) {
		this -> nodeFrom = nodeFrom;
	}

        Node* getNodeTo() {
                return this -> nodeTo;
        }

        void setNodeTo(Node *node) {
                this -> nodeTo = nodeTo;
        }


	int getWeight() {
		return this -> weight;
	}

	void setWeight(int weight) {
		this -> weight = weight;
	}

	Weight(int weight, Node *nodeTo = NULL, Node *nodeFrom = NULL) {
		setWeight(weight);
		setNodeFrom(nodeFrom);
		setNodeTo(nodeTo);
	}
};

class Graph {
	list<Weight> *weights;
	list<Node> *nods;
public:

	void addWeight(Weight *weight) {
	}

	

	void shortPath(Node *start, Node *end) {
		
	}

	Graph() {
		weights = NULL;
		nods = NULL;
	}
	
};

int main() {
	Graph someGraph;
	return 0;
}
