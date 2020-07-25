"""Create chessboard"""
class Board:
    def __init__(self):
        self.board = [[Empty()] * 8 for y in range(8)]

    def get_color(self, s, e):
        return self.board[e][s].color

    def get_moves(self, s, e):
        return self.board[e][s].get_moves(self, s, e)

    def move(self, s_e_from, s_e_to):
        self.board[s_e_to[1]][s_e_to[0]] = self.board[s_e_from[1]][s_e_from[0]]
        self.board[s_e_from[1]][s_e_from[0]] = Empty()

    def __str__(self):
        res = ''
        for e in range(8):
            res += '' . join(map(str, self.board[e])) + "\n"
        return res

    def print_board(self):
        pass

"""Create figures"""
class Figure:
    def __init__(self, s, e, color, name):
        self.s = s
        self.e = e
        self.name = name
        self.color = color

    def move(self):
        pass

class King(Figure):
    def __init__(self, s, e, color, name):
        super().__init__(s, e, color, name)

    def move(self):
        pass

class Queen(Figure):
    def __init__(self, s, e, color, name):
        super().__init__(s, e, color, name)

    def move(self):
        pass

class Pawn(Figure):
    def __init__(self, s, e, color, name):
        super().__init__(s, e, color, name)

    def move(self):
        pass

class Bishop(Figure):
    def __init__(self, s, e, color, name):
        super().__init__(s, e, color, name)

    def move(self):
        pass

class Knight(Figure):
    def __init__(self, s, e, color, name):
        super().__init__(s, e, color, name)

    def move(self):
        pass

class Rook(Figure):
    def __init__(self, s, e, color, name):
        super().__init__(s, e, color, name)

    def move(self):
        pass

"""Create player"""
class Player:
    def __init__(self, name, color, score):
        self.name = name
        self.color = color
        self.score = score
        self.msg = ""

    def place_figure(self):
        pass

    def start_game(self):
        pass

    def move_input(self):
        pass

    def is_check(self):
        pass

    def select_figure(self, color):
        pass
