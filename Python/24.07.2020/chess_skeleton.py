""" The Sceleton of a Chess Game """
""" Create Board For Chess Player """
class Board:
    def __init__(self):
        self.board = [[Empty()] * 8 for coordinate in range(8)]

    def board_color(self, i, j):
        return self.board[i][j].color

    def desplay_board(self):
        pass

    def coordinate(self, prev_coordinate, current_coordinate):
        self.board[current_coordinate[1]][current_coordinate[0]] = self.board[prev_coordinate[1]][prev_coordinate[0]]
        self.board[prev_coordinate[1]][prev_coordinate[0]] = Empty()

""" Create Chess Figures """
class Figure:
    def __init__(self, name, colour, i, j):
        self.name = name
        self.color = color
        self.i = i
        self.j = j

    def step(self):
        pass

class King(Figure):
    def __init__(self, name, colour, i, j):
        super().__init__(name, colour, i, j)

    def step(self):
        pass

class Queen(Figure):
    def __init__(self, name, colour, i, j):
        super().__init__(name, colour, i, j)

    def step(self):
        pass

class Bishop(Figure):
    def __init__(self, name, colour, i, j):
        super().__init__(name, colour, i, j)

    def step(self):
        pass

class Knight(Figure):
    def __init__(self, name, colour, i, j):
        super().__init__(name, colour, i, j)

    def step(self):
        pass

class Rook(Figure):
    def __init__(self, name, colour, i, j):
        super().__init__(name, colour, i, j)

    def step(self):
        pass

class Pawn(Figure):
    def __init__(self, name, colour, i, j):
        super().__init__(name, colour, i, j)

    def step(self):
        pass

""" Create Chess Player """
class Player:
    def __init__(self, color, name, score):
        self.color = color
        self.name = name
        self.score = score

    def place_figure(self):
        pass

class Game:
    def __init__(self, white_player, black_player):
        self.white_player = Player('White')
        self.black_player = Player('Black')

    def start_game(self):
        pass