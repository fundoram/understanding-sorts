#include "sorts.h"

int Count = 0;
int count1 = 0;
int count2 = 0;


void bubbleSort(ItemType theArray[], int n)
{
	Count = 0;

    bool sorted = false;
    for (int pass = 1; (pass < n) && !sorted; ++pass)
    {
        sorted = true;
        for (int index = 0; index < n - pass; ++index)
        {
            int nextIndex = index + 1;
            if (theArray[index] > theArray[nextIndex])
            {
                swap(theArray[index], theArray[nextIndex]);
                Count++;
                sorted = false;
            }
        }
    }
}

void swap(ItemType& x, ItemType& y)
{
    ItemType temp = x;
    x = y;
    y = temp;
}

void mergeSort(ItemType theArray[], int first, int last)
{
	count1 = 0;

    if (first < last)
    {
        // Sort each half
        int mid = first + (last - first) / 2; // Index of midpoint
        
        // Sort left half theArray[first..mid]
        mergeSort(theArray, first, mid);
        
        // Sort right half theArray[mid+1..last]
        mergeSort(theArray, mid + 1, last);
        
        // Merge the two halves
        merge(theArray, first, mid, last);
    }
}

void merge(ItemType theArray[], int first, int mid, int last)
{
    ItemType tempArray[MAX_SIZE];  // Temporary array
    
    int first1 = first;            // Beginning of first subarray
    int last1 = mid;               // End of first subarray
    int first2 = mid + 1;          // Beginning of second subarray
    int last2 = last;              // End of second subarray
    
    // While both subarrays are not empty, copy the smaller item into the temporary array
    int index = first1;            // Next available location in tempArray
    while ((first1 <= last1) && (first2 <= last2))
    {
        // At this point, tempArray[first..index-1] is in order
        if (theArray[first1] <= theArray[first2])
        {
            tempArray[index] = theArray[first1];
            first1++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            first2++;
        }  // end if
        index++;
    }  // end while
    
    // Finish off the first subarray, if necessary
    while (first1 <= last1)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1];
        first1++;
        index++;
    }  // end while
    
    // Finish off the second subarray, if necessary
    while (first2 <= last2)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];
        first2++;
        index++;
    }  // end for
    
    // Copy the result back into the original array
    for (index = first; index <= last; index++)
        theArray[index] = tempArray[index];
}

void radix(ItemType theArray[], int n)
{

	int m = getMax(theArray, n);


	for (int exp = 1; m / exp > 0; exp *= 10)
		count(theArray, n, exp);
}
int getMax(ItemType theArray[], int n)
{
	int max = theArray[0];
	for (int i = 1; i < n; i++)
	if (theArray[i] > max)
		max = theArray[i];
	return max;
}

void count(ItemType theArray[], int n, int exp)
{
	int output[MAX_SIZE]; // output array
	int i, count[10] = { 0 };

	// Store count of no of occurrences in count[] array
	for (i = 0; i < n; i++)
		count[(theArray[i] / exp) % 10]++;

	// Change count[i] so that count[i] contains correct position of this digit in output[] array
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
		count2++;             //counting no of moves
	}

	// output array
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(theArray[i] / exp) % 10] - 1] = theArray[i];
		count2++;
		count[(theArray[i] / exp) % 10]--;
	}

	// Copy the output array to theArray[], so that theArray[] can contain sorted numbers of current digit
	for (i = 0; i < n; i++)
		theArray[i] = output[i];
}

int getBubbleCount() {
	return Count;
}
int getMergeCount() {
	return count1;
}
int getRadixCount() {
	return count2;
}