import os
import re
import argparse

def print_red(text): print("\033[91m {}\033[00m" .format(text), end = '')
def print_green(text): print("\033[92m {}\033[00m" .format(text))
def print_blue(text): print("\033[34m {}\033[00m" .format(text))

def print_result(my_data, result):
    for dirs_or_files in my_data:
        if key in dirs_or_files:
            if '^' or '?' in include_regex:
                include_file = re.search(include_regex + '$', dirs_or_files)
            else:
                include_file = re.search('\w' + include_regex + '$', dirs_or_files)
            if '^' or '?' in exclude_regex:
                exclude_file = re.search(exclude_regex + '$', dirs_or_files)
            else:
                exclude_file = re.search('\w' + exclude_regex + '$', dirs_or_files)
            if include_regex == '' and exclude_regex == '':
                result.append(os.path.join(root, dirs_or_files))
            else:
                if include_regex == '' and exclude_regex != '':
                    if exclude_file:
                        continue
                    result.append(os.path.join(root, dirs_or_files))
                elif include_file:
                    result.append(os.path.join(root, dirs_or_files))

parser = argparse.ArgumentParser(description = 'A tutorial of My Find 1.0')
parser.add_argument("--search", required = True, help = "Key for searching")
parser.add_argument("--path", default = ".", help = "Path (by default search in current directory)")
parser.add_argument("--include", default = '', help = "Include some results by key")
parser.add_argument("--exclude", default = '', help = "Exclude some results by key")
parser.add_argument("--color", action = "store_true", help = "Print in colors")
parser.add_argument("-f", action = "store_true", help = "Show all files")
parser.add_argument("-d", action = "store_true", help = "Show all directories")

args = parser.parse_args()
only_files = args.f
only_dirs = args.d
color = args.color
include_regex = args.include
exclude_regex = args.exclude
key = args.search
my_path = args.path
my_data = os.listdir(path=my_path)

if my_path == ".":
    my_path = os.getcwd()

result_dirs = []
result_files = []

for root, dirs, files in os.walk(my_path, topdown=False):
    if only_dirs or only_files == False:
        print_result(dirs, result_dirs)
    if only_files or only_dirs == False:
        print_result(files, result_files)

len_dirs = len(result_dirs)
len_files = len(result_files)

if len_files == 0 and len_dirs == 0:
    print_red("No such file or directory")
else:
    print_blue(str(len_dirs) + " directories")
    print_green(str(len_files) + " files\n")

    for i in result_dirs:
        if color:
            print_blue(i)
        else:
            print(i)
    for i in result_files:
        if color:
            print_green(i)
        else:
            print(i)