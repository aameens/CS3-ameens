#pragma once

#include <iostream>

using namespace std;

class UnionFind
{
    const static int size = 7;
    int array[size];
    int component_size[size]; // size array for components

    public:

    UnionFind()
    {
        for (int i = 0; i < size; i++)
        {
            array[i] = i; // Initializes node values to their roots
            component_size[i] = 1; // Initializes the size of each component to 1
        }
    }

    void quickUnion(int first, int second)
    {
        if (connected(first, second)) return; // If first and second are already in the same array, don't run the rest of the union function.

        first = findRoot(first);
        second = findRoot(second);

        component_size[second] += component_size[first]; // Updates the size of the component
        array[first] = array[second];
    }

    int findRoot(int index)
    {
        while (index != array[index])
        {
            array[index] = array[array[index]]; // array[array[index]] is what implements path compression.
            index = array[index];
        }
        return array[index];
    }

    int findComponentSize(int index) { return component_size[findRoot(index)]; } // component size array is only accurate at component roots, so this makes sure to look at the target's root as well

    bool connected(const int &first, const int &second) { return findRoot(first) == findRoot(second); }

    void print()
    {
        for (int i = 0; i < size; i++) { cout << i << ':' << array[i] << "     "; }
        cout << endl;
    }
};
