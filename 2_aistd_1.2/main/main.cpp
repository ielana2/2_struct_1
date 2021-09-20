#include <iostream>
#include "RedBlackTree.h"

int main()
{
    RBTree<int, char>* RB = new RBTree<int, char>();

    cout << "first test" << endl;
    RB->insert(2, 'a');
    RB->insert(3, 'b');
    RB->print();

    cout << "second test" << endl;
    RB->remove(3);
    RB->print();

    cout << "third test" << endl;
    RB->insert(1, 'c');
    RB->print();
}