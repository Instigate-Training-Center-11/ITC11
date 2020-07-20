# Function has not local variable
def foo():
    pass

# Has 3 local variables
def func():
    name = "Mane"
    surname = "Antonyan"
    age = 20

# Run main function to see result
def main():
    print("Foo function's local variables count is:", foo.__code__.co_nlocals)
    print("Foo function's local variables count is:", func.__code__.co_nlocals)

if __name__ == "__main__":
    main()