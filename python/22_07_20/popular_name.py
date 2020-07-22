import re

tmp_dict = {}

def get_lines(text):
    lines = text.split('.')
    for line in lines:
        get_words(line)

def get_words(line):
    words = re.findall(r"\b[A-Z].*?\b",line)
    words = [x.upper() for x in words]
    if not words:
        return
    check_add_element_dict(words[0])
    words.pop(0)
    words = set(words)
    for word in words:
        add_element_dict(word)

def add_element_dict(key):
    if key in tmp_dict.keys():
        tmp_dict[key] = abs(tmp_dict[key])
        tmp_dict[key] += 1
    else:
        tmp_dict[key] = 1

def check_add_element_dict(key):
    if key in tmp_dict.keys():
        if tmp_dict[key] < 0:
            tmp_dict[key] -= 1
        else:
            tmp_dict[key] += 1
    else:
        tmp_dict[key] = -1

def check_dict():
    tmp = list(tmp_dict.keys())
    for key in tmp:
        if tmp_dict[key] < 0:
            tmp_dict.pop(key)



def main():
    text = input("Enter your text(Each sentence should start with Capital Letter and end with '.' symbol)===  ")
    get_lines(text)
    check_dict()
    tmp = sorted(tmp_dict.items(), key=lambda x: x[1], reverse=True)
    number = int(input("Enter a positive number ===== "))
    if number > len(tmp):
        number = len(tmp)
    for i in range(0,number):
        print(tmp[i])

if __name__ == "__main__":
    main()
