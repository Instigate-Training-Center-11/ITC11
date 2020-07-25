def input_number(message):
    while True:
        try:
            user_input = int(input(message))
        except ValueError:
            print("Not an integer! Try again.")
            continue
        else:
            return user_input
            break

def search_by_key(data, count):
    text = replace_by_symbol(data)
    line_data = set()
    list_data = {}

    for i in text.split('.',1000):
        change_in_upper(i,line_data)
        for world in line_data:
            if world in list_data:
                list_data[world] += 1
            else:
                list_data.update(dict({world : 1}))
        line_data.clear()

    list_data = sorted(list_data.items(), key=lambda x: x[1], reverse=True)

    if count > len(list_data):
        for i in range(0,len(list_data)):
            print(list_data[i][0], " = ",list_data[i][1])
    else:
        for i in range(0,count):
            print(list_data[i][0], " = ",list_data[i][1])

def change_in_upper(line,line_data):
    list_world = (split_by_space(line))
    for world in list_world:
        if world != '':
            if world.isalpha() and world.istitle() or world.isupper():
                line_data.add(world.upper())


def replace_by_symbol(text):
    try:
        temp = text.replace(',',' ')
    except SomeException:
        tb = sys.exc_info()[2]
        raise OtherException(...).with_traceback(tb)
    else:
        return temp

def split_by_space(text):
    try:
        temp = text.split(' ',1000)
    except SomeException:
        tb = sys.exc_info()[2]
        raise OtherException(...).with_traceback(tb)
    else:
        return temp

def main():
    text = input("Input your text... ")
    print("text  " + text + "\n")
    count = input_number("Input number positive number ")
    search_by_key(text,count)

if __name__ == "__main__":
    main()