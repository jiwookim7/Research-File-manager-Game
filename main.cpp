
#include "LinkedList.hpp"
#include "FileManager.hpp"



//"ADVANTAGES/DISADVANTAGES LINKED LIST:"
//ADVANtAGES: Insertion and deletion operations are easier in the linked list because there is no need to shift elements after the insertion and delection. Yet, the address present in the next pointer needs to be updated.
//DISADVANTAGES: Random access is not possible in a linked list due to the dynamic memory allocation.
//"ADVANTAGES/DISADVANTAGES ARRAY: "
//ADVANTAGES: 2D array is used to represent matrices. And the search process can be applied to an array easily.
//DISADVANtAGES: The array size is fixed because it is static. Therefore, the memory which is allocated to its size cannot be increased or decreased.
//


void displaymenu()
{
    cout << "1. Game Rules " << endl;
    cout << "2. Play Game " << endl;
    cout << "3. Load Previous Game " << endl;
    cout << "4. Add Command " << endl;
    cout << "5. Remove Command" << endl;
    cout << "6. Exit " << endl;
    
}

int getOption()
{
    int option = 0;

    cin >> option;

    if (option < 1 || option > 6)
    {
        cout << "Invalid option" << endl;
    }
    return option;
}

int determineOption()
{
    int option = 0;

    do
    {
        displaymenu();
        option = getOption();
        // system("cls");

        if ((option < 1) || (option > 6))
        {
            cout << "Invalid option" << endl;
        }

        /* code */
    } while ((option < 1) || (option > 6));
    return option;
}

void ruleofthegame()
{
    cout << "------------Learning Linux Commands Matching Game------------" << endl;
    cout << "1. Enter your user for a name. " << endl;
    cout << "2. Enter how many commands/questions to generate for matching. " << endl;
    cout << "3. A random Linux command will be displayed on the screen. " << endl;
    cout << "4. One of those descriptions must be the correct description. " << endl;
    cout << "5. You will pick the right description with your given command. " << endl;
    cout << "6. If you get the right description, you will earn 1 point. " << endl;
    cout << "7. If not, you will lose 1 point. " << endl;
    cout << "8. No matter the result of each round, the next question is displayed. " << endl;
}

bool PlayGame(pair<string, int> profile[], int & profileCount, FileManager &a, Node<string, string> *b)
{
    // FileManager a;
    // Node<string, string> *b;
    // return true when new user added, return false otherwise.
    bool newUser = true;
    string user;
    int pointer = 0, select = 0, index = 0, answer = 0;
    cout << "What is your user name: " << endl;
    cin >> user;

    for (int i = 0; i < 10; i++) //if the name is overlap
    {
        if (profile[i].first == user)
        {
            profile[i].first = user;
            index = i;
            newUser = false;
        }
    }

    if (newUser == true) //if it is not overlap
    {
        index = profileCount;
    }

    profile[index].first = user;
    cout << "How many commands/questions to generate for matching: " << endl;
    cin >> select;

    for (int i = 0; i < select; i++)
    {
        b = a.getCommandNode(rand() % a.getLength()); //randomly generate command side

        cout << b->getCommand() << endl; //display

        int randNum = rand() % 3; // rand num : 0,1,2

        for (int i = 0; i < 3; i++)
        {
            // cout << b->getDescription() << endl;
            // cout << a.getCommandNode(rand() % a.getLength())->getDescription() << endl;

            if (i == randNum)
            {
                cout << (i + 1) << ": " << b->getDescription() << endl;
                //add i + 1 because it will start at zero
                //right answer will shuffle
            
            }
            else
            {
                cout << (i + 1) << ": " << a.getCommandNode(rand() % a.getLength())->getDescription() << endl;
            }
        }
        cout << "User input: " << endl;
        cin >> answer;

        if (answer == randNum + 1)
        {
            cout << "Correct! " << b->getCommand() << b->getDescription() << " is " << answer << "." << endl;
            ++pointer;
            cout << "You have been awarded 1 point. Your point total is: " << pointer << endl;
        }
        else
        {

            cout << "Incorrect! " << b->getCommand() << b->getDescription() << "."
                 << "You have lost 1 point." << endl;
            --pointer;
            cout << "Your point total is:  " << pointer << endl;
        }

        profile[index].second = pointer;
    }
    return newUser;
}

void AdvantagesDisadvantages(pair<string, int> profile[], FileManager & a)
{
    string advantage;
    cout << "Enter the 1 advantage of linked list: " << endl;
    cin >> advantage;

    string disAdvantage;
    cout << "Enter the 1 disadvantage of linked list: " << endl;
    cin >> disAdvantage;

    for(int i = 0; i < 10; i++)
    {
        if(advantage != profile[i].first)
        {
            profile[i].first = advantage;
            profile[i+1].first = disAdvantage;
            a.storeProfile();
            break;
        }
    }

}

