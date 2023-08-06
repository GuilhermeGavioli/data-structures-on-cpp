#include <iostream>
#include "../pause.h"

// reference
//                             15
//                           /    \ 
//                         9       20
//                       / \       /  \ 
//                     8    10   18     29
//                   /        \          \ 
//                 7           13          31 
//
//
// inorder: LrR     =   7  8   9  10  13  15  18  20  29  31
// preorder: rLR    =  15  9   8   7  10  13  20  18  29  31
// postorder: LRr   =   7  8  13  10   9  18  29  31  20  15


class Node{
public:
    Node *left = nullptr;
    Node *right = nullptr;
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
        root = _root;
    }

    ~BinarySearchTree(){
        delete root;
        root = nullptr;
    }

    void printPreOrder(){
        if (root == nullptr){
             return;
        }
        recursive_preorder_print(root);
    }

    void printInOrder(){
        if (root == nullptr){
             return;
        }
        recursive_inorder_print(root);
    }

    void printPosOrder(){
        if (root == nullptr){
             return;
        }
        recursive_posorder_print(root);
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

    void recursive_inorder_print(Node* curr){
        if (curr->left != nullptr){
            recursive_inorder_print(curr->left);
        } 
        std::cout << "\n" << curr->value;
        if (curr->right != nullptr){
            recursive_inorder_print(curr->right);
        }
    }

    void recursive_preorder_print(Node* curr){
        std::cout << "\n" << curr->value;
        if (curr->left != nullptr){
            recursive_preorder_print(curr->left);
        }
        if (curr->right != nullptr){
            recursive_preorder_print(curr->right);
        }
    }

    void recursive_posorder_print(Node* curr){
        if (curr->left != nullptr){
            recursive_posorder_print(curr->left);
        } 
        if (curr->right != nullptr){
            recursive_posorder_print(curr->right);
        }
        std::cout << "\n" << curr->value;
    }
};



int main() {

    // postorder =   7  8  13  10   9  18  29  31  20  15
    Node *root = new Node(15);
    Node *n1 = new Node(9);
    Node *n2 = new Node(8);
    Node *n3 = new Node(7);
    Node *n4 = new Node(10);
    Node *n5 = new Node(13);
    Node *n6 = new Node(20);
    Node *n7 = new Node(18);
    Node *n8 = new Node(29);
    Node *n9 = new Node(31);

    
    BinarySearchTree* bst = new BinarySearchTree(root);
    bst->add(n1);
    bst->add(n2);
    bst->add(n3);
    bst->add(n4);
    bst->add(n5);
    bst->add(n6);
    bst->add(n7);
    bst->add(n8);
    bst->add(n9);

    bst->printPosOrder();

    pause();

    delete bst;
    delete root;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    delete n8;
    delete n9;


    exit(0);
}