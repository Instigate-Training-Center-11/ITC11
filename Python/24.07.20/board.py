import os

class Board:
    __simvol = "."
    __black = " " + __simvol + " "
    __white = "\033[30m\033[47m " + __simvol + " \033[0m"
    board = [[__white, __black, __white, __black, __white, __black, __white, __black],
             [__black, __white, __black, __white, __black, __white, __black, __white],
             [__white, __black, __white, __black, __white, __black, __white, __black],
             [__black, __white, __black, __white, __black, __white, __black, __white],
             [__white, __black, __white, __black, __white, __black, __white, __black],
             [__black, __white, __black, __white, __black, __white, __black, __white],
             [__white, __black, __white, __black, __white, __black, __white, __black],
             [__black, __white, __black, __white, __black, __white, __black, __white]]

def move(board, x, y, simvol1):
    index = board[x][y].find(".")
    board[x][y] = board[x][y][:index] + simvol1 + board[x][y][index+1:]

def print_board(board):
    os.system('cls' if os.name == 'nt' else 'clear')
    print("   A  B  C  D  E  F  G  H")

    print(" +------------------------+")

    for i in range(0, 8):
        print(str(i + 1) + '|', end = "")
        for j in range(0, 8):
            print(board[i][j], end = "")
        print('|',end = str(i + 1) + '\n')

    print(" +------------------------+")

    print("   A  B  C  D  E  F  G  H")
