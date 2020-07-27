try:
    import os
    import re
    import argparse
except ImportError:
    ImportError.__getattribute__()

def print_d(text): print("\033[34m{}\033[04m".format(text), end = "\n")
def print_f(text): print("\033[92m{}\033[04m".format(text), end = "\n")

parser = argparse.ArgumentParser("optional arguments:",allow_abbrev=False)
parser.add_argument("--search",help='searching files or directories')
parser.add_argument("--include", default = '')
parser.add_argument("--exclude", default = '')
parser.add_argument("--path")
parser.add_argument("-f", action = "store_true")
parser.add_argument("-d", action = "store_true")

arguments = parser.parse_args()
path_input = arguments.path
include_args = arguments.include
exclude_args = arguments.exclude
files_args = arguments.f
dirs_args = arguments.d
key = arguments.search
data = os.listdir(path=path_input)

result_directories = []
result_files = []
result_include = []
result_exclude = []

def print_dirs(result_directories):
    for item in result_directories:
        if re.search(key,item):
            print_d(item)

def print_files(result_files):
    for i in result_files:
        if re.search(key,i):
            print_f(i)

for root, dirs, files in os.walk(path_input, topdown=False):
    if  dirs_args or files_args == False:
        for d in dirs:
            result_directories.append(os.path.join(root, d))
    if  files_args or dirs_args == False:
        for f in files:
            result_files.append(os.path.join(root, f))

if  dirs_args or files_args == False:
    print_dirs(result_directories)
if  files_args or dirs_args == False:
    print_files(result_files)

if include_args != '' or exclude_args == '':
    print("Include")
if exclude_args != '' or include_args == '':
    print("Exclude")

