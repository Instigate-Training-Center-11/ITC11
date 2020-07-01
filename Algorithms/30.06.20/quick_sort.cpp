template<typename Type>
void sort(Type array[], int begin, int end) {
    int i = begin;
    int j = end;
    Type pivot = array[end - 1];

    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }

        while (array[j] > pivot) {
            j--;
        }

        if (i <= j) {
        swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    if (begin < j) {
        sort(array, begin, j);
    }

    if (i < end) {
        sort(array, i, end);
    }
}

template<typename Type>
void swap(Type& first, Type& second) {
    Type temp = first;
    first = second;
    second = temp;
}

template<typename Type>
void print(Type array[], int size) {
	for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

template<typename Type>
void random_array(Type array[], int size) {
	for (int i = 0; i < size; ++i) {
		array[i] = rand() % 1000;
	}
}