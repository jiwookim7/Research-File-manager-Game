#pragma once

#include "LinkedList.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>


using namespace std;

class FileManager
{
public:
    void loadCommand();
    int loadProfile();

    void storeCommand();
    void storeProfile();

    Node<string, string> * getCommandNode(int index);

    int getLength();

    bool includeC(string & command);

    bool includeD(string & description);

    void insertAtFront(string & command, string & description);

    void remove(string & command, string & description);

private:

    pair<string, int> profiles[10]; //don't want to change the artribute
    LinkedList<string, string> store;
};