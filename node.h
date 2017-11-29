//
// Created by Omer Kawaz.
//

#ifndef WET1_WINTER_NODE_H
#define WET1_WINTER_NODE_H

#include <cstdlib>

template <class T, class S> class SplayTree;

//a class of the nodes used in the tree
template<class T, class S>
class Node {
public:
    explicit Node() : key(T()), info(S()), right(NULL), left(NULL) {}
    Node(const T& key, const S& info) : key(key), info(info) ,
                                        right(NULL), left(NULL){}
    Node(const Node<T,S>& copy) : key(copy.key), info(copy.info) ,
                                  right(copy.right), left(copy.left){}
    ~Node() {
        delete left;
        delete right;
    }
private:
    T key;
    S info;
    Node<T,S>* right;
    Node<T,S>* left;
    friend class SplayTree<T,S>;
};


#endif //WET1_WINTER_NODE_H
