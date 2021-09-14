#pragma once
#include "Node.hpp"

template <typename T, typename K>

class LinkedList
{
private:
    Node<T, K> *pHead;

public:
    LinkedList()
    {
        pHead = nullptr;
    }
    ~LinkedList()
    {
    }

    bool IncludeC(const T &command)
    {
        bool result = false;
        Node<T,K> * temp = pHead;

           while (temp != nullptr)
            {
                if (temp->getCommand() == command)
                {
                    return true;
                }

                temp = temp->getNext();
            }


        return false;


    }

    bool IncludeD(const K & description)
    {
        bool result = false;
        Node<T, K> * temp = pHead;

        while(temp != nullptr)
        {
            if(temp->getDescription() == description)
            {
                result = true;
            }

            temp = temp->getNext();
        }

        return result;

    }

    void InsertAtfront(const T &command, const K &description)
    {
        Node<T, K> *newnode = new Node<T, K>(command, description);

        if (pHead == nullptr)
        {
            pHead = newnode;
        }
        else
        {
            newnode->setNext(pHead);

            pHead = newnode;
        }
    }

    void removeFrontNode(const T &command, const K &description) //needed when removing commands from the list
    {
        Node<T, K> * temp = pHead;

        if (pHead == nullptr)
        {
            cout << "Empty Node.." << endl;
        }

        else
        {
            pHead = pHead->getNext();
            temp->setNext(nullptr);
            delete temp;
        }
    }

    void removeNode(const T & command, const K & description)
    {
        Node<T,K> * prev = nullptr;
        Node<T,K> * temp = pHead;

        while(temp != nullptr && temp->getCommand() != command)
        {
            temp = temp->getNext();
        }

        if(prev == nullptr)
        {
            pHead = pHead->getNext();
            temp->setNext(nullptr);
            delete temp;
        }
        else
        {
            prev->setNext(temp->getNext());
            delete temp;
        }
    }

    Node<T, K> *getNode(int index)
    {
        int i = 0;

        Node<T, K> *temp = pHead;

        while (temp != nullptr)
        {
            if (i == index)
            {
                return temp;
            }

            temp = temp->getNext();
            i++;
        }
        return NULL;
    }

    int getLenght()
    {
        int count = 0;
        Node<T, K> *temp = pHead;

        while (temp != nullptr)
        {
            temp = temp->getNext();
            count++;
        }

        return count;
    }
};
