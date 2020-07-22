def count(s, c):
    line = 0
    bo = {}
    m = {}
    st = str(s).split("\n")
    for j in st:
        k = j.split()
        for i in k:
            if not i[0].islower() and not i[0].isdigit() and (i.upper() in bo and bo[i.upper()] != line or i.upper() not in bo):
                if i.upper() in m:
                    m[i.upper()] += 1
                    bo[i.upper()] = line
                else:
                    m[i.upper()] = 1
                    bo[i.upper()] = line
        line += 1
    result = sorted(m.items(), key = lambda x: x[1], reverse = True)
    #print(result)
    if c > len(result):
        c = len(result)
    for i in range(0, c):
        print(result[i][0], end="")
        print(" : ", end="")
        print(result[i][1])



def main():
    st = "Linux was originally developed for personal computers based on the Intel x86 architecture, but has since been ported to more platforms than any other operating system.\n Because of the dominance of Android on smartphones, Linux also has the largest installed base of all general-purpose operating systems.\n Although it is used by only around 2.3 percent of desktop computers, the Chromebook, which runs the Linux kernel-based Chrome OS, dominates the US K–12 education market and represents nearly 20 percent of sub-$300 notebook sales in the US.\n Linux is the leading operating system on servers (over 96.4% of the top 1 million web servers' operating systems are Linux)․"
    count(st, 20)
    count(input("string : "), int(input("count :")))


main()

