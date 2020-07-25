WHITE = "white"
BLACK = "black"


class Cell:
    # def __init__(self, figure, color, number, letter):
    def __init__(self):
        self.color = None
        self.figure = None
        self.number = None
        self.letter = None


class Figure:
    def __init__(self, image, color):
        self.image = image
        self.color = color


class Boat(Figure):
    def __init__(self, color):
        super(Boat, self).__init__("♖", color)


class Queen(Figure):
    def __init__(self, color):
        super(Queen, self).__init__("♕", color)


class King(Figure):
    def __init__(self, color):
        super(King, self).__init__("♔", color)


class Horse(Figure):
    def __init__(self, color):
        super(Horse, self).__init__("♘", color)


class Soldier(Figure):
    def __init__(self, color):
        super(Soldier, self).__init__("♙", color)
        self.countGame = 0


class Elephant(Figure):
    def __init__(self, color):
        super(Elephant, self).__init__("♗", color)


class Board(object):
    cells = [[Cell() for i in range(8)] for j in range(8)]
    coordinateLetter = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
    coordinateNumber = [1, 2, 3, 4, 5, 6, 7, 8]

    @classmethod
    def __setCellsColor(cls):
        for i in range(0, 8):
            if i % 2 is 0:
                for k in range(0, 8, 2):
                    cls.cells[i][k].color = BLACK
                for k in range(1, 8, 2):
                    cls.cells[i][k].color = WHITE
            else:
                for j in range(1, 8, 2):
                    cls.cells[i][j].color = BLACK
                for k in range(0, 8, 2):
                    cls.cells[i][k].color = WHITE

    @classmethod
    def __initializeCells(cls):
        for i in range(0, 8):
            for k in range(0, 8):
                cls.cells[i][k] = Cell()
                if i is 1:
                    cls.cells[i][k].figure = Soldier(WHITE)
                if i is 0:
                    if k == 0 or k == 7:
                        cls.cells[i][k].figure = Boat(WHITE)
                    elif k == 1 or k == 6:
                        cls.cells[i][k].figure = Horse(WHITE)
                    elif k == 2 or k == 5:
                        cls.cells[i][k].figure = Elephant(WHITE)
                    elif k == 3:
                        cls.cells[i][k].figure = Queen(WHITE)
                    else:
                        cls.cells[i][k].figure = King(WHITE)
                if i is 6:
                    cls.cells[i][k].figure = Soldier(BLACK)
                if i is 7:
                    if k == 0 or k == 7:
                        cls.cells[i][k].figure = Boat(BLACK)
                    elif k == 1 or k == 6:
                        cls.cells[i][k].figure = Horse(BLACK)
                    elif k == 2 or k == 5:
                        cls.cells[i][k].figure = Elephant(BLACK)
                    elif k == 3:
                        cls.cells[i][k].figure = Queen(BLACK)
                    else:
                        cls.cells[i][k].figure = King(BLACK)

    @classmethod
    def showBoard(cls):
        for i in range(0, 8):
            print("\t\t", end="")
            print(cls.coordinateLetter[i], end="")

        for j in range(0, 8):
            print()
            print()
            print(cls.coordinateNumber[j], end="")
            for k in range(0, 8):
                temp = cls.cells[j][k]
                if temp.figure is None:
                    if temp.color == WHITE:
                        print("\t\t -", end="")
                    else:
                        print("\t\t ", end="")
                else:
                    if temp.figure.color == BLACK:
                        print("\t\t" + temp.figure.image, end="")
                    else:
                        print("\t\t" + temp.figure.image + '.', end="")

    def __new__(cls):
        if not hasattr(cls, 'instance'):
            cls.instance = super(Board, cls).__new__(cls)
            # cls.cells = [[Cell() for i in range(8)] for j in range(8)]
            # cls.coordinateNumber = [1, 2, 3, 4, 5, 6, 7, 8]
            # cls.coordinateLetter = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
            cls.__initializeCells()
            cls.__setCellsColor()
        return cls.instance

    '''def __init__(self):
        self.cells = [[Cell() for i in range(8)] for j in range(8)]
        self.coordinateNumber = [1, 2, 3, 4, 5, 6, 7, 8]
        self.coordinateLetter = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
        self.__initializeCells()
        self.__setCellsColor()'''


