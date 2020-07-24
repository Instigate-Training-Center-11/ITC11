import re
import os
import argpars

search=''
include=''
exclude=''
path=''
file = []
dir = []

def change_string(str):
    j = '^'
    str = list(str)
    for i in str:
        if i == '*':
            j += '.*'
        elif re.findall(r"[@_!+#$%^&*()<>?/\|}{~:]" , i):
            j = j + "\\" + i
            pass
        else:
            j += i
    j = j + '$'
    return j

def search_list():
    dir_list = os.listdir(path)
    for i in dir_list:
        if re.findall(search , i):
            if re.findall(include , i):
                if not re.findall(exclude , i):
                    if os.path.isdir(i):
                        dir.append(i)
                    else:
                        file.append(i)

def print_list():
    if argpars.args.f and argpars.args.d:
        print("files=====")
        print(file)
        print("directories=======")
        print(dir)
    elif argpars.args.f:
        print("files=====")
        print(file)
    elif argpars.args.d:
        print("directories=======")
        print(dir)
    else:
        print("files=====")
        print(file)
        print("directories=======")
        print(dir)

search=argpars.args.search
include=change_string(argpars.args.include)
exclude=change_string(argpars.args.exclude)
path=argpars.args.path

def main():
    search_list()
    print_list()

if __name__ == "__main__":
    main()