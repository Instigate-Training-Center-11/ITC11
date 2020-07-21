import functions as module

def main():
    ''' Line count must be great then 0 '''
    print("enter number of lines: ", end = "")
    size = module.getNumber()

    ''' Create dictionary for string-values '''
    strings = {}
    ''' Create dictionary for number-values '''
    numbers = {}

    ''' Initialize dictionaries '''
    for i in range(size):
        print("Enter key for", i, ": ", end = "")
        key = input()
        print("Enter value for", key, ": ", end = "")
        value = input()
        if value[0].isnumeric():
            numbers[key] = value
        else:
            strings[key] = value

    ''' Print numeric-value dictionary sorted '''
    while len(numbers) > 0:
        key = module.getMinKey(numbers)
        print(key, ":", numbers[key])
        del numbers[key]

    ''' Print string-value dictionary sorted '''
    while len(strings) > 0:
        key = module.getMinKey(strings)
        print(key, ":", strings[key])
        del strings[key]

if __name__ == "__main__":
    main()