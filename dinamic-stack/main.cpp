#include <iostream>
#include "../pause.h"

class Stack{
public:
    int grow_type = 0; // 0 - Double   // 1 - Exponencial  // * - linear
    int max;
    int* top;
    int size;
    int* data = new int[max];

    Stack(int _max){
        max = _max;
        size = -1;
        top = data;
    }

    ~Stack(){
        delete[] data;
    }

    int push(int value){
        if (isFull()){
            grow();
        }
        ++size;
        data[size] = value;
        top = data + (size);
        return 0;
    }

    bool pop(){
        if (isEmpty()){
            return 1;
        }
        --size;
        top = data + (size);
        return 0;
    }

private:
    bool isFull(){
        return top == (data + (max - 1));
    }

    bool isEmpty(){
        return top == (data - 1); // or size == -1
    }

    bool grow(){ // Alocate more Heap Memory
        if (grow_type == 0) {
            doubleSize();
        } else if (grow_type == 1){
            exponencialSize();
        } else {
            linearSize();
        }

        int* bigger = new int[max];
        for (int i = 0; i < size; i++){
            bigger[i] = data[i];
        }
        delete[] data;
        data = bigger;
    }

    void doubleSize(){
        max = max * 2;
    }

    void exponencialSize(){
        max = max * max;
    }

    void linearSize(){
        max = max + max;
    }
};

int
main()
{

    Stack* s = new Stack(5);
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);

    std::cout << "\n" << s->push(5);
    std::cout << "\n" << s->push(6);
    std::cout << "\n" << s->push(7);
    std::cout << "\n" << s->pop();
    std::cout << "\n" << s->push(8);
    std::cout << "\n" << s->top;
    std::cout << "\n" << *s->top;

    delete s;

    pause();
    exit(0);
}