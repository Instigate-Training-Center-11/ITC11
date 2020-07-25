class Chess_Board:
    def __init__(self):
        self.board = self.create_board()

    def create_board(self):
        board_x=[]

        for x in range(9):
            board_y = list("{}".format(x))
            for y in range(9):
                board_y.append('.')
            board_x.append(board_y)
        
        for i in range(1 , 9):
            board_x[2][i] = '♙'
            board_x[7][i] = '♟︎'
            board_x[0][i] = i

        board_x[8][1] = '♜'
        board_x[8][8] = '♜'
        board_x[8][2] = '♞'
        board_x[8][7] = '♞'
        board_x[8][3] = '♝'
        board_x[8][6] = '♝'
        board_x[8][4] = '♛'
        board_x[8][5] = '♚'

        board_x[1][1] = '♖'
        board_x[1][8] = '♖'
        board_x[1][2] = '♘'
        board_x[1][7] = '♘'
        board_x[1][3] = '♗'
        board_x[1][6] = '♗'
        board_x[1][4] = '♕'
        board_x[1][5] = '♔'
        return board_x


class King(Chess_Board):
    def __init__(self):
        Chess_Board.__init__(self)

    def move(self, x_start , y_start, x_end, y_end , str):
        if self.board[x_end][y_end] == '.':
            if (abs(x_start - x_end) < 2 and abs(y_start - y_end) < 2):
                self.board[x_start][y_start] = '.'
                self.board[x_end][y_end] = str
                return self.board
            else:
                print('wrong coordinates to move')
        else:
            print('wrong coordinates to move')


class Queen(Chess_Board):
    def __init__(self):
        Chess_Board.__init__(self)

    def move(self, x_start , y_start, x_end, y_end , str):
        if self.board[x_end][y_end] == '.':
            if x_start == x_end or y_start == y_end or abs(x_end - x_start) == abs(y_end - y_start):
                self.board[x_start][y_start] = '.'
                self.board[x_end][y_end] = str
                return self.board
            else:
                print('wrong coordinates to move')
        else:
            print('wrong coordinates to move')


class Ship(Chess_Board):
    def __init__(self):
        Chess_Board.__init__(self)

    def move(self, x_start , y_start, x_end, y_end , str):
        print('dhgf')
        if self.board[x_end][y_end] == '.':
            if x_start == x_end or y_start == y_end:
                self.board[x_start][y_start] = '.'
                self.board[x_end][y_end] = str
                return self.board
            else:
                print('wrong coordinates to move')
        else:
            print('wrong coordinates to move')


class Horse(Chess_Board):
    def __init__(self):
        Chess_Board.__init__(self)

    def move(self, x_start , y_start, x_end, y_end , str):
        if self.board[x_end][y_end] == '.':
            if abs(x_end - x_start) + abs(y_end - y_start) == 3:
                self.board[x_start][y_start] = '.'
                self.board[x_end][y_end] = str
                return self.board
            else:
                print('wrong coordinates to move')
        else:
            print('wrong coordinates to move')


class Elephant(Chess_Board):

    def __init__(self):
        Chess_Board.__init__(self)

    def move(self, x_start , y_start, x_end, y_end , str):
        if self.board[x_end][y_end] == '.':
            if abs(x_end - x_start) == abs(y_end - y_start):
                self.board[x_start][y_start] = '.'
                self.board[x_end][y_end] = str
                return self.board
            else:
                print('wrong coordinates to move')
        else:
            print('wrong coordinates to move')


class Solger(Chess_Board):

    def __init__(self):
        Chess_Board.__init__(self)

    def move(self, x_start , y_start, x_end, y_end , str):
        if self.board[x_end][y_end] == '.':
            if str == '♟︎':
                if x_end - x_start == -1:
                    self.board[x_start][y_start] = '.'
                    self.board[x_end][y_end] = str
                    return self.board
                else:
                    print('wrong coordinates to move')
            else:
                if x_end - x_start == 1:
                    self.board[x_start][y_start] = '.'
                    self.board[x_end][y_end] = str
                    return self.board
                else:
                    print('wrong coordinates to move')
        else:
            print('wrong coordinates to move')


class Brain(Chess_Board):

    def __init__(self):
        Chess_Board.__init__(self)
        King.__init__(self)
        Queen.__init__(self)
        Solger.__init__(self)
        Elephant.__init__(self)
        Horse.__init__(self)
        Ship.__init__(self)

    def print_board(self):
        for i in range (9):
            for j in range (9):
                print (self.board[i][j], end=' ')
            print ()

    def play_game(self):
        print('Please provide coordinates of the figure to move.')

        while True:
            x_start = int(input('provide current x coordinate ==== '))
            y_start = int(input('provide current y coordinate ==== '))
            x_end = int(input('Provide x coordinate need to move === '))
            y_end = int(input('Provide y coordinate need to move === '))

            if x_start < 0 or x_start > 8 or y_start < 0 or y_start > 8 or x_end < 0 or x_end > 8 or y_end < 0 or y_end > 8:
                print('wrong coordinates to move')
                continue
            
            if self.board[x_start][y_start] == '♔':
                King.move(x_start, y_start, x_end, y_end, '♔')
            elif self.board[x_start][y_start] == '♚':
                King.move(x_start, y_start, x_end, y_end, '♚')

            elif self.board[x_start][y_start] == '♛':
                Queen.move(self,x_start, y_start, x_end, y_end, '♛')
            elif self.board[x_start][y_start] == '♕':
                Queen.move(self,x_start, y_start, x_end, y_end, '♕')

            elif self.board[x_start][y_start] == '♖':
                Ship.move(self,x_start, y_start, x_end, y_end, '♖')
            elif self.board[x_start][y_start] == '♜':
                Ship.move(self, x_start, y_start, x_end, y_end, '♜')

            elif self.board[x_start][y_start] == '♝':
                Elephant.move(self,x_start, y_start, x_end, y_end, '♝')
            elif self.board[x_start][y_start] == '♗':
                Elephant.move(self,x_start, y_start, x_end, y_end, '♗')

            elif self.board[x_start][y_start] == '♘':
                Horse.move(self,x_start, y_start, x_end, y_end, '♘')
            elif self.board[x_start][y_start] == '♞':
                Horse.move(self,x_start, y_start, x_end, y_end, '♞')

            elif self.board[x_start][y_start] == '♟︎':
                Solger.move(self,x_start, y_start, x_end, y_end, '♟︎')
            elif self.board[x_start][y_start] == '♙':
                Solger.move(self,x_start, y_start, x_end, y_end, '♙')

            else:
                print('wrong coordinates to move')

            self.print_board()


def main():
    a=Brain()
    a.print_board()
    a.play_game()

if __name__ == "__main__":
    main()


