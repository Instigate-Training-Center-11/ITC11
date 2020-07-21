def foo_one():
    a = 5
    b = 20
    c = 30
    f = 0

def foo_two():
    x = "dfdf"
    g = 5454
    e = 251

print("count local  variables in function foo_one = ",foo_one.__code__.co_nlocals) 
print("count local variables in function foo_two = ",foo_two.__code__.co_nlocals) 

