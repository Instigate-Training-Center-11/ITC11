import re

"""Declare dictionary"""
word_count={}

""" Count the Words"""
def count(word):
    if word not in word_count.keys():
        word_count[word] = 1
    else:
        word_count[word] += 1

"""Get count the Words"""
def get_count(word):
    if word[0] != '.' or word[0] == '.' and word in word_count.keys():
        count(word)
    else:
        return

def main():
    text = str(input("Enter some text\n"))
    words = re.findall(r"\b[.^]?[A-Z].*?\b",text)
    words = [letter.title() for letter in words]
    for i in range(1,len(words)):
        get_count(words[i])
    print(word_count)

if __name__ == "__main__":
    main()
