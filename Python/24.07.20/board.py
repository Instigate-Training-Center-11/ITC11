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
    if len(board[x][y]) > 3 and board[x][y][11] == '.':
        board[x][y] = board[x][y][:11] + simvol1 + board[x][y][11 + 1:]
    else:
        board[x][y] = board[x][y][:1] + simvol1 + board[x][y][1 + 1:]

def remove(board, x, y):
    if len(board[x][y]) > 3:
        board[x][y] = board[x][y][:11] + '.' + board[x][y][11 + 1:]
    else:
        board[x][y] = board[x][y][:1] + '.' + board[x][y][1 + 1:]

def check(board, x, y):
    if len(board[x][y]) > 3:
        return board[x][y][11]
    else:
        return board[x][y][1]

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
