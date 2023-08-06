#include <iostream>
#include "../pause.h"




class Node{
public:
    int value;
    Node *next = NULL;

    Node(int _value){
        value = _value;
    }

    ~Node(){
        if (next){
            delete next;
            next = nullptr;
        }
    }
};

class LinkedList{
public:
    Node* head = NULL;
    Node* tail = NULL;

    LinkedList(){
       tail = new Node(0);
    }

    LinkedList(int* value){
        head = new Node(*value);
        tail = new Node(0);
        tail->next = head;
    }
    
    ~LinkedList(){
        if (head){
            delete head;
            head = nullptr;
        }
        if (tail){
            delete tail;
            tail = nullptr;
        }
    }

    int add(Node* new_node){
        if (head == NULL){
            head = new_node;
            tail->next = head;
            return 0;
        }
        return add_recursive(head, new_node);
    }

    // add to the O(1) time complexity by keeping track of the linked list tail (w/ a pointer on the tail of the ll)
    bool quick_add(Node* node){
        if (head == NULL){
            head = node;
            tail->next = head;
            return 0;
        }
        tail->next->next = node;
        tail->next = node;
        return 0;
    }

    // # Not possible (yet) - It would require the tail to be one address behind in the tail, seem that it needs to points / access the last but one node element.
    // bool remove_quick(){
    //     if (head == NULL){
    //         return 0;
    //     }
    // }

    int remove(){
        if (head == NULL){
            return 0;
        }
        return remove_recursive(NULL, head);
    }

    int addPosition(Node* node, int* pos){
        if (pos < 0 || head == NULL){
            return 0;
        }
        int curr_pos = 0;
        add_position_recursive(node, pos, NULL, head, &curr_pos);
    }

    int invert(){
        if (head != NULL){
            tail->next = head;
        }
        return invert_recursive(NULL, head);
    }

    int print(){
        if (head == NULL){
            return 0;
        }
        std::cout << "\n";
        print_recursive(head);
    }

private:
    int add_recursive(Node* curr, Node* new_node){
        if (curr->next == NULL){
            curr->next = new_node;
            tail->next = new_node;
            return 0;
        }
        return add_recursive(curr->next, new_node);
    }

    void print_recursive(Node* node){
        std::cout << node->value << " --> ";
        if (node->next == NULL){
            std::cout << " null";
            return;
        }
        return print_recursive(node->next);
    }

    int remove_recursive(Node* prev, Node* curr){
        if (curr->next == NULL){
            prev->next = NULL;
            tail->next = prev;
            return 0;
        }
        prev = curr;
        return remove_recursive(prev, curr->next);
    }
    
    int add_position_recursive(
        Node* new_node,
        int* pos,
        Node* prev,
        Node* curr,
        int* curr_pos
    ){
        if(curr == NULL){
            prev->next = new_node;
            tail->next = prev;
            return 0;
        }
        if (*curr_pos == *pos){ // Should insert here
            prev->next = new_node;
            new_node->next = curr;
            return 0;
        }
        prev = curr;
        (*curr_pos)++;
        return add_position_recursive(new_node, pos, prev, curr->next, curr_pos);
    }

    int invert_recursive(Node* prev, Node* curr){
        if (curr == NULL){
            head = prev;
            return 0;
        }
        Node *temp = curr->next;
        curr->next = prev;
        return invert_recursive(curr, temp);
    }
};



int main() {

    const int MAX = 6;
    LinkedList l = LinkedList();

    for (int i = 1; i <= MAX;  i++){
            Node *node = new Node(i);
            l.add(node);
    }

    for (int j = 1; j <= MAX;  j++){
        Node *node = new Node(j + MAX);
        l.quick_add(node);
    }
    l.print();

    Node *n1 = new Node(100);
    Node *n2 = new Node(200);
    Node *n3 = new Node(300);
    Node *n4 = new Node(400);
    int pos = 5;
    int pos2 = 120;
    
    // l.print();
    // l.print();

    
    l.invert();
    l.print();
    l.quick_add(n3);
    l.add(n4);
    l.print();
    l.addPosition(n2, &pos2);
    l.addPosition(n1, &pos);
    l.print();
    l.invert();
    l.print();


    pause();
    delete(n1);
    delete(n2);
    delete(n3);
    return 0;
    exit(0);
}
