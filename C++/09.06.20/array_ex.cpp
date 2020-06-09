#include <iostream>
#include <string>

class array_exception {
private:
	std::string my_error;
	int my_count;

public:
	array_exception(std::string error, int count = 0) : my_error(error), my_count(count) {
        std::cout << "invalid index = " << my_count << std::endl;
    }

	array_exception(const array_exception& o) : my_error(o.my_error), my_count(o.my_count + 1) {

    }

	~array_exception() {

    }

	const char* get_error() const {
        return my_error.c_str();
    }
};

void get_by_index(int[], int, int);

int main() {
    int size = 5;
    int array[size] = {1, 2, 3, 4, 5};
    try {
        get_by_index(array, size, 777);
    } catch (array_exception &exception) {
        std::cerr << "array exception! (" << exception.get_error() << ")\n";
    }
}

void get_by_index(int arr[], int size, int index) {
    if (index > size || index < 0) {
        throw array_exception("Invalid index", index);
    } else {
        std::cout << "value[" << index << "] = " << arr[index] << std::endl;
    }
}