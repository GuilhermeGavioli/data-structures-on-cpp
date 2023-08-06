#include <iostream>
#include "../pause.h"

class Queue{
public:
    int grow_type = 0; // 0 - Double   // 1 - Exponencial  // * - linear
    int* rear = nullptr;
    int** print_pointer = nullptr;
    int* front = nullptr;
    int max;
    int size;
    int* data = new int[max];

    Queue(int _max){
        max = _max;
        size = 0;
        rear = data;
        print_pointer = &rear;
    }

    ~Queue(){
        delete[] data;
        delete rear;
        delete front;
        data = nullptr;
        rear = nullptr;
        front = nullptr;
    }

    void print(){
        while (*print_pointer <= front){
            std::cout << **print_pointer << "--";
            ++(*print_pointer);
        }
    }

    int enqueue(int value){
        // if (isFull()){
        //     grow();
        // }
       data[size] = value;
       front = &data[size];
       ++size;
       // rear = &data[0];
       return 0;
    }

    bool dequeue(){
        // if (isEmpty()){
        //     return 1;
        // }
        ++rear;
        --size;
        return 0;
    }

private:
    // bool isFull(){
    //     return top == (data + (max - 1));
    // }

    // bool isEmpty(){
    //     return top == (data - 1); // or size == -1
    // }

    // bool grow(){ // Alocate more Heap Memory
    //     if (grow_type == 0) {
    //         doubleSize();
    //     } else if (grow_type == 1){
    //         exponencialSize();
    //     } else {
    //         linearSize();
    //     }

    //     int* bigger = new int[max];
    //     for (int i = 0; i < size; i++){
    //         bigger[i] = data[i];
    //     }
    //     delete[] data;
    //     data = bigger;
    // }

    // void doubleSize(){
    //     max = max * 2;
    // }

    // void exponencialSize(){
    //     max = max * max;
    // }

    // void linearSize(){
    //     max = max + max;
    // }
};

int
main()
{

    Queue* q = new Queue(6);
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->print();
    // q->dequeue();


    // std::cout << "\n" << q->rear;
    // std::cout << "\n" << *q->rear;

    
    pause();

    delete q;
    q = nullptr;

    // exit(0);
    return 0;
}