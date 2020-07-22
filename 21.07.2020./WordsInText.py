n = int(input("Enter the positive number : "))
text = str(input("Enter some text : "))
words = text.split()
count_of_words = {}

''' Spliting the text '''
for word in text.split(" "):
    if len(word) > 0 and word.istitle():
        ''' Seting the word into count_of_words, if it not in count_of_words and set value to 1 '''
        if word not in count_of_words:
            count_of_words[word] = 1
        else:
            ''' Incrementing count, if the word already exsist in count_of_words '''
            count_of_words[word] += 1           
    
if len(count_of_words) < n:
    ''' Sorting the dictionary by the values, reversed, taking all items, if items are less then n'''
    for i, word in enumerate(sorted(count_of_words, key=count_of_words.get, reverse=True)):       
        print(str(i+1) + ". " +  word + " - " + str(count_of_words[word]))
else:
    ''' Sorting the dictionary by the values, reversed, taking the n top items,'''
    for i, word in enumerate(sorted(count_of_words, key=count_of_words.get, reverse=True)[:n]):
        print(str(i+1) + ". " +  word + " - " + str(count_of_words[word]))