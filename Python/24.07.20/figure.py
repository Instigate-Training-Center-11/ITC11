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