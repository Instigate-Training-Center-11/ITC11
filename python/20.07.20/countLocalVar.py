"""Count local variables"""
def func():
    var = 10
    var1 = 2
    var3 = "String"

def main():
    print("Count of local variables is: " + repr(func.__code__.co_nlocals))

if __name__ == '__main__':
    main()
