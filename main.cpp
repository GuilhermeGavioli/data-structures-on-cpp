#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;

    int a = 5;
    int b = 5;

    int *prta = &a;
    int *prtb = &b;

    std::cout << "Hello, World!" << (*prta == *prtb)<< std::endl;
    while(true){
        std::cin;
    }
    return 0;
}