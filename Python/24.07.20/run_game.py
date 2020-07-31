from figure import *
from board import *
import string
import os

# Check moves for different figures
def check_move(current_white_figure,current_black_figure, new_x, new_y, cordinate_x, cordinate_y, count):
    for i in range(0, count):
        black_x = current_black_figure[i].get_x()
        black_y = current_black_figure[i].get_y()
        white_x = current_white_figure[i].get_x()
        white_y = current_white_figure[i].get_y()
        if black_x == cordinate_x and black_y == cordinate_y:
                if current_black_figure[i].safe_move(new_x, new_y):
                    current_black_figure[i].set_x_y(new_x, new_y)
                    move(new_board.board, black_x, black_y, ' ')
                    move(new_board.board, new_x, new_y, current_black_figure[i].get_simvol())
                    print("Nice move for:", end = " ")
                    print(current_black_figure[i].get_simvol())
                else:
                    print("No such move for:", end = " ")
                    print(current_black_figure[i].get_simvol())
        elif white_x == cordinate_x and white_y == cordinate_y:
                if current_white_figure[i].safe_move(new_x, new_y):
                    current_white_figure[i].set_x_y(new_x, new_y)
                    move(new_board.board, white_x, white_y, ' ')
                    move(new_board.board, new_x, new_y, current_white_figure[i].get_simvol())
                    print("Nice move for:", end = " ")
                    print(current_white_figure[i].get_simvol())
                else:
                    print("No such move for:", end = " ")
                    print(current_white_figure[i].get_simvol())

new_board = Board()

#|♟|♞|♝|♜|♛|♚|♙|♘|♗|♖|♕|♔|
# Create lists for chess figure objects
black_pown = []
white_pown = []
black_rook = []
white_rook = []
black_knight = []
white_knight = []
black_bishop = []
white_bishop = []
black_king = []
white_king = []
black_queen = []
white_queen = []

# Painting figures in the board
for i in range(0, 8):
    black_pown.append(Pown(1, i, "♟"))
    move(new_board.board, 1, i, "♟")
    white_pown.append(Pown(6, i, "♙"))
    move(new_board.board, 6, i, "♙")
for i in range(0, 8, 7):
    black_rook.append(Rook(0, i, "♜"))
    move(new_board.board, 0, i, "♜")
    white_rook.append(Rook(7, i, "♖"))
    move(new_board.board, 7, i, "♖")
for i in range(1, 8, 5):
    black_knight.append(Knight(0, i, "♞"))
    move(new_board.board, 0, i, "♞")
    white_knight.append(Knight(7, i, "♘"))
    move(new_board.board, 7, i, "♘")
for i in range(2, 8, 3):
    black_bishop.append(Bishop(0, i, "♝"))
    move(new_board.board, 0, i, "♝")
    white_bishop.append(Bishop(7, i, "♗"))
    move(new_board.board, 7, i, "♗")

black_king.append(King(0, 3, "♛"))
move(new_board.board, 0, 3, "♛")
white_king.append(King(7, 4, "♕"))
move(new_board.board, 7, 4, "♕")

black_queen.append(Queen(0, 4, "♚"))
move(new_board.board, 0, 4, "♚")
white_queen.append(Queen(7, 3, "♔"))
move(new_board.board, 7, 3, "♔")

# Start game
is_exit = False
os.system('cls' if os.name == 'nt' else 'clear')
print("Good luck!!!")
while is_exit == False:
    print_board(new_board.board)
    print("Please insert some figure cordinates.(Example: A and 2)")
    cordinate_y = ord(input("First cordinate: ")) - 65
    cordinate_x = int(input("Second cordinate: ")) - 1
    new_y = ord(input("New first cordinate: ")) - 65
    new_x = int(input("New second cordinate: ")) - 1

    simvol = check(new_board.board, cordinate_x, cordinate_y)
    os.system('cls' if os.name == 'nt' else 'clear')
    if simvol == '.':
        print("Empty")
    else:
        if simvol == '♟' or simvol == '♙':
            check_move(white_pown, black_pown, new_x, new_y, cordinate_x, cordinate_y, 8)
        elif simvol == '♜' or simvol == '♖':
            check_move(black_rook, white_rook, new_x, new_y, cordinate_x, cordinate_y, 2)
        elif simvol == '♞' or simvol == '♘':
            check_move(black_knight, white_knight, new_x, new_y, cordinate_x, cordinate_y, 2)
        elif simvol == '♝' or simvol == '♗':
            check_move(black_bishop, white_bishop, new_x, new_y, cordinate_x, cordinate_y, 2)
        elif simvol == '♛' or simvol == '♕':
            check_move(black_king, white_king, new_x, new_y, cordinate_x, cordinate_y, 1)
        elif simvol == '♚' or simvol == '♔':
            check_move(black_queen, white_queen, new_x, new_y, cordinate_x, cordinate_y, 1)