def printing_name():
    firstname = "Vardan"
    lastname = "Babayan"
    print(firstname + " " + lastname)

def addition():
    first = 3
    second = 4
    third = 5
    print(first + second + third)

n = printing_name.__code__.co_nlocals
m = addition.__code__.co_nlocals
print("The count of local variables of printName() is: " + str(n))
print("The count of local variables of addition() is: " + str(m))
