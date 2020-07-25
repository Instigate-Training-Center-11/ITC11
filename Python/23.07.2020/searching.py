import argparse, os, re

argument = argparse.ArgumentParser(prog = 'Files Search Program')
argument.add_argument('--search', default = '')
argument.add_argument('--path', default = '.')
argument.add_argument('--include', default = '')
argument.add_argument('--exclude', default = '')
argument.add_argument('-d', action = 'store_true')
argument.add_argument('-f', action = 'store_true')
arg = argument.parse_args()

dirs_store = set()
files_store = set()

def get_result(space, store):
    for names in space:
        if arg.search in names:
            if '?' or '^' in arg.include:
                include_f_d = re.search(arg.include + '$', names)
            else:
                include_f_d = re.search('\w' + arg.include + '$', names)
            if '?' or '^' in arg.exclude:
                exclude_f_d = re.search(arg.exclude + '$', names)
            else:
                exclude_f_d = re.search('\W' + arg.exclude + '$', names)
            if arg.include == '' and arg.exclude == '':
                store.add(os.path.join(root, names))
            else:
                if arg.include == '' and arg.exclude != '':
                    if exclude_f_d: continue
                    store.add(os.path.join(root, names))
                elif include_f_d:
                    store.add(os.path.join(root, names))

for root, dirs, files in os.walk(arg.path, topdown = False):
    if arg.d or arg.f == False:
        get_result(dirs, dirs_store)
    if arg.f or arg.d == False:
        get_result(files, files_store)

if len(files_store) == 0 and len(dirs_store) == 0:
    print('No such file or directory...')

for d in dirs_store:
    print(d)
for f in files_store:
    print(f)
