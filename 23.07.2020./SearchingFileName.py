'''Importing moduls for using methods'''
import os
import argparse

'''Inputing argumnets'''
df = str(input("-d or -f :"))
s = str(input("--search=: "))
i = str(input("--include= : "))
e = str(input("--exclude= : "))
p = str(input("--path= : "))

'''Choose defalult directory as current'''
cur_dir = os.getcwd()
if p == "":
    p = cur_dir

'''Iteration in the choosed path or in current directory'''
'''Checking and printing if the file will be directory'''
'''Checking and printing if the file will be file with include and exclude some exstensions'''
'''The case if the file will be file or directory'''
for root, dirs, files in os.walk(p):
    if df == '-d':
        for file in dirs:
            if file.__contains__(s):
                print(os.path.join(root, file))
    elif df == '-f':
        for file in files:
            if file.__contains__(s) and \
                    (not file.endswith(i) or file.endswith(e)):
                print(os.path.join(root, file))                
    elif df == '':
        for file in files:
            if file.__contains__(s):
                print(os.path.join(root, file))
        for dir in dirs:
            if file.__contains__(s):
                print(os.path.join(root, file))

