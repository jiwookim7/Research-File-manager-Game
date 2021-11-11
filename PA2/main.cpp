#include "AVLTree.hpp"
#include <vector>
#include <algorithm>
#include <random>

int main(void)
{
    //AVLTree<int> * Avl = new AVLTree<int>();
    // Avl->insert(10);
    // Avl->insert(9);
    // Avl->insert(8);
    // Avl->insert(7);
    // Avl->insert(6);
    // Avl->insert(5);
    //Avl->insert(Avl->getRoot(), 10);
    //Avl->insert(Avl->getRoot(), 11);
    //Avl->insert(Avl->getRoot(), 12);

    // cout << Avl->height() << endl;

    // cout <<Avl->validate() << endl;

    // Avl->printLevelOrder();


    vector<int> v1;
    vector<int> v2;
    vector<int> v3;



    for (int i = 1; i <= 100; i++)
    {
        if (i % 2 == 1)
            v1.push_back(i);
    }

    for(int i = 100; i >= 1; i--)
    {
        if(i % 2 == 1)
        {
            v2.push_back(i);
        }
    }

    for(int i = 1; i <= 100; i++)
    {
        if(i % 2 == 1)
        {
            v3.push_back(i);

        }
    
    }

auto rng = std::default_random_engine {};
std::shuffle(std::begin(v3), std::end(v3), rng);





//     AVLTree<int> tree1;
//     for (int i = 0; i < (int)v1.size(); i++)
//     {
//         tree1.insert(v1[i]);
//     }
//     cout << tree1.validate() << endl;

    
//     tree1.printLevelOrder();
// }

//     AVLTree<int> tree2;

//     for(int i = 0; i < (int)v2.size(); i++)
//     {
//         tree2.insert(v2[i]);
//     }

//     cout << tree2.validate() << endl;

//     tree2.printLevelOrder();
// }

    AVLTree<int> tree3;

    for(int i = 0; i < (int)v3.size(); i++)
    {
        tree3.insert(v3[i]);
    }

    cout << tree3.validate() << endl;
    cout << tree3.contain() << endl;
    tree3.printLevelOrder();
}
