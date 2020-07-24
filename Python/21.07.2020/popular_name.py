import re, operator
from operator import eq


popular_names = {}

def list_of_lines(text):
    list_of_lines = text.split(".")
    for line in list_of_lines:
        names = [n.upper() for n in re.findall(r"\b[A-Z].*?\b", line)]
        if not names:
            return

        check_name(names[0])
        names.pop(0)   
        names = set(names)

        for name in names:
            if name in popular_names.keys():
                popular_names[name] = abs(popular_names[name]) + 1
            else:
                popular_names[name] = -1


def check_name(name):
    if name in popular_names.keys():
        if popular_names[name] > 0:
            popular_names[name] += 1
        else:
            popular_names[name] -= 1
    else:
        popular_names[name] = -1

def check_popular_names():
    names_list = list(popular_names.keys())
    for name in names_list:
        if popular_names[name] < 0:
            popular_names.pop(name)

def main():
    print("                       -- Enter your text -- ")
    print("________________________________________________________________________________")
    text = input()
    print("________________________________________________________________________________")
    number = int(input("\nEnter count of pupular numbers You expected to get: "))
    list_of_lines(text)
    check_popular_names()

    pop_names = sorted(popular_names.items(), key=operator.itemgetter(1), reverse = True)
    if len(pop_names) == 0:
        print("\n---> There is no any popular name...")
        return

    if number > len(pop_names):
        number = len(pop_names)
    print("\n                       -- Popular Names -- ")
    for i in range(0,number):
        print("#", i, "--->  ", end = "")
        print(pop_names[i])

if __name__ == "__main__":
    main()