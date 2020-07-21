def pascal_triangle(rows):
    count = 0;
    while count <= rows:
        pascal_triangle_rows(count, rows)
        count += 1

# Calculate current row values
def pascal_triangle_rows(row, rows):
    my_array = []
    for i in range(row + 1):
        my_array.append(0)

    my_array[0] = 1

    j = 1
    while j <= row:
        i = j
        while i >= 1:
            my_array[i] = my_array[i - 1] + my_array[i]
            i -= 1
        j += 1

    print_array(my_array, rows - row)

# Print array and clear it
def print_array(my_array, row):
    space = ' '
    print(row * space, end = space)
    for i in my_array:
        print(i, end = space)
    my_array.clear()
    print()

# Function checking value and return it
def input_index():
    while True:
        try:
            index = int(input("Insert index: "))
            if index < 0:
                print("Insert positive integer! Try again ")
                continue
        except ValueError:
            print("Insert positive integer! Try again ")
            continue
        else:
            return index
            break