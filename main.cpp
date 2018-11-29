//Matthew Fundora
//Tony Biehl
//CSIS 211
//Lab 4

#include "sorts.h"
#include <iostream>
#include <random>

using namespace std;


int main()
{
	const int MAX_SIZE = 20000;

    int ary[MAX_SIZE];
    int seed = 39;
    
    srand(seed);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        ary[i] = rand() % MAX_SIZE;
    }
    
    bubbleSort(ary, MAX_SIZE);
    
    cout << "The seed used is " << seed << endl;
    cout << "Bubble sort had " << getBubbleCount() << " swaps." << endl;
    cout << " The first ten values are: ";
    for(int i = 0; i < 10; i++) {
        cout << ary[i] << " ";
    }
    cout << endl;
    cout << "The last ten values are: ";
    for(int j = MAX_SIZE - 10; j < MAX_SIZE; j++) {
        cout << ary[j] << " ";
    }
    cout << endl;
    cout << endl;
    
    mergeSort(ary, 0, MAX_SIZE - 1);
    cout << "Merge sort had " << getMergeCount() << " swaps." << endl;
    cout << " The first ten values are: ";
    for(int i = 0; i < 10; i++) {
        cout << ary[i] << " ";
    }
    cout << endl;
    cout << "The last ten values are: ";
    for(int j = MAX_SIZE - 10; j < MAX_SIZE; j++) {
        cout << ary[j] << " ";
    }
    cout << endl;
    cout << endl;
    
  radix(ary, MAX_SIZE);
    
    cout << "Radix sort had " << getRadixCount() << " swaps." << endl;
    cout << " The first ten values are: ";
    for(int i = 0; i < 10; i++) {
        cout << ary[i] << " ";
    }
    cout << endl;
    
    cout << "The last ten values are: ";
    for(int j = MAX_SIZE - 10; j < MAX_SIZE; j++) {
        cout << ary[j] << " ";
    }
	
    system("pause");
    return 0;
}

