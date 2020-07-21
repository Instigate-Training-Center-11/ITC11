def count(s, c):
    line = 0
    bo = {}
    m = {}
    st = str(s).split("\n")
    for j in st:
        k = j.split()
        if not k[0][0].islower() and k[0].upper() not in m:
            continue
        for i in k:
            if not i[0].islower() and (i.upper() in bo and bo[i.upper()] != line or i.upper() not in bo):
                if i.upper() in m:
                    m[i.upper()] += 1
                    bo[i.upper()] = line
                else:
                    m[i.upper()] = 1
                    bo[i.upper()] = line
        line += 1
    result = sorted(m.items(), key = lambda x: x[1], reverse = True)

    #print(m)
    #print(result)
    if c > len(result):
        c = len(result)
    for i in range(0, c):
        print(result[i][0], end="")
        print(" : ", end="")
        print(result[i][1])



def main():
    st = "AS\njkn Jk  JK As AS lknmlkjn as\n As JK JK jk AS\n As AS As AS \n AS As Wq"
    count(st, 5)


main()

