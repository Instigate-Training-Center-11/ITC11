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

"""initializes list""" 
def input_lines(n, strings, numbers):
    print("\nEnter the lines as shown in the example: \nExample1: a1 df ki   \nExample2: a24 584 778\n")
    for i in range(0, n):
        print("Enter", i, "th line: ", end = "")
        words = input().split()
        tmp = []
        for j in words:
            tmp.append(j)
        try:
            int(tmp[1])
            numbers.append(tmp)
        except:
            strings.append(tmp)

"""swap two string lines"""
def string_swap(strings, i, j):
    tmp = strings[i]
    strings[i] = strings[j]
    strings[j] = tmp

"""swap two number lines"""
def number_swap(numbers, i, j):
    tmp = numbers[i]
    numbers[i] = numbers[j]
    numbers[j] = tmp

"""Sorting lines, from min to max"""
def sorting(strings, numbers):

    """sort string lines"""
    for i in range(0, len(strings)):
        for j in range(0, len(strings)):
            if(len(strings[i][0]) < len(strings[j][0])):
                string_swap(strings, i, j)
            elif(strings[i][0] < strings[j][0] and len(strings[i][0]) == len(strings[j][0])):
                string_swap(strings, i, j)
            elif(len(strings[i][0]) == len(strings[j][0])):
                if(len(strings[i][1]) < len(strings[j][1])):
                    string_swap(strings, i, j)
                elif(strings[i][1] < strings[j][1] and len(strings[i][1]) == len(strings[j][1])):
                    string_swap(strings, i, j)
                elif(len(strings[i][1]) == len(strings[j][1])):
                    if(len(strings[i][2]) < len(strings[j][2])):
                        string_swap(strings, i, j)
                    elif(strings[i][2] < strings[j][2] and len(strings[i][2]) == len(strings[j][2])):
                        string_swap(strings, i, j)

    """Sort number lines"""
    for i in range(0, len(numbers)):
        for j in range(0, len(numbers)):
            if(len(numbers[i][0]) < len(numbers[j][0])):
                number_swap(numbers, i, j)
            elif(numbers[i][0] < numbers[j][0] and len(numbers[i][0]) == len(numbers[j][0])):
                number_swap(numbers, i, j)
            elif(numbers[i][0] == numbers[j][0] and (len(numbers[i][1]) < len(numbers[j][1]) or numbers[i][1] < numbers[j][1])):
                number_swap(numbers, i, j)
            elif(numbers[i][0] == numbers[j][0] and (len(numbers[i][2]) < len(numbers[j][2]) or numbers[i][2] < numbers[j][2])):
                number_swap(numbers, i, j)

"""Print Sorting List"""
def printList(strings, numbers):
    print("\n==================Sorting List====================")
    for i in strings:
        for j in i:
            print(j, " ", end = "",)
        print()

    for i in numbers:
        for j in i:
            print(j, " ", end = "")
        print()

def main():
    n = get_line_count()
    
    strings = []
    numbers = []
    input_lines(n, strings, numbers)
    
    sorting(strings, numbers)
    printList(strings, numbers)

if __name__ == "__main__":
    main()
