class Player:
    """ class in represent a player in chess game """

    def __init__(self, name, color):
        self.name = name
        self.color = color

    def start_input(self):
       pass

    def move_input(self):
        pass



class Figure:
    """ This is an abstract class representing a chess piece """
    
    def __init__(self, row, col, color, board):
        self.row = row
        self.col = col
        self.color = color
        self.board = board

    def rull_muve(self):
        """ generate all the possible moves from the current position """
        pass

    def move_to(self, row, col):
        """ make a move to the given position (row, col) """
        pass


class Pawn(Figure):
    """ Pawn class represent a pawn in chess """

    def __init__(self, row, col, color, board):
        # __init__for Pawn
        super().__init__(row, col, color, board)

    def rull_muve(self):
        pass

    def move_to(self, row, col):
        pass


class Bishop(Figure):
    """ This class will represent a bishop in the chess game """

    def __init__(self, row, col, color, board):
        # __init__for Bishop
        super().__init__(row, col, color, board)

    def rull_muve(self):
        pass

    def move_to(self, row, col):
        pass


class Queen(Figure):
    """This class will represent a queen piece in chess game """

    def __init__(self, row, col, color, board):
        # __init__for Queen
        super().__init__(row, col, color, board)

    def rull_muve(self):
        pass

    def move_to(self, row, col):
        pass


class Rook(Figure):
    """ This class represent a rook in chess game """
    
    def __init__(self, row, col, color, board):
        # __init__for Rock
        super().__init__(row, col, color, board)

    def rull_muve(self):
        pass

    def move_to(self, row, col):
        pass

class Horse(Figure):
    """ This class will represent a knight piece in chess game """
  
    def __init__(self, row, col, color, board):
        # __init__for Horse
        super().__init__(row, col, color, board)

    def rull_muve(self):
        pass

    def move_to(self, row, col):
        pass


class King(Figure):
    """ This class will represent the king piece in chess game """

    def __init__(self, row, col, color, board):
        # __init__for Horse
        super().__init__(row, col, color, board)

    def rull_muve(self):
        pass

    def move_to(self, row, col):
        pass


class Board:
    """Board class represent a chessboard """
    
    def __init__(self,player_white, player_black):
        self.grid = [[None for _ in range(8)] for _ in range(8)]
        self.player_white = player_white
        self.player_black = player_black
        self._setup()

    def _setup(self):
        """ setting up the board and arranging the pieces """
        pass

    def move(self,start_row, start_col, end_row, end_col, color):
        """get a move from player and check whether it is possible or not if so do it"""
        
        pass

    def print_board(self):
        """ Print board """
        pass