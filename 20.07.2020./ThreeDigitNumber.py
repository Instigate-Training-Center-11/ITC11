n = int(input("Enter the three-digit number in range : "))
count = 0

for number in range(100, n):
    if number % 3 == 0:
        count += 1
print(count)
