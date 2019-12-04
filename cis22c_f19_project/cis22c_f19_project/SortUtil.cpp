#include "SortAlgos.h"

/* Partition to create a descending sort order */
int SortUtil::partition(Pair<Movie*, int>** arr, int low, int high)
{
	Pair<Movie*, int>* pivot = arr[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot  
		if (*arr[j] > *pivot)
		{
			i++; // increment index of smaller element  
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}
void SortUtil::quickSort(Pair<Movie*, int>** arr, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
	else
		return;
}
// A utility function to swap two elements
void SortUtil::swap(Pair<Movie*, int>* a, Pair<Movie*, int>* b)
{
	Pair<Movie*, int> t = *a;
	*a = *b;
	*b = t;
}