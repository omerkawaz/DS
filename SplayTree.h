//
// Created by Omer Kawaz on 28/11/2017.
//

#ifndef SPLAYTREE_H
#define SPLAYTREE_H
#include <exception>
#include <stdexcept>
#include "node.h"
#include <assert.h>
#include <iostream>






class exceptionTree : public std::exception {};
class existAlready : public exceptionTree {};
class notExist : public exceptionTree{};

template<class T,class S>
class SplayTree {
private:
    const Node<T, S>* findAux(const Node<T, S>* current, const T& k) {
        if (current == NULL) {
            throw notExist();
        }
        if (current->key == k) {
            return current;
        }
        else if (current->key < k)
            return findAux(current->right,k);
        else if (current->key > k)
            return findAux(current->left,k);
        return NULL;
    }
    Node<T, S>* addElementAux(Node<T, S>* current,const T& k,const S& info) {
        if (current == NULL) {
            return new Node<T,S>(k,info);
        }
        if (k > current->key) {
            current->right = addElementAux(current->right,k,info);
        }
        else if (k < current->key) {
            current->left = addElementAux(current->left,k,info);
        }
        else {
            throw existAlready();
        }
        return balance(current);

    }
protected:
    Node<T,S>* root;
public:

};


#endif //SPLAYTREE_H
