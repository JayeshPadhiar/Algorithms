/*
 *		Selection Sort
 * 		Time Complexity: O(n^2)
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

void selectionsort(int arr[], int size)
{
	int min_index;
	for(int i=0; i<size; i++)
	{
		min_index = i;
		for(int j=i+1; j<size; j++)
			if(arr[j] < arr[min_index])
				min_index = j;

		swap(&arr[i], &arr[min_index]);
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

	selectionsort(arr, size);

	for(int i=0; i<size; i++)
		cout<<arr[i]<<" ";

	return 0;
}