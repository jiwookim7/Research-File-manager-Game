#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
#include <vector>
using namespace std;


/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

protected:
	Node<T>* _root;         // Root of the tree nodes

	/* Add new T val to the tree */
	void addHelper(Node<T>* root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}

    void printLevel(Node<T>* root, int level)
    {
        if(root == NULL)
			return;
		
		

        if(level == 1)
        {
            cout << root->value << " ";
        }
        else if(level > 1)
        {
			
            printLevel(root->left, level-1);
            printLevel(root->right, level-1);

        }
    }

	/* Print tree out in inorder (A + B) */
	void printInOrderHelper(Node<T>* root) {
		if (!root) return;
		printInOrderHelper(root->left);
		cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	void destrutorHelper(Node<T>* root)
	{
		//post order
		if(root == NULL)
			return;
		destrutorHelper(root->left);
		destrutorHelper(root->right);
		delete  root;
	}

	/* Return number of nodes in tree */
	int nodesCountHelper(Node<T>* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}

	/* Return height of tree (root == nullptr -> 0) */
	int heightHelper(Node<T>* root) {
		if (!root) {
			return -1;
		}
		else {
			return 1 + max(heightHelper(root->left), heightHelper(root->right));
		}
	}

    void printMaxPathHelper(Node<T>* root)
    {
		if(root == NULL)
		{
			// return vector<int>();
			return;
		}
		cout << root->value << " ";

		int left = heightHelper(root->left);
		int right = heightHelper(root->right);

		// if (left.size() > right.size())
		//{
			// left.push_back(value);
			// return left;
		//}
		//else
		//{
			// right.push
			//return right;
		//}

		if(left > right)
		{
			//cout << root->value << " ";
			printMaxPathHelper(root->left);
		}
		else
		{
			//cout << root->value << " ";
			printMaxPathHelper(root->right);
		}	
		return;
    }

	bool searchNumber(Node<T> * root, int key)
	{
		bool result = false;

		if(root == NULL || root->value == key)
		{
			result = true;
			return root;
		}
		
		if(root->value < key)
		{
			result = true;
			return searchNumber(root->right, key);
		}

		else
		{
			result = true;
			return searchNumber(root->left, key);
		}

		return result;
	}

	/* Delete a given <T> value from tree */
	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->_root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}

	/********************************* PUBLIC API *****************************/
public:

	BST() : _root(nullptr) { }               // Basic initialization constructor

	/**
	 * Destructor - Needs to free *all* nodes in the tree
	 * TODO: Implement Destructor
	 */
	~BST() {
	    destrutorHelper(this->_root);
	}

	/* Public API */
	void add(T val) {
		if (this->_root) {
			this->addHelper(this->_root, val);
		}
		else {
			this->_root = new Node<T>(val);
		}
	}

	void print() {
		printInOrderHelper(this->_root);
	}

	/**
	 * Print the nodes level by level, starting from the root
	 * TODO: Implement printLevelOrder
	 */
	void printLevelOrder() {
        int h = heightHelper(this->_root);
        int i;
        for(i = 1; i <= h + 1; i++)
        {
			 printLevel(this->_root, i);
			 cout << endl;
        }
	}

	int nodesCount() {
		return nodesCountHelper(this->_root);
	}

	int height() {
		return heightHelper(this->_root);
	}

	/**
	 * Print the maximum path in this tree
	 * TODO: Implement printMaxPath
	 */
	void printMaxPath() 
    {
		printMaxPathHelper(this->_root);
	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->_root, value);
	}

	/**
	 * Find if the BST contains the value
	 * TODO: Implement contains
	 */
	bool contains(T value) 
	{
	    //cout << "TODO: Implement contains" << endl;
		//bool result = false;
		return searchNumber(this->_root, value);
		//return numeric_limits<T>::min();
	}
};

#endif
