#include "Utils.h"

int check_the_number(int min, int max)
{
    int n = 0;
    while (((std::cin >> n).fail()) || (n < min) || (n > max) || (std::cin.get() != '\n')) {
        std::cin.clear();
        std::cin.ignore(1000000, '\n');
        std::cout << "Enter correct number: ";
    }
    return n;
}