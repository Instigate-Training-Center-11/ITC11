class Figure:
    def __init__(self, x, y, name, color):
        self.x = x
        self.y = y
        self.color = color
        self.name = name

    def move(self):
        pass


class Bishop(Figure):
    def __init__(self, x, y, color, name):
        super().__init__(x, y, color, name)

    def move(self):
        pass


class Pawn(Figure):
    def __init__(self, x, y, color, name):
        super().__init__(x, y, color, name)

    def move(self):
        pass


class Knight(Figure):
    def __init__(self, x, y, color, name):
        super().__init__(x, y, color, name)

    def move(self):
        pass


class King(Figure):
    def __init__(self, x, y, color, name):
        super().__init__(x, y, color, name)

    def move(self):
        pass


class Queen(Figure):
    def __init__(self, x, y, color, name):
        super().__init__(x, y, color, name)

    def move(self):
        pass


class Rook(Figure):
    def __init__(self, x, y, color, name):
        super().__init__(x, y, color, name)

    def move(self):
        pass


class Board:
    def __init__(self):
        self.board = [[Empty()] * 8 for y in range(8)]

    def get_color(self, x, y):
        return self.board[y][x].color

    def get_moves(self, x, y):
        return self.board[y][x].get_moves(self, x, y)

    def move(self, xy_from, xy_to):
        self.board[xy_to[1]][xy_to[0]] = self.board[xy_from[1]][xy_from[0]]
        self.board[xy_from[1]][xy_from[0]] = Empty()

    def __str__(self):
        res = ''
        for y in range(8):
            res += '' . join(map(str, self.board[y])) + "\n"
        return res

    def print_board(self):
        pass 


class Gamer:
    def __init__(self, name, color, score):
        self.name = name
        self.color = color
        self.score = score
        self.message = ""

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