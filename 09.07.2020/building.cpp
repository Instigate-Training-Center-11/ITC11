#include <iostream> 

int WaysToConstructBuildings(int);
int checkType(int);

int main()
{
    int sections = 0;
    std::cout << "Enter number of sections: ";
    std::cin >> sections;
    sections = checkType(sections);
    while (0 > sections)
    {
        std::cout << "Please, enter a positive number: ";
        std::cin >> sections;
    }

    std::cout << "Count of ways for " << sections << " sections to construct buildings is ";
    std::cout << WaysToConstructBuildings(sections) << std::endl; 
    return 0; 
}

int WaysToConstructBuildings(int n)
{
    if (1 == n)
    {
        return 4;
    }

    /* initialisation count of buildings and spaces for one side */
    int Building = 1;
    int Spaces = 1;
    int oldBuilding = 0;
    int oldSpaces = 0;

    for (int i = 2; i <= n; ++i)
    {
        oldBuilding = Building;
        oldSpaces = Spaces;

        Spaces = oldBuilding + oldSpaces;
        Building = oldSpaces;
    }

    int oneSide = Spaces + Building;

    /* for two sides return the square for one side */
    int twoSide = oneSide * oneSide;

    return twoSide; 
}

int checkType(int input)
{
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();

        std::cout << "\nPlease enter integer type data: ";
        std::cin >> input;
    }

    return input;
}