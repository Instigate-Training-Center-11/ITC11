"""Importing moduls for using methods"""
import os
import argparse

"""Inputing argumnets"""
dir_file = str(input("-d or -f :"))
search = str(input("--search=: "))
inc = str(input("--include= : "))
exc = str(input("--exclude= : "))
path = str(input("--path= : "))

"""Choose default directory as current"""
cur_dir = os.getcwd()
if path == "":
    path = cur_dir

for root, dirs, files in os.walk(path):
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
