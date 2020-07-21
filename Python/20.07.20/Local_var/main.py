def some_foo(some_value):
    first = 1
    second = 2

def pascal_triangle (my_array, row):
    ffgfg = 8856
    fghgf = 7688766
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

print("Local variables in function: ",pascal_triangle.__code__.co_nlocals)
print("Local variables in function: ",some_foo.__code__.co_nlocals)

