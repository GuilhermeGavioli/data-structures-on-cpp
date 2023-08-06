#include <iostream>

const char QUIT = 'q';

static void pause(){
    char keep_going = ' ';
    while(true){
        std::cin >> keep_going;
        if (keep_going == QUIT)
            exit(0);
    }
};
