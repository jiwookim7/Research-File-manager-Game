#include "AVLNode.hpp"


template <typename T>
class AVLTree{

protected:
	Node <T>* _root;         // Root of the tree nodes

    void insertHelper(Node<T>*& root, T& val)
    {
        if(root == NULL)
        {
            root = new Node<T>(val);
        }
        else if(val < root->value)
        {
            insertHelper(root->left, val);
            if(heightHelper(root->left) - heightHelper(root->right) == 2)
            {
                if(val < root->left->value)
                    rotateWithLeftChild(root);
                else
                    doubleWithRightChild(root);
            }
        }
        else if(root->value < val)
        {
            insertHelper(root->right, val);
            if(heightHelper(root->right) - heightHelper(root->left) == 2)
            {
                if(root->right->value < val)
                    rotateWithRightChild(root);
                else
                    doubleWithLeftChild(root);
            }
        }
        else;
        root->height = std::max(heightHelper(root->left), heightHelper(root->right)) + 1;
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
		delete root;
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
	

	/********************************* PUBLIC API *****************************/
public:

	AVLTree()
    {
        this->_root = NULL;
    }               // Basic initialization constructor


	~AVLTree() 
    {
	    destrutorHelper(this->_root);
	}

    Node<T>* getRoot()
    {
        return this->_root;
    }

    void setRoot(Node<T>*newnode)
    {
        this->_root = newnode;
    }

	/* Public API */
	void insert(T val) {
		// if (this->_root) {
			insertHelper(this->_root, val);
		// }
		// else {
		// 	this->_root = new Node<T>(val);
		// }
	}

	void print() {
		printInOrderHelper(this->_root);
	}


	int height() {
		return heightHelper(this->_root);
	}


    	void printLevelOrder() 
        {
        int h = heightHelper(this->_root);
        int i;
        for(i = 1; i <= h + 1; i++)
        {
			 printLevel(this->_root, i);
			 cout << endl;
        }
	}



    void rotateWithLeftChild(Node<T>*& k2)
    {
        Node<T>* k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = std::max(heightHelper(k2->left), heightHelper(k2->right));
        k1->height = std::max(heightHelper(k1->left), k2->height) + 1;
        k2 = k1;
    }

    void rotateWithRightChild(Node<T> *& k5)
    {
        Node<T> * k1 = k5->right;
        k5->right = k1->left;
        k1->left = k5;
        k5->height = std::max(heightHelper(k5->right), heightHelper(k5->left));
        k1->height = std::max(heightHelper(k1->right), k5->height) + 1;
        k5 = k1;
    }

    void doubleWithLeftChild(Node<T>*& k6)
    {
        rotateWithLeftChild(k6->right);
        rotateWithRightChild(k6);
    }

    void doubleWithRightChild(Node<T>*&k3)
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    int containHelper(Node<T>*& root)
    {
       for(int i = 1; i <= 100; i++)
       {
           if(root->value == i)
           {
               return 1;
           }

       }
            return 0;

    }

    int validateHelper(Node<T>*& root)
    {
        if(root == nullptr)
            return 1;
        if(validateHelper(root->left) == 0)
            return 0;
        else if(validateHelper(root->right) == 0)
            return 0;
        
        return std::abs(heightHelper(root->left) - heightHelper(root->right)) <= 1;
    }

    int validate()
    {
        return validateHelper(this->_root);
    }

    int contain()
    {
        return containHelper(this->_root);
    }




};
