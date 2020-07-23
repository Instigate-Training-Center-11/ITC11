import re

log = []
number = []
string = []

def input_log(num):
    for i in range(0 , num):
        log.append(input("line === "))

def num_and_str():
    for i in log:
        i = i.split(' ')
        temp = re.compile("([a-zA-Z]+)([0-9]+)")
        i[0] = list(temp.match(i[0]).groups())
        try:
            int(i[2])
            number.append(i)
        except:
            string.append(i)

def compare_int_line(line_1 , line_2):
    if len(line_1[0][0]) == len(line_2[0][0]) and line_1[0][0] == line_2[0][0]:
        if int(line_1[0][1]) == int(line_2[0][1]):
            if int(line_1[1]) == int(line_2[1]):
                if int(line_1[2]) > int(line_2[2]):
                    return True
                else:
                    return False
            elif int(line_1[1]) > int(line_2[1]):
                return True
            else:
                return False
        elif int(line_1[0][1]) > int(line_2[0][1]):
            return True
        else:
            return False
    elif line_1[0][0] > line_2[0][0]:
        return True
    else:
        return False

def compare_string_line(line_1 , line_2):
    if len(line_1[0][0]) == len(line_2[0][0]) and line_1[0][0] == line_2[0][0]:
        if int(line_1[0][1]) == int(line_2[0][1]):
            if line_1[1] == line_2[1]:
                if line_1[2] > line_2[2]:
                    return True
                else:
                    return False
            elif line_1[1] > line_2[1]:
                return True
            else:
                return False
        elif int(line_1[0][1]) > int(line_2[0][1]):
            return True
        else:
            return False
    elif line_1[0][0] > line_2[0][0]:
        return True
    else:
        return False

def bubble_sort_int():
    n = len(number)
    for i in range(0 , len(number)):
        for j in range(0 , len(number) - i - 1):
            if compare_int_line(number[j] , number[j + 1]):
                number[j] , number[j + 1] = number[j + 1] , number[j]

def bubble_sort_str():
    for i in range(0 , len(string)):
        for j in range(0 , len(string) - i - 1):
            if compare_string_line(string[j] , string[j + 1]):
                string[j] , string[j + 1] = string[j + 1] , string[j]

def clear_element_list(tmp):
    for i in tmp:
        i[0][0] += i[0][1]
        i[0].pop(1)

def print_lines():
    for i in string:
        print(i[0][0] , '\t' , i[1] , '\t' , i[2])
    for i in number:
        print(i[0][0] , '\t' , i[1] , '\t' , i[2])




def main():
    num = int(input("enter count =====  "))
    input_log(num)
    num_and_str()
    bubble_sort_int()
    bubble_sort_str()
    clear_element_list(number)
    clear_element_list(string)
    print_lines()

if __name__ == "__main__":
    main()