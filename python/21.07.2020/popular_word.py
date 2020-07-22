""" the function get lines number
    return line number
"""
def get_line_count():
    n = 0
    try:
        """try cast input value in int"""
        n = int(input("Enter Number of lines: "))

        if(n < 1):
            print("Please enter number grater than 0")
            get_line_count(n)
    except:
        """when input value is string generate exception and now call get_line_count function"""
        print("Please enter number grater than 0")
        get_line_count(n)

    return n


def input_lines(n, strings):
    print("Enter text")
    for i in range(0, n):
        """line split space"""
        words = input().split()
        tmp = []
        for j in words:
            tmp.append(j)
        strings.append(tmp)


def add_popular_word(strings, my_dict):
    for i in strings:
        for j in range(0, len(i)):
            """check word start uppercase or all simbols uppercase"""
            if(i[j][0].isupper()) and (i[j][1:].islower()) or i[j].isupper():
                cur = i[j]
                if(cur[-1] == '.'):
                    cur = cur[0:(len(cur) - 1)]
                """chack word find in dictionary and worf finding count incement"""
                if(cur.upper() in my_dict):
                    tmp = cur[0] + cur[1:].lower()
                    indexes = [k for k, x in enumerate(i) if x == cur or x == cur.upper() or x ==  tmp or x == i[j]]
                    if(indexes[0] != j):
                        continue
                    else:
                        my_dict[cur.upper()] = my_dict[cur.upper()] + 1
                    
                #"""when word not found in dictionary """ 
                #"""check word nots start in line then add in dictionary"""
                else:
                    if(j != 0):
                        tmp = i[j - 1]
                        if(tmp[-1] != '.'):
                            tmp = i[j]
                            if(tmp[-1] == '.' or tmp[-1] == ','):
                                """remove last . simbols than add in dictionary"""
                                tmp = tmp[0:(len(tmp) - 1)]
                                my_dict[tmp.upper()] = 1
                                
                            else:
                                my_dict[i[j].upper()] = 1


def popular_word(my_dict):
    print("\nThe Popular words is: \n")
    if(len(my_dict) < 3):
        for i in my_dict:
            print(i, ":", my_dict[i])
    else:
        my_dict = sorted(my_dict.items(), key=lambda x: x[1], reverse=True)
        for i in range(0, 3):
            print(my_dict[i][0], ":", my_dict[i][1])


def main():
    n = 0
    n = get_line_count()

    strings = []
    input_lines(n, strings)
    
    my_dict = {}
    add_popular_word(strings, my_dict)

    popular_word(my_dict)


if __name__ == "__main__":
    main()
