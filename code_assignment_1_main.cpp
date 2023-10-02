#include <iostream>

#include "code_assignment_1_classes.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    char operationChoice;
    int input1, input2;
    UnionFind uf;
    
    uf.print();

    while (operationChoice != 'X')
    {
        cout << "Enter the operation and the nodes you want to perform it on, or 'X' to exit the program: ";
        cin >> operationChoice;
        if (operationChoice == 'X') break; // Exits program

        if (operationChoice == 'U') // Union operation
        {
            cin >> input1 >> input2;
            uf.quickUnion(input1, input2);
        }
        else if (operationChoice == 'Q') // Query operation
        {
            cin >> input1;
            cout << "Size of this component is: " << uf.findComponentSize(input1) << endl;
        }
        uf.print();
    }

    return 0;
}
