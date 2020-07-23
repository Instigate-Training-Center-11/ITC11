import os
import sys


def boolean(s1, s2):
    if '^' in s1:
        s = str.replace(s1, '^', '')
        return s2.startswith(s)
    elif '*' in s1:
        s = str.split(s1, '*')
        return s2.startswith(s[0]) and s2.endswith(s[1])
    elif '?' in s1:
        s = str.split(s1, '?')
        return s2.startswith(s[0]) and s2.endswith(s[1]) and (s2.count("") - s1.count("")) is 0
    else:
        return s1 in s2


def f(pat, b, w, inc, exc):
    bb = True if (b == '-d') else False
    for entry in os.listdir(pat):
        if os.path.isdir(os.path.join(pat, entry)):
            f(os.path.join(pat, entry), b, w, inc, exc)
            #print(entry)
            if bb and boolean(w, entry) and inc in (os.path.join(pat, entry)) and exc not in (os.path.join(pat, entry)):
                print(os.path.join(pat, entry))
        else:
            if not bb and boolean(w, entry) and inc in (os.path.join(pat, entry)) and exc not in (os.path.join(pat, entry)):
                print(os.path.join(pat, entry))



f(input("--path: "), input("-d or -f: "), input("word or letters in word: "), input("--include : "), input("--exclude: "))

#f(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])
