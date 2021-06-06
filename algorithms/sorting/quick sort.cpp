/*
 *		Quick Sort
 * 		Time Complexity: O(nlog(n))
 *
 */

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high)
{
	int piv = arr[high];
	int j = low-1;

	for(int i=low; i<high; i++)
	{
		if(arr[i] < piv)
		{
			j++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[j+1], &arr[high]);
	return (j+1);
}

void quicksort(int arr[], int low, int high)
{
	if(low<high)
	{
		int pivot = partition(arr, low, high);

		quicksort(arr, low, pivot-1);
		quicksort(arr, pivot+1, high);
	}
}

int main()
{
	int size;

	cout<<"Enter size: ";
	cin>>size;

	int arr[size];

	for(int i=0; i<size; i++)
		cin>>arr[i];

	quicksort(arr, 0, size);

	for(int i=0; i<size; i++)
		cout<<arr[i]<<" ";

	return 0;
}