class Player:
    def __init__(self, color):
        self.color = color
        self.board = Board()

    def move(self, firstNumber, firstLetter, secondNumber, secondLetter):
        firstNum = int(firstNumber) - 1
        secondNum = int(secondNumber) - 1
        firstLet = ord(firstLetter) - 65
        secondLet = ord(secondLetter) - 65
        firstCoordinate = self.__checkFirstCoordinate(firstNum, firstLet)
        playersFigure = self.__checkPlayersFigure(firstNum, firstLet)
        secondCoordinate = self.__checkSecondCoordinate(firstNum, firstLet, secondNum, secondLet)
        return firstCoordinate and playersFigure and secondCoordinate

    def __checkFirstCoordinate(self, firstNumber, firstLetter):
        if self.board.cells[firstNumber][firstLetter].figure is None:
            print("No figure in that coordinates! \n Please input correct coordinates!")
            return False
        return True

    def __checkPlayersFigure(self, firstNumber, firstLetter):
        if self.color is not self.board.cells[firstNumber][firstLetter].figure.color:
            print("That is not your figure! \n Please input correct coordinates!")
            return False
        return True

    def __checkSecondCoordinate(self, firstNumber, firstLetter, secondNumber, secondLetter):
        firstFigure = self.board.cells[firstNumber][firstLetter].figure
        secondFigure = self.board.cells[secondNumber][secondLetter].figure
        firstCell = self.board.cells[firstNumber][firstLetter]
        secondCell = self.board.cells[secondNumber][secondLetter]
        # TODO see syntax instanceOf()
        if isinstance(firstFigure, Soldier):
            countGame = Soldier(firstFigure).countGame
            if firstFigure.color is WHITE:
                if countGame is -1 or countGame is 0:
                    if countGame is 0 and firstLetter is secondLetter and (secondNumber - firstNumber) is 2:
                        if secondCell.figure is None or secondCell.figure.color is BLACK and \
                                self.board.cells[secondNumber][secondLetter].figure is None:
                            Soldier(firstFigure).countGame = -1
                            secondCell.figure = firstFigure
                            firstCell.figure = None
                            return True
                        else:
                            print("Second coordinates are not correct!\n There are your figure!")
                            return False

                    elif (firstLetter is secondLetter) and ((secondNumber - firstNumber) is 1) and (
                            (secondFigure is None) or (secondFigure.color is BLACK)):
                        if firstFigure.color is self.color:
                            if countGame is 0:
                                Soldier(firstFigure).countGame = -1
                            secondCell.figure = firstFigure
                            firstCell.figure = None
                            return True
                        else:
                            print("Second coordinates are not correct!\n There are your figure!")
                            return False
                    elif ((secondLetter - firstLetter is 1) or (firstLetter - secondLetter is 1)) and (
                            (secondNumber - firstNumber) is 1) and (secondFigure.color is BLACK):
                        if firstFigure.color is self.color:
                            if countGame is 0:
                                Soldier(firstFigure).countGame = -1
                            secondCell.figure = firstFigure
                            firstCell.figure = None
                            return True
                        else:
                            print("Second coordinates are not correct!\n There are your figure!")
                            return False
                    else:
                        return False

            if firstFigure.color is BLACK:
                if countGame is -1 or countGame is 0:
                    if countGame is 0 and (firstLetter is secondLetter) and (firstNumber - secondNumber) is 2:
                        if (secondCell.figure is None) or (secondCell.figure.color is WHITE) and (
                                self.board.cells[secondNumber][secondLetter].figure is None):
                            Soldier(firstFigure).countGame = -1
                            secondCell.figure = firstFigure
                            firstCell.figure = None
                            return True
                        else:
                            print("Second coordinates are not correct!\n There are your figure!")
                            return False
                    elif (firstLetter is secondLetter) and ((firstNumber - secondNumber) is 1) and (
                            (secondFigure is None) or (secondFigure.color is WHITE)):
                        if firstFigure.color is self.color:
                            if countGame is 0:
                                Soldier(firstFigure).countGame = -1
                            secondCell.figure = firstFigure
                            firstCell.figure = None
                            return True
                        else:
                            print("Second coordinates are not correct!\n There are your figure!")
                            return False

                    elif ((ord(secondLetter) - ord(firstLetter) is 1) or (
                            ord(firstLetter) - ord(secondLetter) is 1)) and (
                            (firstNumber - secondNumber) is 1) and (secondFigure.color is WHITE):
                        if firstFigure.color() is self.color:
                            if countGame is 0:
                                Soldier(firstFigure).countGame = -1
                            secondCell.figure = firstFigure
                            firstCell.figure = None
                            return True
                        else:
                            print("Second coordinates are not correct!\n There are your figure!")
                            return False
                    else:
                        return False
        return True


class Game:
    coordinate = []

    @classmethod
    def chessGame(cls):
        # coordinate = []
        player1 = Player(WHITE)
        player2 = Player(BLACK)
        while True:
            Board.showBoard()
            # TODO with do while
            coordinate = input("\nPLAYER ONE please input coordinates(first number, first letter, second number, "
                               "second letter)!")
            while not player1.move(coordinate[0], coordinate[1], coordinate[2], coordinate[3]):
                coordinate = input("\nPLAYER ONE please input coordinates(first number, first letter, second number, "
                                   "second letter)!")
            Board.showBoard()

            # TODO with do while
            coordinate = input("\nPLAYER TWO please input coordinates(first number, first letter, second number, "
                               "second letter)!")
            while not player2.move(coordinate[0], coordinate[1], coordinate[2], coordinate[3]):
                coordinate = input("\nPLAYER TWO please input coordinates(first number, first letter, second number, "
                                   "second letter)!")


def main():
    Game.chessGame()


main()
