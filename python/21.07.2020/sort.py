simple_dictionary = [['az3', '34', '54'],
                    ['mi2', 'jog', 'mid'],
                    ['x5', '45', '27'],
                    ['a1', 'alps', 'cow'],
                    ['a1', 'alps', 'blow']]

def display_dictionary(simple_dictionary):
    for i in simple_dictionary:
        print(i)

def sort_numbers_line(simple_dictionary):
    simple_dictionary.sort(key=lambda x: x[0])
    simple_dictionary.sort(key=lambda x: x[1])

def list_reverse(simple_dictionary):
    simple_dictionary.reverse()


for line in simple_dictionary:
    for i in line:
        print(i)
    break
#display_dictionary(simple_dictionary)
#sort_numbers_line(simple_dictionary)
#list_reverse(simple_dictionary)
#temp = []
#temp.append(simple_dictionary.pop())
#temp.append(simple_dictionary.pop())
#list_reverse(temp)
#print(temp)
#list_reverse(simple_dictionary)
#print("================================")
#simple_dictionary.append(temp[0])
#simple_dictionary.append(temp[1])
#display_dictionary(simple_dictionary)
#temp_dictionary = simple_dictionary