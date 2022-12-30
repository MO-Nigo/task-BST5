#ifndef MY_TREE_H
#define MY_TREE_H

#include <vector>

template <class T>
struct Node {
    T data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(T data) : data(data) {}
    // Add the constructors you want
};

template <class T>
class MyTree{

    private:

    public:
        MyTree(){}
        
        MyTree(std::vector<T> elements){}
   
        void insert(T key){}

        void insert(const Node<T> node){}

        const Node<T>* search(T key){}
        
        const Node<T>* delete_node(T key){}

        const Node<T>* delete_node(const Node<T> node){}

        bool isBST(){}
        
        std::vector<T> inorder_rec(){}
        
        std::vector<T> preorder_rec(){}
        
        std::vector<T> postorder_rec(){}
        
        std::vector<T> inorder_it(){}
        
        std::vector<T> preorder_it(){}
        
        std::vector<T> postorder_it(){}

        std::vector<T> breadth_traversal(){}

        int get_size(){}

        int get_height(){}

        void clear(){}

        ~MyTree(){}
};

#endif