#include <iostream>
#ifndef AVLTREE
#define AVLTREE

using namespace std;


template <typename T>
class Node {
public:
	T value;
	Node* left;
	Node* right;
    int height;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
        this->height = 0;
	}

	~Node()
	{
		this->value = 0;
        this->height = 0;
		this->left = nullptr;
		this->right = nullptr;
	}

};
#endif