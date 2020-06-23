#include <iostream>
using namespace std; 

template <class T>
class Vector;

template <typename T>
class Iterator {
	int size;
	Vector<T>* obj;
public: 
	Iterator(Vector<T>* object) {
		obj = object;
		size = 0;
	}

	bool hasNext() {
		return obj -> getSize() > size;
	}
	
	Iterator<T>* next() {
		++size;
		return this;
	}

	T getValue() {
		return obj -> getByIndex(size);
	}
};


template <typename T>
class Vector {
	T* arr;
	int capacity;
	int size;
	void growArray() {
		T* temp = new T[capacity * (3 / 2)];
		for (int i = 0; i < capacity; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		capacity *= 3 / 2;
		arr = temp;
	}
public:
	Vector() {
		arr = new T[16];
		capacity = 16;
		size = 0;
	}

	Vector(int n) {
		arr = new T[n];
		capacity = n;
		size = 0;
	}

	Iterator<T> getIterator() {
		Iterator<T> iter(this);
		return iter;
	}

	void shrinkToFit() {
		capacity = size;
	}

	void reserve(int n, T val = T()) {
		if(n > capacity) {
			growArray();
			reserve(n, val);	
		}
		int temp = size;
		size = n;
		for(; temp < size; ++temp) {
			arr[temp] = val;
		}
	}

	void resize(int size) {
		if(this -> size > size && size >= 0) {
			this -> size = size;
		}
	}

	bool isEmpty() const {
		return 0 == size;
	}

	void pushBack(const T& data) {
		if(size == capacity) {
			growArray();
		}
		arr[size] = data;
		size++;
	}
  
	void push(T data, int index) {
		if (index == capacity) {
			push_back(data);
		} else {
			arr[index] = data;
		}
	}

	T getByIndex(int index) {
		if (index < size && index >= 0) {
			return arr[index];
		}
	}
  
	void popBack() {
		size--;
	}
  
	int getSize() const {
		return size;
	}
  
	int getCapacity() const {
		return capacity;
	}

	void toString() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	Vector<int> vector;
	vector.pushBack(1);
	vector.pushBack(2);
	cout << "Array elements after pushBack() 1 and 2" << endl;
	vector.toString();

	vector.popBack();
	cout << "After popBack()" << endl;
	vector.toString();

	cout << "getSize() :" << vector.getSize() << endl;
	cout << "getCapacity() :" << vector.getCapacity() << endl;
	cout << "isEmpty() :" << vector.isEmpty() << endl;

	cout << "Elements of dinamic array after resize(0)" << endl;
	vector.resize(0);
	vector.toString();
	
	vector.reserve(5, 7);
	cout << "After reserve(5, 7)" << endl;
	vector.toString();

	vector.shrinkToFit();
	cout << "After shrinkToFit()" << endl;
	cout << "size :" << vector.getSize() << endl;
	cout << "capacity :" << vector.getCapacity() << endl;
	
	cout << "After iteration" << endl;
	Iterator<int> iter = vector.getIterator();
	while(iter.hasNext()) {
		cout << iter.getValue() << " ";
		iter.next();
	}
	cout << endl;
	return 0;
}
