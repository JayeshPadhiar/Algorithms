/*
 *		Bubble Sort
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

void bubblesort(int arr[], int size)
{
	for(int i=0; i<size; i++)
	{
		bool swapped = false;
		for(int j=0; j<size-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
				swapped = true;
			}
		}

		if(!swapped)
			break;
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

	bubblesort(arr, size);

	for(int i=0; i<size; i++)
		cout<<arr[i]<<" ";

	return 0;
}