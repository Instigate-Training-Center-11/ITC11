def sortFirstInteger(a, b):
    aa = str(a)
    bb = str(b)
    if len(a) > len(b):
        return True
    aaa = 0
    bbb = 0
    for i in range(0, len(a)):
        if a[i].isdigit():
            aaa += int(a[i])
        if b[i].isdigit():
            bbb += int(b[i])
    if aaa > bbb:
        return True

    aaaa = ""
    bbbb = ""
    for i in range(0, len(a)):
        if not a[i].isdigit():
            aaaa += a[i]
        if not b[i].isdigit():
            bbbb += b[i]
    return aaaa > bbbb

def sortFirstString(a, b):
    aa = str(a)
    bb = str(b)
    if len(a) > len(b):
        return True

    aaaa = ""
    bbbb = ""
    for i in range(0, len(a)):
        if not a[i].isdigit():
            aaaa += a[i]
        if not b[i].isdigit():
            bbbb += b[i]
    return aaaa > bbbb

    aaa = 0
    bbb = 0
    for i in range(0, len(a)):
        if a[i].isdigit():
            aaa += int(a[i])
        if b[i].isdigit():
            bbb += int(b[i])
    if aaa > bbb:
        return True


def sortt(st):
    string = []
    integer = []
    lines = str(st).split("\n")
    for line in lines:
        b = True
        words = line.split(" ")
        for wordIndex in range(1, len(words)):
            if not words[wordIndex].isdigit():
                b = False
        if b:
            integer.append(line)
        else:
            string.append(line)

    for i in range(0, len(string)):
        for j in range(0, len(string)):
            aa = string[i].split(" ")
            bb = string[j].split(" ")
            if not sortFirstString(aa[0], bb[0]):
                temp = string[j]
                string[j] = string[i]
                string[i] = temp


    for i in range(0, len(integer)):
        for j in range(0, len(integer)):
            aa = integer[i].split(" ")
            bb = integer[j].split(" ")
            if not sortFirstInteger(aa[0], bb[0]):
                temp = integer[j]
                integer[j] = integer[i]
                integer[i] = temp

    for i in string:
        print(i)
    for j in integer:
        print(j)




sortt("c3 22 33 44\na4 22 33 44\na3 sf5 dds 547\nb2 4l 13 99")