int main(int arcg, char *argv[])
{

    FileManager a;
    Node<string, string> *b;
    LinkedList<string, string> store1;
    pair<string, int> profile[10];

    srand(time(0));

    int number = 0;
    string user = "";
    string name = "";
    string command = "";
    string newCommand = "";
    string description = "";
    int select = 0;
    int answer = 0;
    int pointer = 0;
    int profileCount = 0;
    int index = 0;

    a.loadCommand();
    profileCount = a.loadProfile();

    while (number != 7)
    {
        number = determineOption();

        switch (number)
        {
        case 1:

            ruleofthegame();
            break;

        case 2:
            if (PlayGame(profile, profileCount, a, b))
            {
                profileCount++;
            }
            break;
        case 3:
            cout << "Enter the user for a profile name: " << endl;
            cin >> name;

            for (int i = 0; i < 10; i++)
            {
                if (profile[i].first == name)
                {
                    cout << profile[i].first << endl;
                    cout << profile[i].second << endl;

                    index = i;

                    break;
                }
            }

            if (PlayGame(profile, profileCount, a, b))
            {
                profileCount++;
            }

            // cout << "What is your user name: " << endl;
            // cin >> user;
            // profile[index].first = user;

            // cout << "How many commands/questions to generate for matching: " << endl;
            // cin >> select;

            // for (int i = 0; i < select; i++)
            // {
            //     b = a.getCommandNode(rand() % a.getLength());

            //     cout << b->getCommand() << endl;

            //     int randNum = rand() % 3;

            //     for (int i = 0; i < 3; i++)
            //     {
            //         if (i == randNum)
            //         {
            //             cout << (i + 1) << ": " << b->getDescription() << endl;
            //         }
            //         else
            //         {
            //             cout << (i + 1) << ": " << a.getCommandNode(rand() % a.getLength())->getDescription() << endl;
            //         }
            //     }
            //     cout << "User input: " << endl;
            //     cin >> answer;

            //     if (answer == randNum + 1)
            //     {
            //         cout << "Correct! " << b->getCommand() << b->getDescription() << " is " << answer << "." << endl;
            //         ++pointer;
            //         cout << "You have been awarded 1 point. Your point total is: " << pointer << endl;
            //     }
            //     else
            //     {

            //         cout << "Incorrect! " << b->getCommand() << b->getDescription() << "."
            //              << "You have lost 1 point." << endl;
            //         --pointer;
            //         cout << "Your point total is:  " << pointer << endl;
            //     }
            // }

            break;
        case 4:

            cout << "Type the command you want to add: " << endl;
            cin >> command;
            cout << "Type the description you want to add: " << endl;
            cin >> description;

            // while (a.include(command))
            while (a.includeC(command) || a.includeD(description))
            {

                cout << "Invalid the program has detected duplication..." << endl;
                cout << "Type the new command you want to add: " << endl;
                cin >> command;

                cout << "Type the new description you want to add: " << endl;
                cin >> description;
            }

            a.insertAtFront(command, description);

            break;
        case 5:
            cout << "Enter the command you want to remove: " << endl;
            cin >> command;

            while(1)
            {
                if(a.includeC(command) == true)
                {
                    a.remove(command,description);
                    cout << "It is removed successfully... " << endl;
                    break;
                }
                else
                {
                    cout << "Enter the command you want to remove again: " << endl;
                    cin >> command;

                }
            }

            // while(a.include(command) == true)
            // {

            //     a.remove(command, description);
            //     cout << "It is removed successfully... " << endl;
            //     break;

            // if(a.include(command) != true)
            // {
            //     cout << "Enter the command you want to remove again: " << endl;
            //     cin >> newCommand;

            //     if(a.include(newCommand) == true)
            //     {
            //         a.remove(newCommand, description);
            //         cout << "It is removed successfully... " << endl;
            //         break;
            //     }
            // }

            // }

            break;
        case 6:
            a.storeCommand();
            a.storeProfile();

            break;
        }
    }
}

// clear,"Used to clear the terminal screen"
// grep,"Searches a file for a particular pattern of characters, and displays all lines that contain that pattern"
// alias,"Instructs the shell to replace one string with another string while executing the commands"
// who,"Used to get information about currently logged in user on to system"
// ps,"Used to list the currently running processes and their PIDs along with some other information depends on different options"
// g++,"Used for preprocessing, compilation, assembly and linking of source code to generate an executable file"
// ssh,"Protocol used to securely connect to a remote server/system"
// rm,"Used to remove objects such as files, directories, symbolic links and so on from the file system like UNIX"
// cd,"Known as change directory command. It is used to change current working directory"
// finger,"It is a user information lookup command which gives details of all the users logged in"
// exit,"Used to exit the shell where it is currently running"
// df,"Used to display information related to file systems about total space and available space"
// cat,"Reads data from file and gives their content as output. It helps us to create, view, concatenate files"
// top,"Provides a dynamic real-time view of the running system"
// make,"While it helps administrators in compiling and installing many open source utilities through the command line, programmers use it to manage the compilation of their large and complicated projects"
// man,"Used to display the user manual of any command that we can run on the terminal"
// mv,"Used to move one or more files or directories from one place to another in file system like UNIX"
// rmdir,"Used to remove empty directories from the filesystem in Linux"
// ls,"ls will list files in the current working directory"
// find,"Used to find files and directories and perform subsequent operations on them"
// echo,"Used to display line of text/string that are passed as an argument"
// chown,"Used to change the file Owner or group"
// chmod,"Used to change the access mode of a file"
// kill,"Used to terminate processes manually. kill command sends a signal to a process which terminates the process"
// gcc,"GNU Compiler Collections is used to compile mainly C and C++ language. It can also be used to compile Objective C and Objective C++"
// scp,"Used to copy file(s) between servers in a secure way"
// cp,"Used to copy files or group of files or directory"
// mkdir,"Allows the user to create directories. This command can create multiple directories at once"
// pwd,"It prints the path of the working directory, starting from the root"
// free,"Displays the total amount of free space available along with the amount of memory used and swap memory in the system, and also the buffers used by the kernel"