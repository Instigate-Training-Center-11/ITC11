# Function for n-th Fibonacci number
def number_by_index(index):
    if index < 0:
        print("Incorrect input")
    elif index == 1 or index == 2:
        return 1
    else:
        return number_by_index(index - 1) + number_by_index(index - 2)