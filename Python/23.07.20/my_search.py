import os
import re
import argparse

def print_result(my_data):
    for dirs_or_files in my_data:
        if key in dirs_or_files:
            if '^' in include_regex:
                include_file = re.search(include_regex + '$', dirs_or_files)
            else:
                include_file = re.search('\w' + include_regex + '$', dirs_or_files)
            exclude_file = re.search('\w' + exclude_regex + '$', dirs_or_files)
            if include_regex == '' and exclude_regex == '':
                print(os.path.join(root, dirs_or_files))
            if include_regex == '' and exclude_regex != '':
                if exclude_file:
                    continue
                print(os.path.join(root, dirs_or_files))
            if include_file:
                print(os.path.join(root, dirs_or_files))

parser = argparse.ArgumentParser(description = 'A tutorial of My Find 1.0')
parser.add_argument("--search", required = True, help = "Key for searching")
parser.add_argument("--path", default = ".", help = "Path (by default search in current directory)")
parser.add_argument("--include", default = '', help = "Include some results by key")
parser.add_argument("--exclude", default = '', help = "Exclude some results by key")
parser.add_argument("-f", action = "store_true", help = "Show all files")
parser.add_argument("-d", action = "store_true", help = "Show all directories")

args = parser.parse_args()
only_files = args.f
only_dirs = args.d
include_regex = args.include
exclude_regex = args.exclude
key = args.search
my_path = args.path
my_data = os.listdir(path=my_path)

for root, dirs, files in os.walk(my_path, topdown=False):
    if only_dirs or only_files == False:
        print_result(dirs)
    if only_files or only_dirs == False:
        print_result(files)