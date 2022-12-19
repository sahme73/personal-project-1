#include "..\lib\player.h"
#include "..\lib\operations.h"

#include <iostream>

int main() {

    //initialize player
    Player player;
    player.SetHealth(100.0f);

    //display player information
    std::cout << "The player's health is: " << player.GetHealth() << std::endl;

    //karatsuba
    std::string x, y;
    std::cout << std::endl << "First input number (x): ";
    std::cin >> x;
    std::cout << std::endl << "Second input number (y): ";
    std::cin >> y;
    std::cout << std::endl << x << " * " << y << " = " << Karatsuba(x, y) << std::endl;

    //exit program
    std::string result;
    do {
        std::cout << std::endl << "Enter 'exit' to end the program!" << std::endl;
        std::cin >> result;
    } while (result != "exit");

}