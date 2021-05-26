#pragma once
#include <iostream>
#include <stack>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>

namespace ariel
{

template<typename T>
    class BinaryTree
    {

            class Node
            {
                public:
                    T value;
                    Node *left;
                    Node *right;

                    Node(T d){
                        this->left = nullptr;
                        this->right = nullptr;
                        value = d;
                    }
            };

      private:
        Node *root ;

      public:
        BinaryTree<T>(){}
        BinaryTree<T> add_root(T r){return *this;}
        BinaryTree<T> add_left(T r,T l_n){return *this;}
        BinaryTree<T> add_right(T r,T r_n){return *this;}

            class iterator
            {
                private:
                   Node* pointer;

                public:
                    iterator(Node* p = nullptr)
                    {
                        pointer = p;
                    }

                    T& operator*() const
                    {
                        return pointer->value;
                    }

                    T* operator->() const 
                    {
                        return &(pointer->value);
                        }

                    iterator& operator++(){return *this;}
                    const iterator operator++(int){return *this;}
                    bool operator==(const iterator& other) const {return pointer == other.pointer;}
                    bool operator!=(const iterator& other) const {return pointer != other.pointer;}
      
          };

          
                    iterator begin_preorder(){return iterator(nullptr);}
                    iterator end_preorder(){return iterator(nullptr);}
                    iterator end_inorder(){return iterator(nullptr);}
                    iterator begin_inorder(){return iterator(nullptr);}
                    iterator end_postorder(){return iterator(nullptr);}
                    iterator begin_postorder(){return iterator(nullptr);}
                    iterator begin(){return iterator(nullptr);}
                    iterator end(){return iterator(nullptr);}
                    friend std::ostream& operator<<(std::ostream& output,const BinaryTree<T> &BT){return output;}

    };
}