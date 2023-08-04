#include <iostream>


static void pause(){
    char keep_going = 'a';
    while(true){
        std::cin >> keep_going;
        if (keep_going == 'q')
            break;
    }
};

class Node{
public:
    int value;
    Node *next = NULL;

    Node(int _value){
        value = _value;
    }

    ~Node(){
        delete next;
        delete this;
    }
};

class LinkedList{
public:
    Node* head = NULL;
    Node* tail = NULL;

    LinkedList(){
       
    }

    LinkedList(int* value){
        head = new Node(*value);
    }

    int add(Node* new_node){
        if (head == NULL){
            head = new_node;
            return 0;
        }
        return add_recursive(head, new_node);
    }

    // add to the O(1) [instantly] by keeping track of the linked list tail
    quick_add(){

    }

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
        //  Node* new_node,
        // int* pos,
        // Node* prev,
        // Node* curr,
        // int* curr_pos
    }

    int invert(){
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
            return 0;
        }
        return add_recursive(curr->next, new_node);
    }

    void print_recursive(Node* node){
        std::cout << node->value << "-->";
        if (node->next == NULL){
            std::cout << " null";
            return;
        }
        return print_recursive(node->next);
    }

    int remove_recursive(Node* prev, Node* curr){
        if (curr->next == NULL){
            prev->next = NULL;
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

    LinkedList l = LinkedList();
    for (int i = 1; i <= 10;  i++){
     
            Node *node = new Node(i);
            l.add(node);
    }

    Node *n1 = new Node(100);
    Node *n2 = new Node(200);
    l.print();
    int pos = 5;
    int pos2 = 120;
    l.addPosition(n1, &pos);
    l.print();
    l.addPosition(n2, &pos2);
    l.print();
    l.invert();
    l.print();


    pause();
    return 0;
}
