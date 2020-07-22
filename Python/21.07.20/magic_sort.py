def print_array(array):
    """ Print array

    Args:
        array (list): List
    """

    for i in array:
        print(i)
    print('_______________________', end = '\n\n')

def take_second(element):
    """ Take second value
    """

    return element[1]

def my_sort(array):
    """ Sorting array at first by second value

    Args:
        array (list): List
    """

    print_array(array)
    array.sort(key = take_second, reverse = True)

    j = 0
    for i in array:
        if array[j][1].isdigit():
            break
        j += 1
    array[j:len(array)] = sorted(array[j:len(array)])
    array[0:j] = sorted(array[0:j])
    print_array(array)