array_one = [['aaa1', "zah", 'bdd'],
            ['a1', 'zah', 'add'],
            ['z9', 'z', 'bdd'],
            ['xh1', 'abc', 'bdd'],
            ['xh1', 'abc', 'bdd'],
            ['r1', 'aa', 'bb'],
            ['a0', '00', '77'],
            ['ww1', '08', '00']]

array_two = [['k1', '54', '78'],
            ['k2', 'kaa', 'bdd'],
            ['ka2', 'abc', 'bdd'],
            ['k2', 'abc', 'dbe']]

def display_list(array):
    for i in array:
        print(i)
    print(end="\n\n")

def swap_lines(array, first, second):
    """[swapped two line]
    Args:
        array ([class list]): [list]
        first ([str]): [str_one]
        second ([str]): [str_two]
    """
    tmp = array[first]
    array[first] = array[second]
    array[second] = tmp

def sort_by_key(array, first, second):
    """[sorted list by key]
    Args:
        array ([class list]): [list]
        first ([type]): [str_one]
        second ([type]): [str_two]
    """
    for i in range(second):
        for j in range(first, second-i):
            if array[j] > array[j+1]:
                swap_lines(array, j, j + 1)
            elif array[j] == array[j+1]:
                sort_by_value(array,j,j+1)

def sort_by_value(array, first, second):
    """[sorted list by value]
    Args:
        array ([class list]): [list]
        first ([str]): [str_one]
        second ([str]): [str_two]
    """
    for i in range(second):
        for j in range(first, second-i):
            if array[j][1] < array[j+1][1]:
                swap_lines(array, j, j + 1)

def sort_by_length(array, first, second):
    """[sorted list by length of key]
    Args:
        array ([class list]): [list]
        first ([str]): [str_one]
        second ([str]): [str_two]
    """
    for i in range(second):
        for j in range(first, second-i):
            if len(array[j][0]) > len(array[j+1][0]):
                swap_lines(array, j, j + 1)

def general_sort(array):
    """[sorted list]
    Args:
        array ([class list]): [list]
    """
    size = len(array) - 1
    sort_by_value(array, 0, size)
    j = 0
    for i in array:
        if array[j][1].isdigit():
            break
        j += 1

    sort_by_key(array, 0, j - 1)
    sort_by_length(array, 0, j - 1)
    sort_by_key(array, j, size)

def main():

    print("========= list ===========",end="\n\n")
    display_list(array_one)
    general_sort(array_one)
    print("======== sorted list =====",end="\n\n")
    display_list(array_one)
    print("========= list ===========",end="\n\n")
    display_list(array_two)
    general_sort(array_two)
    print("======== sorted list =====",end="\n\n")
    display_list(array_two)

if __name__ == "__main__":
    main()