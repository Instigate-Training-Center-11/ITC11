# Function for n-th Fibonacci number
def number_by_index(index):
    if index < 0:
        print("Incorrect input")
    elif index == 0 or index == 1:
        return 1
    else:
        return number_by_index(index - 1) + number_by_index(index - 2)

# Function checking value and return it
def input_index():
    while True:
        try:
            index = int(input("Insert index: "))
            if index < 0:
                print("Insert positive integer! Try again ")
                continue
        except ValueError:
            print("Insert positive integer! Try again ")
            continue
        else:
            return index
            break