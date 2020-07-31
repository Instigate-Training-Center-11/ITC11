import figure
import board
import string

new_board = board.Board()

#|♟|♞|♝|♜|♛|♚|♙|♘|♗|♖|♕|♔|

black_pown = []
white_pown = []
black_rook = []
white_rook = []
black_knight = []
white_knight = []
black_bishop = []
white_bishop = []

for i in range(0, 8):
    black_pown.append(figure.Figure(1, i, "♟"))
    board.move(new_board.board, 1, i, "♟")
    white_pown.append(figure.Figure(6, i, "♙"))
    board.move(new_board.board, 6, i, "♙")
for i in range(0, 8, 7):
    black_rook.append(figure.Figure(0, i, "♜"))
    board.move(new_board.board, 0, i, "♜")
    white_rook.append(figure.Figure(7, i, "♖"))
    board.move(new_board.board, 7, i, "♖")
for i in range(1, 8, 5):
    black_knight.append(figure.Figure(0, i, "♞"))
    board.move(new_board.board, 0, i, "♞")
    white_knight.append(figure.Figure(7, i, "♘"))
    board.move(new_board.board, 7, i, "♘")
for i in range(2, 8, 3):
    black_bishop.append(figure.Figure(0, i, "♝"))
    board.move(new_board.board, 0, i, "♝")
    white_bishop.append(figure.Figure(7, i, "♗"))
    board.move(new_board.board, 7, i, "♗")

black_king = figure.Figure(0, 3, "♛")
board.move(new_board.board, 0, 3, "♛")
white_king = figure.Figure(7, 4, "♕")
board.move(new_board.board, 7, 4, "♕")

black_queen = figure.Figure(0, 4, "♚")
board.move(new_board.board, 0, 4, "♚")
white_queen = figure.Figure(7, 3, "♔")
board.move(new_board.board, 7, 3, "♔")

is_exit = False

while is_exit == False:
    board.print_board(new_board.board)
    print("Please insert some figure cordinates.(Example: A and 2)")
    cordinate_y = ord(input("First cordinate: ")) - 65
    cordinate_x = int(input("Second cordinate: ")) - 1
    new_y = ord(input("New first cordinate: ")) - 65
    new_x = int(input("New second cordinate: ")) - 1

    simvol = board.check(new_board.board, cordinate_x, cordinate_y)

    if simvol == '.':
        print("Empty")
    else:
        if simvol == '♟':
            for i in range(0, 8):
                current_x = black_pown[i].get_x()
                current_y = black_pown[i].get_y()
                if current_x == cordinate_x and current_y == cordinate_y:
                    black_pown[i].set_x_y(current_x, current_y)
                    board.remove(new_board.board, current_x, current_y)
                    board.move(new_board.board, new_x, new_y, "♟")

    ##TO_DO

