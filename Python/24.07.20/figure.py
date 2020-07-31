class Figure:
    __board_simvol = ""
    __cordinate_x = 0
    __cordinate_y = 0

    def __init__(self,  x, y, board_simvol):
        self.__board_simvol = board_simvol
        self.__cordinate_x = x
        self.__cordinate_y = y

    def get_color(self):
        return self.__color

    def get_x(self):
        return self.__cordinate_x

    def get_y(self):
        return self.__cordinate_y

    def set_x_y(self, x, y):
        self.__cordinate_x = x
        self.__cordinate_y = y

    def get_simvol(self):
        return self.__board_simvol

class Pown(Figure):
    def __init__(self, x, y, board_simvol):
        super().__init__(x, y, board_simvol)

    def safe_move(self, new_x, new_y):
        if self._Figure__cordinate_y != new_y or abs(self._Figure__cordinate_x - new_x) > 2:
            return False
        else:
            return True

class Rook(Figure):
    def __init__(self, x, y, board_simvol):
        super().__init__(x, y, board_simvol)

    def safe_move(self, new_x, new_y):
        if self._Figure__cordinate_y == new_y or self._Figure__cordinate_x == new_x:
            return True
        else:
            return False

class Knight(Figure):
    def __init__(self, x, y, board_simvol):
        super().__init__(x, y, board_simvol)

    def safe_move(self, new_x, new_y):
        if abs(self._Figure__cordinate_y - new_y) != 2 and abs(self._Figure__cordinate_y - new_y) != 1 or abs(self._Figure__cordinate_x - new_x) != 2 and abs(self._Figure__cordinate_x - new_x) != 1:
            return False
        else:
            return True

class Bishop(Figure):
    def __init__(self, x, y, board_simvol):
        super().__init__(x, y, board_simvol)

    def safe_move(self, new_x, new_y):
        if self._Figure__cordinate_y == new_y or self._Figure__cordinate_x == new_x:
            return False
        else:
            return True

class King(Figure):
    def __init__(self, x, y, board_simvol):
        super().__init__(x, y, board_simvol)

    def safe_move(self, new_x, new_y):
        if abs(self._Figure__cordinate_y - new_y) > 1 or abs(self._Figure__cordinate_x - new_x) > 1:
            return False
        else:
            return True

class Queen(Figure):
    def __init__(self, x, y, board_simvol):
        super().__init__(x, y, board_simvol)

    def safe_move(self, new_x, new_y):
        if (self._Figure__cordinate_y == new_y or self._Figure__cordinate_x == new_x) or (self._Figure__cordinate_y != new_y or self._Figure__cordinate_x != new_x):
            return True
        else:
            return False