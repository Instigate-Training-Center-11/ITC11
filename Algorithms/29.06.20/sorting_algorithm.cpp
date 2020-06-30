/* Merge sort */
template<typename Type>
void sort(Type array[], int begin, int end, int mid) {
	int i = 0;
	int j = 0;
	int count = 0;
	int size = end - begin + 1;
	Type buffer[size];
	i = begin;
	count = 0;
	j = mid + 1;

	while (i <= mid && j <= end) {
		if (array[i] < array[j]) {
			buffer[count] = array[i];
			++count;
			++i;
		} else {
			buffer[count] = array[j];
			++count;
			++j;
		}
	}

	while (i <= mid) {
		buffer[count] = array[i];
		++count;
		++i;
	}

	while (j <= end) {
		buffer[count] = array[j];
		++count;
		++j;
	}

	for (i = begin; i <= end; ++i) {
		array[i] = buffer[i - begin];
	}
}

template<typename Type>
void merge_sort(Type array[], int begin, int end) {
	int mid = 0;
	if(begin >= end) {
		return;
	}

	if (begin < end) {
		mid = (begin + end) / 2;
		merge_sort(array, begin, mid);
		merge_sort(array, mid + 1, end);

		sort(array, begin, end, mid);
	}
}

/* Selection sort */
template<typename Type>
void selection_sort(Type array[], int size) {
	int index_min = 0;
	int temp = 0;

	for (int i = 0; i < size - 1; ++i) {
		index_min = i;
		for (int j = i + 1; j < size; ++j) {
			if (array[index_min] > array[j]) {
				index_min = j;
			}
		}
		temp = array[i];
		array[i] = array[index_min];
		array[index_min] = temp;
	}
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