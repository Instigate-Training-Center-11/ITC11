import re

""" create an empty list for lines """
lines = []

""" input lines """
def input_lines(number):
    for i in range(0 , number):
        print("line #", i, " ---> ", end = "")
        lines.append(input())

""" create a list for strings and a list for numbers """
numbers_list = []
strings_list = []

""" seperate lines by strings and by numbers """
def divide_by_num_str():
    for i in lines:
        i = i.split(' ')
        symbol = re.compile("([a-zA-Z]+)([0-9]+)")
        i[0] = list(symbol.match(i[0]).groups())
        try:
            int(i[1])
            numbers_list.append(i)
        except:
            strings_list.append(i)

""" sort lines comparing them with each other """
def sorting(func):
    for i in range(0 , len(func)):
        for j in range(0 , len(func) - i - 1):
            if compare_lines(func[j] , func[j + 1]):
                temp = func[j]
                func[j] = func[j + 1]
                func[j + 1] = temp

def sorting_str(func):
    for i in range(0 , len(func)):
        for j in range(0 , len(func) - i - 1):
            if compare_lines(func[j] , func[j + 1]):
                temp = func[j]
                func[j] = func[j + 1]
                func[j + 1] = temp

def compare_lines(first_line, second_line):
    if first_line[0][0] == second_line[0][0] and len(first_line[0][0]) == len(second_line[0][0]):
        if int(first_line[0][1]) == int(second_line[0][1]):
            if first_line[1] == second_line[1]:
                if first_line[2] > second_line[2]: return True; return False
            elif first_line[1] > second_line[1]: return True; return False
        elif int(first_line[0][1]) > int(second_line[0][1]): return True; return False
    if first_line[0][0] > second_line[0][0]: return True; return False

""" desplay sorted lines """
def print_lines(func):
    for i in func:
        i[0][0] += i[0][1]
        i[0].pop(1)
        print(i[0][0], "  ", end = "")

        for j in range(1, len(i)):
            print(i[j], "  ",  end = "")
        print()

def main():
    print("Please, enter count of lines: ", end = "")
    num = int(input())

    input_lines(num)
    divide_by_num_str()

    sorting(numbers_list)
    sorting_str(strings_list)

    print("\n------> Lines After Sorting <------")
    print_lines(numbers_list)
    print_lines(strings_list)
    
if __name__ == "__main__":
    main()