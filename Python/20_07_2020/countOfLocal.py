def f():
    a = 1
    b = 2
    c = "some"

def main():
    print("Count of local variables is: " + repr(f.__code__.co_nlocals))

main()
