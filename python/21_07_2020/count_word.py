string = input("Enter the string: ")
print()
array = string.split(' ')
my_list = []
my_dict = {}
case = []
case.append(array[0])
for i in range(len(array)):
    last_index =len(array[i - 1]) - 1
    val = my_dict.values()
    if array[i].istitle() or array[i].isupper():
        if array[i][len(array[i]) - 1] == ',':
            array[i] = array[i][:array[i].index(',')]
        if array[i][len(array[i]) - 1] == '.':
            array[i] = array[i][:array[i].index('.')]
        if array[i] not in my_dict.keys():
            my_dict.update({array[i]:1})
        else:
            my_dict[array[i]] += 1
        my_list.append(array[i])
    if array[i - 1][last_index] == '.':
        case.append(array[i])
for i in case:
    if my_dict[i] == 1:
        del my_dict[i]
sort_list = []
for i in sorted (my_dict.keys()):  
    sort_list.append(i) 
for i in range(0, len(sort_list), 2):
    my_dict[sort_list[i]] += my_dict[sort_list[i + 1]]
    del my_dict[sort_list[i + 1]]
sort_orders = sorted(my_dict.items(), key = lambda x: x[1], reverse = True)
n = input("Enter the number: ")
while int(n) > len(my_dict):
    n = input("Enter the new number: ")
for i in range(int(n)):
    print(sort_orders[i][0], "\t: ", sort_orders[i][1])
