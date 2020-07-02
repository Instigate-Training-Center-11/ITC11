#ifndef _MENU_HPP_
#define _MENU_HPP_

#include <iostream>
#include "linear_search.hpp"
#include "binary_search.hpp"
#include "jump_search.hpp"
#include "interpolation_search.hpp"
#include "exponential_search.hpp"
#include "ternary_search.hpp"

int validation();
void print_index(int array[], int size, int index);
void logic_menu();

int menu() {
    int submenu;
    std::cout << "\t\t************************MENU**********************\n\n";
    std::cout << "\t\tCheck (1):  Insert elements for array.\n";
    std::cout << "\t\tCheck (2):  Generate sorted array.\n";
    std::cout << "\t\tCheck (3):  Linear_search.\n";
    std::cout << "\t\tCheck (4):  Binary_search.\n";
    std::cout << "\t\tCheck (5):  Jump_search.\n";
    std::cout << "\t\tCheck (6):  Interpolation_search.\n";
    std::cout << "\t\tCheck (7):  Exponential_search.\n";
    std::cout << "\t\tCheck (8):  Ternary_search.\n";
    std::cout << "\t\tCheck (9): For exit...\n\n";
    std::cout << "\t\t**************************************************\n\n";
    std::cout << "\t\tInsert 1 - 9\n\n";

    return validation();
}

void logic_menu() {
    int size = 0;
    int value = 0;
    std::cout << "\t\tPlease insert size of array: ";
    size = validation();
    int* array = new int[size];
    bool is_exit = true;

    while (is_exit) {
        int submenu = menu();
        switch (submenu) {
        case(1):
            system("clear");
            std::cout << "\t\tInsert elements: " << std::endl << std::endl;
            for (int i = 0; i < size; ++i) {
                array[i] = validation();
            }
            break;
        case(2):
            system("clear");
            std::cout << "\t\tGenerate sorted array..." << std::endl << std::endl;
            std::cout << "\t\t";
            for (int i = 0, j = 0; i < size; ++i, j += 2) {
                array[i] = j;
                std::cout << j << " ";
            }
            std::cout << std::endl << std::endl;
            break;
        case(3):
            system("clear");
            std::cout << "\t\tLinear_search..." << std::endl << std::endl;
            std::cout << "\t\tInsert value for searching: ";
            value = validation();
            print_index(array, size, linear_search(array, value, size));
            break;
        case(4):
            system("clear");
            std::cout << "\t\tBinary_search..." << std::endl << std::endl;
            std::cout << "\t\tInsert value for searching: ";
            value = validation();
            print_index(array, size, binary_search(array, value, size));
            break;
        case(5):
            system("clear");
            std::cout << "\t\tJump_search...." << std::endl << std::endl;
            std::cout << "\t\tInsert value for searching: ";
            value = validation();
            print_index(array, size, jump_search(array, value, size));
            break;
        case(6):
            system("clear");
            std::cout << "\t\tInterpolation_search..." << std::endl << std::endl;
            std::cout << "\t\tInsert value for searching: ";
            value = validation();
            print_index(array, size, interpol_search(array, value, size));
            break;
        case(7):
            system("clear");
            std::cout << "\t\tExponential_search..." << std::endl << std::endl;
            std::cout << "\t\tInsert value for searching: ";
            value = validation();
            print_index(array, size, exp_search(array, value, size));
            break;
        case(8):
            system("clear");
            std::cout << "\t\tTernary_search..." << std::endl << std::endl;
            std::cout << "\t\tInsert value for searching: ";
            value = validation();
            print_index(array, size, ternary_search(array, value, size));
            break;
        case(9):
            system("clear");
            std::cout << "Bye...Good luck!" << std::endl;
            is_exit = false;
            break;
            default:
            system("clear");
            std::cout << "\t\tplease select valid number of submenu..\n";
            std::cout << std::endl << std::endl;
            break;
        }
    }
}

int validation() {
    int value = 0;
    std::cin >> value;
    std::cout << std::endl;
    while ((std::cin.fail() | value < 0)) {
            std::cout << "\t\tWrong input: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> value;
    }
    return value;
}

void print_index(int array[],int size, int index) {
    if (index == -101) {
        std::cout << "\t\tIndex not found!";
        std::cout << std::endl << std::endl;
    } else {
        std::cout << "\t\tIndex = " << index;
        std::cout << std::endl << std::endl;
        std::cout << "\t\t";

        for (int i = 0; i < index; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << "[" << array[index] << "] ";
        for (int i = index + 1; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl << std::endl;
    }
}

#endif