import abc

class Color(object):
    BLACK = 1
    WHITE = 2
    EMPTY = 0

    '''The classmethod() method returns a class method for the given function'''
    @classmethod
    def invert(cls, color):
        if color == cls.EMPTY:
            return color
        return cls.BLACK if color == cls.WHITE else cls.WHITE

''' Class Figure for figures '''
class Figure(object):

    CODE = None
    VALUE = None
    WHITE_IMG = None
    BLACK_IMG = None

    color = None

    def __init__(self, color):
        self.color = color

    @abc.abstractmethod
    def get_moves(self, board, x, y):
        return []

    def enemy_color(self):
        return Color.invert(self.color)

    def __str__(self):
        return self.WHITE_IMG if self.color == Color.WHITE else self.BLACK_IMG

''' Class for inserting images of king from unicode'''
class FigureKing(Figure):
    CODE = 'king'
    VALUE = 0
    WHITE_IMG = '♔'
    BLACK_IMG = '♚'

    def get_moves(self, board, x, y):
        moves = []
        for j in (y-1, y, y+1):
            for i in (x-1, x, x+1):
                if i == x and j == y:
                    continue
                if 0 <= i <= 7 and 0 <= j <= 7 and board.get_color(i, j) != self.color:
                    moves.append([i, j])
        return moves

''' Class for inserting images of pown from unicode'''
class FigurePawn(Figure):
    CODE = 'pawn'
    VALUE = 10
    WHITE_IMG = '♙'
    BLACK_IMG = '♟'

    def get_moves(self, board, x, y):
        moves = []
        y += -1 if self.color == Color.WHITE else 1
        if y == -1 or y == 8:
            return moves
        if x > 0 and board.get_color(x-1, y) == self.enemy_color():
            moves.append([x-1, y])
        if x < 7 and board.get_color(x+1, y) == self.enemy_color():
            moves.append([x+1, y])
        if board.is_empty(x, y):
            moves.append([x, y])
            if self.color == Color.WHITE and y == 5 and board.is_empty(x, y-1):
                moves.append([x, y-1])
            if self.color == Color.BLACK and y == 2 and board.is_empty(x, y+1):
                moves.append([x, y+1])
        return moves

''' Class for inserting images of rook from unicode'''
class FigureRook(Figure):
    CODE = 'rook'
    VALUE = 50
    WHITE_IMG = '♖'
    BLACK_IMG = '♜'

    def get_moves(self, board, x, y):
        moves = []
        for j in (-1, 1):
            i = x + j
            while 0 <= i <= 7:
                color = board.get_color(i, y)
                if color == self.color:
                    break
                moves.append([i, y])
                if color != Color.EMPTY:
                    break
                i += j
        for j in (-1, 1):
            i = y + j
            while 0 <= i <= 7:
                color = board.get_color(x, i)
                if color == self.color:
                    break
                moves.append([x, i])
                if color != Color.EMPTY:
                    break
                i += j
        return moves

''' Class for inserting images of quin from unicode'''
class FigureQuin(Figure):
    CODE = 'quin'
    VALUE = 90
    WHITE_IMG = '♕'
    BLACK_IMG = '♛'

    def get_moves(self, board, x, y):
        moves = []
        # code
        return moves

''' Class for inserting images of knight unicode'''
class FigureKnight(Figure):
    CODE = 'knight'
    VALUE = 30
    WHITE_IMG = '♘'
    BLACK_IMG = '♞'

    def get_moves(self, board, x, y):
        moves = []
        # code
        return moves

''' Class for inserting images of bishop from unicode'''
class FigureBishop(Figure):
    CODE = 'bishop'
    VALUE = 30
    WHITE_IMG = '♗'
    BLACK_IMG = '♝'

    def get_moves(self, board, x, y):
        moves = []
        # code
        return moves

''' Class for creating board of chess 8X8 will be matrix '''
class Chessboard(object):
    SPACE_COLOR_WHITE = 0
    SPACE_COLOR_BLACK = 240

    board = None

    def fill(self):
        board = self.board = [[EmptyCell() for x in range(8)]
                              for y in range(8)]
        black = Color.BLACK
        white = Color.WHITE

        ''' Setting simple start position on the board'''
        board[0][0] = FigureRook(white)
        board[0][1] = FigureKnight(white)
        board[0][2] = FigureBishop(white)
        board[0][3] = FigureKing(white)

        board[0][4] = FigureQuin(white)
        board[0][5] = FigureBishop(white)
        board[0][6] = FigureKnight(white)
        board[0][7] = FigureRook(white)

        for i in range(len(board[1])):
            board[1][i] = FigurePawn(white)

        for i in range(len(board[6])):
            board[6][i] = FigurePawn(black)

        board[7][0] = FigureRook(black)
        board[7][1] = FigureKnight(black)
        board[7][2] = FigureBishop(black)
        board[7][3] = FigureKing(black)

        board[7][4] = FigureQuin(black)
        board[7][5] = FigureBishop(black)
        board[7][6] = FigureKnight(black)
        board[7][7] = FigureRook(black)

    def clone(self):
        cb = Chessboard()
        cb.board = [self.board[i][:] for i in range(8)]
        return cb

    def get_Figure(self, x, y):
        return self.board[y][x]

    def get_color(self, x, y):
        return self.get_Figure(x, y).color

    def get_Figure_moves(self, x, y):
        return self.get_Figure(x, y).get_moves(self, x, y)

    def move_Figure(self, xy_from, xy_to):
        captured = self.board[xy_to[1]][xy_to[0]]
        self.board[xy_to[1]][xy_to[0]] = self.board[xy_from[1]][xy_from[0]]
        self.board[xy_from[1]][xy_from[0]] = EmptyCell()
        return captured

    ''' Check: Is the next fild empty? '''
    def is_empty(self, x, y):
        return self.get_Figure(y, x).CODE == 'empty'

    def __str__(self):
        res = " a b c d e f g h\n"
        for y in range(8):
            res += "\033[0m" + str(8 - y)
            for x in range(8):
                color = self.SPACE_COLOR_BLACK if (
                    x + y) % 2 else self.SPACE_COLOR_WHITE
                res += '\033[48;5;%sm%s ' % (color, self.board[y][x])
            res += "\n"
        res += "\033[0m"
        return res

class EmptyCell(object):
    CODE = 'empty'
    color = Color.EMPTY

    def get_moves(self, board, x, y):
        raise Exception('Error!')

    def __str__(self):
        return ' '

class Game(object):
    @staticmethod
    def clear_screen():
        print("\033[2J\033[1;3H\033[14;0m")

    def __init__(self):
        cb = Chessboard()
        cb.fill()

        self.clear_screen()
        print(cb)
        color = Color.WHITE
        xy_from = xy_to = None
        if not xy_from:
            print('end')
            exit()
            cb.move_Figure(xy_from, xy_to)
            color = Color.invert(color)
            self.clear_screen()
            print(cb)


Game()
