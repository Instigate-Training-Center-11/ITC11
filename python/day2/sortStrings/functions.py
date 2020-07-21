def getNumber():
    ''' Enter only integer number(not other charecter) '''
    ''' Number must be greater then 0 '''
    number = 0
    while number < 1:
        try:
            number = int(input())
        except ValueError:
            ''' If the input value is letter or string '''
            print("It is not a number!")
            print("Try again: ", end = "")
            number = 0
        else:
            ''' If input value is less than or equal to 0 '''
            if number < 1:
                print("Number must be great then 0!")
                print("Try again: ", end = "")
                number = 0
            else:
                return number

def getMinKey(diction):
    ''' Find minimum index from dictionary '''
    ''' If dictionary is empty, nothing to do '''
    if diction == {}:
        return None

    ''' Get first element's key from dictionary and infer it minimum key '''
    ''' For getting element by index used dictionary's keys like list '''
    minKey = list(diction.keys())[0]

    ''' Iterate all elements and return minimum key '''
    for key in diction:
        if key < minKey:
            minKey = key
    return minKey