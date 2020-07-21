import re
tmp={}
def add_dict(key):
    if key in tmp.keys():
        tmp[key] += 1
    else:
        tmp[key] = 1


def get_dict(key):
    if key[0] == '.' and key in tmp.keys():
        add_dict(key)
    elif key[0] != '.':
        add_dict(key)
    else:
        return



def main():
    #text == Amen naxadasutjan skizb kpac petqe lini .-in or  tux.linux
    text = input("enter your text === '/n'")
    list_1 =re.findall(r"\b[.^]?[A-Z].*?\b",text)
    list_1 = [x.upper() for x in list_1]
    for i in range(1,len(list_1)):
        get_dict(list_1[i])
    print(tmp)



if __name__ == "__main__":
    main()