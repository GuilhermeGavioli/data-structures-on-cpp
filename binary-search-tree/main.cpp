#include <iostream>


class Node{
public:
    Node *left;
    Node *right;
    int value; //fix to a pointer

    Node(int _value){
        value = _value;
    }

    ~Node(){
        if (left){
            delete left;
            left = nullptr;
        }
        if (right){
            delete right;
            right = nullptr;
        }
    }
};
class BinarySearchTree{
public:
    Node *root = nullptr;

    BinarySearchTree(){

    }

    BinarySearchTree(Node* _root){
        this->root = _root;
    }

    ~BinarySearchTree(){
        delete root;
        root = nullptr;
    }

    bool add(Node* node){
        if (root == nullptr){
            root = node;
            return 0;
        }
        return recursive_add(root, node);
    }

private:
    bool recursive_add(Node* curr, Node* new_node){
        if (new_node->value == curr->value){ // Can not contain two equal value elements in same bs tree
            return 1;
        }
        if (curr->value > new_node->value){
            if (curr->left == nullptr){
                curr->left = new_node;
                return 0;
            }
            return recursive_add(curr->left, new_node);
        } else {
            if (curr->right == nullptr){
                curr->right = new_node;
                return 0;
            }
            return recursive_add(curr->right, new_node);
        }
    }
};



int main() {

    Node *root = new Node(15);
    BinarySearchTree bst = BinarySearchTree(root);

    while(true){
        std::cin;
    }
    return 0;
}