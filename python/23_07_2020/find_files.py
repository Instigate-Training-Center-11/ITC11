import os
import sys


def args_in_dict(arg):
    ''' Inline arguments throw in dictionary '''

    for i in sys.argv:
        if '=' in i:
            temp = i.split('=')
            arg.update({temp[0]:temp[1]})
        if '--path' not in arg.keys():
            arg.update({'--path':'.'})


def print_fils(args, files):
    ''' Print selected files '''

    if '--include' not in args and '--exclude' not in args:
        ''' Print all files '''

        for i in files:
            if args['--search']  in i:
                print(i)

    elif '--exclude' not in args or '--exclude' in args and '--include' in args:
        ''' Print included files '''

        include = args['--include'][1:]
        for i in files:
            if args['--search']  in i and include in i:
                print(i)

    elif '--include' not in args:
        ''' Print all files except exclude files '''

        exclude = args['--exclude'][1:]
        for i in files:
            if args['--search']  in i and exclude not in i:
                print(i)


def main():
    my_dict = {}
    args_in_dict(my_dict)
    my_files = os.listdir(my_dict['--path'])
    print_fils(my_dict, my_files)


if __name__ == '__main__':
    main()