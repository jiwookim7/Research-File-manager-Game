#include "FileManager.hpp"

void FileManager::loadCommand()
{

    ifstream fin;
    string line;
    fin.open("command.csv");

    while (getline(fin, line))
    {
        istringstream iss2(line);

        string command;

        getline(iss2, command, ',');

        string description;

        getline(iss2, description, '"');
        getline(iss2, description, '"');

        store.InsertAtfront(command, description);

        // cout << store.getNode(0)->getDescription() << endl;
    }

    fin.close();
}

int FileManager::loadProfile()
{

    string line;

    ifstream fin; //read file

    int i = 0;

    fin.open("profiles.csv");

    if (!fin)
    {
        cout << "Error while opening file " << endl;
        exit(1);
    }

    while (getline(fin, line))
    {

        istringstream iss1(line);

        string name;

        getline(iss1, name, ',');

        string point;

        getline(iss1, point, '\0');

        // name = strtok(line, ",");

        // point = strtok(NULL, ",");

        profiles[i].first = name;
        profiles[i].second = stoi(point);

        i++;
    }

    fin.close();
    return i;
}



void FileManager::storeCommand()
{
    int index = 0;

    Node<string, string> * temp =  store.getNode(index);

    fstream fout;

    fout.open("command.csv");

    int k = store.getLenght();

    for(int i = 0; i < k; i++)
    {
        // write
        fout << temp->getCommand() << ",\"" << temp->getDescription() << "\"" << endl;
        temp = temp->getNext();
    }
    fout.close();
}

void FileManager::storeProfile()
{
    fstream fout;
    fout.open("profiles.csv");

    for(int i =0; i < 10; i++)
    {
        fout << profiles[i].first << "," << profiles[i].second << endl;
    }
    fout.close();


}

 Node<string, string> * FileManager::getCommandNode(int index)
 {
     
    return store.getNode(index);

 }

int FileManager::getLength()
{
    return store.getLenght();
}


 bool FileManager::includeC(string & command)
 {
     return store.IncludeC(command);
 }

 bool FileManager::includeD(string & description)
 {
     return store.IncludeD(description);
 }

 void FileManager::insertAtFront(string & command, string & description)
 {
     store.InsertAtfront(command, description);

 }

void FileManager::remove(string & command, string & description)
{
    store.removeNode(command, description);
}