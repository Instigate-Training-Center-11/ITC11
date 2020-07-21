def pascal_triangle(rows):
    """ This function call pascal_triangle_rows for printing current row

    Args:
        rows (integer): Count for all rows
    """

    count = 0;
    while count <= rows:
        pascal_triangle_rows(count, rows)
        count += 1

def pascal_triangle_rows(row, rows):
    """ Calculate current row values

    Args:
        row (integer): Current row
        rows (integer): All rows
    """

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

def print_array(my_array, row):
    """ Print array and clear it

    Args:
        my_array (list): list for values in row
        row (integer): Current row
    """

    space = ' '
    print(row * space, end = space)
    for i in my_array:
        print(i, end = space)

    my_array.clear()

    print()

def input_index():
    """ Function checking validation and return true value

    Returns:
        (integer): Positive integer for rows
    """

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