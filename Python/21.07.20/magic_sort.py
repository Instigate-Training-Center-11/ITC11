def print_array(array):
    """ Print array

    Args:
        array (list): List
    """

    for i in array:
        print(i)
    print('_______________________', end = '\n\n')

def my_sort(array):
    """ Sorting array at first by second value

    Args:
        array (list): List
    """

    print_array(array)
    array.sort(key = lambda element: element[1], reverse = True)

    j = 0
    for i in array:
        if array[j][1].isdigit():
            break
        j += 1
    array[j:len(array)] = sorted(array[j:len(array)])
    array[0:j] = sorted(array[0:j], key = lambda element: len(element[0]))

    i = 0
    tmp = 0
    while i < j:
        if len(array[i][0]) != len(array[i+1][0]):
            array[tmp:i+1] = sorted(array[tmp:i+1])
            tmp = i + 1
        i += 1
    print_array(array)