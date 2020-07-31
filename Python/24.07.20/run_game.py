import figure
import board
import string

def check_move(current_white_figure,current_black_figure, new_x, new_y, cordinate_x, cordinate_y, count):
    for i in range(0, count):
        black_x = current_black_figure[i].get_x()
        black_y = current_black_figure[i].get_y()
        white_x = current_white_figure[i].get_x()
        white_y = current_white_figure[i].get_y()
        if black_x == cordinate_x and black_y == cordinate_y:
                if current_black_figure[i].safe_move(new_x, new_y):
                    current_black_figure[i].set_x_y(new_x, new_y)
                    board.move(new_board.board, black_x, black_y, ' ')
                    board.move(new_board.board, new_x, new_y, current_black_figure[i].get_simvol())
        elif white_x == cordinate_x and white_y == cordinate_y:
                if current_white_figure[i].safe_move(new_x, new_y):
                    current_white_figure[i].set_x_y(new_x, new_y)
                    board.move(new_board.board, white_x, white_y, ' ')
                    board.move(new_board.board, new_x, new_y, current_white_figure[i].get_simvol())

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
black_king = []
white_king = []
black_queen = []
white_queen = []

for i in range(0, 8):
    black_pown.append(figure.Pown(1, i, "♟"))
    board.move(new_board.board, 1, i, "♟")
    white_pown.append(figure.Pown(6, i, "♙"))
    board.move(new_board.board, 6, i, "♙")
for i in range(0, 8, 7):
    black_rook.append(figure.Rook(0, i, "♜"))
    board.move(new_board.board, 0, i, "♜")
    white_rook.append(figure.Rook(7, i, "♖"))
    board.move(new_board.board, 7, i, "♖")
for i in range(1, 8, 5):
    black_knight.append(figure.Knight(0, i, "♞"))
    board.move(new_board.board, 0, i, "♞")
    white_knight.append(figure.Knight(7, i, "♘"))
    board.move(new_board.board, 7, i, "♘")
for i in range(2, 8, 3):
    black_bishop.append(figure.Bishop(0, i, "♝"))
    board.move(new_board.board, 0, i, "♝")
    white_bishop.append(figure.Bishop(7, i, "♗"))
    board.move(new_board.board, 7, i, "♗")

black_king.append(figure.King(0, 3, "♛"))
board.move(new_board.board, 0, 3, "♛")
white_king.append(figure.King(7, 4, "♕"))
board.move(new_board.board, 7, 4, "♕")

black_queen.append(figure.Queen(0, 4, "♚"))
board.move(new_board.board, 0, 4, "♚")
white_queen.append(figure.Queen(7, 3, "♔"))
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

    ##TO_DO