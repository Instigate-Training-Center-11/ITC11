""" To check perfect numbers: """
""" ask user to input a number """
def user_input():
    index = 0
    while index < 1:
        print("Enter a number: ", end = "")
        try:
            index = int(input())
        except ValueError:
            print("\nTry again...")
            index = 0
        else:
            if index < 1:
                print("\nTry again... Enter a number greater 0 !!!")
                index = 0
            else:
                return index

"""" use two checking versions to check if inputted number is a perfect number or not """
""" first version - using perfect numbers collaction (tupil contains only first 8 perfect numbers)"""
def perfect_number_list(number):
    perfect_num = (6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128)
    return (number in perfect_num)

"""" second version - using 'for' loop """
def perfect_number(number):
    sum = 0
    for i in range(1, ((number // 2) + 1)):
        if number % i == 0:
            sum += i
    return (sum == number)

""" send used a message if inputted number is a perfect number or not """
def print_output(num, func):
    if (func == True):
        print("==>  '", num, "' is a perfect number!!!")
    else:
        print("==>  '", num, "' is NOT a perfect number!!!")

def main():
    print("------- Check if number is perfect or not -------")
    num = user_input()

    print("\n* Version 1")
    print_output(num, perfect_number_list(num))

    print("\n* Version 2")
    print_output(num, perfect_number(num))

if __name__ == "__main__":
    main()
