#include <iostream>
#include "hello.hpp"

int main() {

    std::cout << "Hello World!" << std::endl;   // std::endl mach auch std::flush -> Viel aufwändigeer als '\n', Ausgabe erfolgt aber sofort!

    printFromHeader();

    return 0;
}

void printFromHeader() {
    std::cout << "Hello from .hpp" << std::endl;
}