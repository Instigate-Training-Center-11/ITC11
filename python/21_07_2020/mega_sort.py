''' Divides the lines by intager and by string '''
def parser_line_type(line, number, txt):
    for i in line:
        words = i.split(' ')
        if not words[1].isdigit():
            txt.append(i)
        else:
            number.append(i)


''' Sorted list by first word by to given condition '''
def compare_line(int_line, keys):
    sort_line = []
    str_list = []
    finish = []
    for i in range(len(keys)):
        for j in range(len(keys)):
            if keys[i] in int_line[j]:
                sort_line.append(int_line[j])
                del int_line[j]
                break

    for i in range(len(sort_line)):
        str_list.append(sort_line[i].split(' '))

    for i in range(len(str_list) - 1):
        for j in range(2):
            if str_list[i][j] == str_list[i + 1][j] and str_list[i][j + 1] > str_list[i + 1][j + 1]:
                temp = str_list[i]
                str_list[i] = str_list[i + 1]
                str_list[i + 1] = temp

    for i in str_list:
        finish.append(' '.join(i))

    return finish


''' Sorted only first words by to given condition '''
def compare_keys(txt_or_num_list, keys):
    for i in txt_or_num_list:
        words = i.split(' ')
        keys.append(words[0])

    keys.sort()
    sorted_key = list(sorted(keys, key = len))
    return sorted_key



def sort():
    my_str = ['wz3 fdgf dfgd', 'mi2 jog mid', 'avvv5 alps cow',
             'x5 45 27', 'a1 alps blov', 'a1 alps bloz', 'axe5 455 27',
             'a5 25 80','a6 25 70','tx5 405 97']

    my_txt = []
    my_number = []
    my_txt_keys = []
    my_int_keys = []

    parser_line_type(my_str, my_number, my_txt)

    sort_txt_key = compare_keys(my_txt, my_txt_keys)
    sort_int_key = compare_keys(my_number, my_int_keys)
    
    sort_txt_line = compare_line(my_txt, sort_txt_key)
    sort_int_line = compare_line(my_number, sort_int_key)
    
    print('Given text!!!\n')
    for i in my_str:
        print(i)

    print('\nSorted text!!!\n')
    for i in sort_txt_line:
        print(i)

    for i in sort_int_line:
        print(i)

sort()