from collections import Counter

def elements_count():
    st = "Tux is a penguin character Tux\
        TUX of the LINUX kernel. Originally CREAted as an ENtry\
        to a Linux TUX is the most LINUX\
        for Linux although different Linux depict Tux in\
        various styles. The character is used in many other lInux programs\
        and as a general symbol of. Linux. Bbbb BBBB"
    arr = st.split(" ")
    new_arr = []
    after_dot = []

    '''All special names add in the array'''
    for i in range(len(arr)):
        if arr[i].istitle() or arr[i].isupper():
            new_arr.append(arr[i])

    after_dot.append(new_arr[0])
    new_arr.remove(new_arr[0])

    '''Add the next element of '.' into the new array, and delete it from the old array.'''
    for i in range(len(new_arr)):
        l = len(new_arr[i])
        if new_arr[i][l - 1] == ".":
            after_dot.append(new_arr[i + 1])
            ind = i
            
    new_arr.remove(new_arr[ind + 1])

    '''Duplicate elements inside 2 arrays.'''
    crossing_el = list(set(new_arr) & set(after_dot))

    for i in crossing_el:
        new_arr.append(i)

    '''Delete the '.' from array element.'''
    for i in range(len(new_arr)):
        if new_arr[i][len(new_arr[i]) - 1] == ".":
            new_arr[i] = new_arr[i][:new_arr[i].index(".")]

    '''Count of number duplicate elements.'''
    counts = Counter(new_arr)
    k = counts.keys()
    v = counts.values()
    '''Create dict from keys and values.'''
    d = dict(zip(k, v))
    new_d = {}
    keys = d.keys()

    for i in keys:
        if d[i] != 1:
            new_d[i] = d[i]

    '''Sort the result and print the elements with its counts.'''
    result = sorted(new_d.items(), key = lambda x: x[1], reverse = True)

    print("The count of all special names in the string is: ")
    print()
    for i in result:
        print(i[0], "\t-", i[1])

def main():
    elements_count()

if __name__ == '__main__':
    main()