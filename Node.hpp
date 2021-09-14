#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <time.h>

using namespace std;

template <typename T, typename K>

class Node
{
private:
    Node<T, K> *next;
    T command;
    K description;

public:
    Node()
    {
        this->next = nullptr;
    }

    Node(const T &command, const K &description)
    {
        this->command = command;
        this->description = description;
        this->next = nullptr;
    }

    void setCommand(const T &command)
    {
        this->command = command;
    }
    void setDescription(const K &description)
    {
        this->description = description;
    }

    T &getCommand()
    {
        return command;
    }

    K &getDescription()
    {
        return description;
    }

    Node<T, K> *getNext()
    {
        return this->next;
    }

    void setNext(Node<T, K> *next)
    {
        this->next = next;
    }
};
