import re

"""Create list for lines"""
lines_list = []

"""Create list for numbers and strings"""
numbers = []
strings = []

"""Input list lines"""
def input_lines(num):
    for i in range(0, num):
        print("Line ", i, ": ", end = "")
        lines_list.append(input())

def div_str_by_num():
    for i in lines_list:
        i = i.split(' ')
        smb = re.compile("([a-zA-Z]+)([0-9]+)")
        i[0] = list(smb.match(i[0]).groups())
        try:
            int(i[2])
            numbers.append(i)
        except:
            strings.append(i)

"""Sorted and compared lines by string"""
def sorting_str(lst):
    for i in range(0 , len(lst)):
        for j in range(0 , len(lst) - i - 1):
            if compare_string_lines(lst[j] , lst[j + 1]):
                tmp = lst[j]
                lst[j] = lst[j + 1]
                lst[j + 1] = tmp

def compare_string_lines(first, second):
    if len(first[0][0]) == len(second[0][0]) and first[0][0] == second[0][0]:
        if int(first[0][1]) == int(second[0][1]):
            if first[1] == second[1]:
                if first[2] > second[2]: return True; return False
            elif first[1] > second[1]: return True; return False
        elif int(first[0][1]) > int(second[0][1]): return True; return False 
    elif first[0][0] > second[0][0]: return True; return False


"""Sorted and compared lines by number"""
def sorting_num(lst):
    for i in range(0 , len(lst)):
        for j in range(0 , len(lst) - i - 1):
            if compare_num_lines(lst[j] , lst[j + 1]):
                tmp = lst[j]
                lst[j] = lst[j + 1]
                lst[j + 1] = tmp

def compare_num_lines(first, second):
    if first[0][0] == second[0][0] and len(first[0][0]) == len(second[0][0]):
        if int(first[0][1]) == int(second[0][1]):
            if int(first[1]) == int(second[1]):
                if int(first[2]) > int(second[2]): return True; return False
            elif int(first[1]) > int(second[1]): return True; return False
        elif int(first[0][1]) > int(second[0][1]): return True; return False
    elif first[0][0] > second[0][0]: return True; return False

""" Print lines after sorting"""
def print(lst):
    for i in lst:
        i[0][0] += i[0][1]
        i[0].pop(1)
        print(i[0][0], "  ", end = "")

        for j in range(1, len(i)):
            print(i[j], "  ",  end = "")
        print()

def main():
    num = int(input("Enter the number of lines: "))
    input_lines(num)
    div_str_by_num()
    sorting_num(numbers)
    sorting_str(strings)
    print("\n---List After Sorting---")
    print(strings)
    print(numbers)

if __name__ == "__main__":
    main()

