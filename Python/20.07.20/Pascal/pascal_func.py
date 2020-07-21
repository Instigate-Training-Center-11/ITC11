# Calculate current row values
def pascal_triangle (my_array, row):
    for i in range(row + 1):
        my_array.append(0)

    my_array[0] = 1

    j = 1
    while j <= row:
        i = j
        while i >= 1:
            my_array[i] = my_array[i - 1] + my_array[i]
            i = i - 1
        j = j + 1

# Print array and clear it
def print_array (my_array):
    for i in my_array:
        print(i, end = ' ')
    my_array.clear()
    print()