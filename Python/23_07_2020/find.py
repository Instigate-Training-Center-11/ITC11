import os, fnmatch

def find_files(directory, pattern):
    for root, dirs, files in os.walk(directory):
        for basename in files:
            if fnmatch.fnmatch(basename, pattern):
                filename = os.path.join(root, basename)
                yield filename

d = input("Enter directory name: ")
f = input("Enter full file name: ")
ext = input("Enter file type: ")
res = f + "." + ext

for filename in find_files(d, res):
    print ('Result is: ', filename)