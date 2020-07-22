"""input elements"""
def input_lines(num, string, number):
    print("\nEnter lines : ")
    for i in range(0, num):
       print("Enter", i, "th line: ", end = "")
       word = input().split()
       tmp = []
       for j in word:
           tmp.append(j)
       try:
           int(tmp[1])
           number.append(tmp)
       except:
           string.append(tmp)

"""swap numbers"""
def num_swap(number, i, j):
    tmp = number[i]
    number[i] = number[j]
    number[j] = tmp

"""swap strings"""
def string_swap(string, i, j):
    tmp = string[i]
    string[i] = string[j]
    string[j] = tmp

"""sorting"""
def sorting(string, number):
    """sorting strings"""
    for i in range(0, len(string)):
        for j in range(0, len(string)):
            if(len(string[i][0]) < len(string[j][0])):
                string_swap(string, i, j)
            elif(string[i][0] < string[j][0] and len(string[i][0]) == len(string[j][0])):
                string_swap(string, i, j)
            elif(len(string[i][0]) == len(string[j][0])):
                if(len(string[i][1]) < len(string[j][1])):
                    string_swap(string, i, j)
                elif(string[i][1] < string[j][1] and len(string[i][1]) == len(string[j][1])):
                    string_swap(string, i, j)
                elif(len(string[i][1]) == len(string[j][1])):
                    if(len(string[i][2]) < len(string[j][2])):
                        string_swap(string, i, j)
                    elif(string[i][2] < string[j][2] and len(string[i][2]) == len(string[j][2])):
                        string_swap(string, i, j)

    """sorting numbers"""
    for i in range(0, len(number)):
        for j in range(0, len(number)):
            if(len(number[i][0]) < len(number[j][0])):
                num_swap(number, i, j)
            elif(number[i][0] < number[j][0] and len(number[i][0]) == len(number[j][0])):
                num_swap(number, i, j)
            elif(number[i][0] == number[j][0] and (len(number[i][1]) < len(number[j][1]) or number[i][1] < number[j][1])):
                num_swap(number, i, j)
            elif(number[i][0] == number[j][0] and (len(number[i][2]) < len(number[j][2]) or number[i][2] < number[j][2])):
                num_swap(number, i, j)


def print_sort(string, number):
    print("\n=====After sorting=====")
    for i in string:
        for j in i:
            print(j, " ", end = "",)
        print()
    for i in number:
        for j in i:
            print(j, " ", end = "")
        print()

def main():
    num = int(input("Enter Number of lines: "))
    string = []
    number= []
    input_lines(num, string, number)
    sorting(string, number)
    print_sort(string, number)

main()

