import os


def f(pat, b, w, inc, exc):
    bb = True if (b == '-d') else False
    for entry in os.listdir(pat):
        if os.path.isdir(os.path.join(pat, entry)):
            f(os.path.join(pat, entry), b, w, inc, exc)
            if bb and w in entry and inc in (os.path.join(pat, entry)) and exc not in (os.path.join(pat, entry)):
                print(os.path.join(pat, entry))
        else:
            if not bb and w in entry and inc in (os.path.join(pat, entry)) and exc not in (os.path.join(pat, entry)):
                print(os.path.join(pat, entry))


f(input("--path: "), input("-d or -f: "), input("word or letters in word: "), input("--include : "), input("--exclude: "))


