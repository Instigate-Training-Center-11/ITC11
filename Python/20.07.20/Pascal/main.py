import pascal_func

my_array = []

rows = int(input("Insert index: "));

count = 0;
while count <= rows:
    pascal_func.pascal_triangle(my_array, count)
    pascal_func.print_array(my_array)
    count += 1