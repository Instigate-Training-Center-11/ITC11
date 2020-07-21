n = int(input("Enter the number : "))

def is_in_range(n):
    return ((abs(1000 - n) <= 100) or (abs(2000 - n) <= 100))
print(is_in_range(n))
