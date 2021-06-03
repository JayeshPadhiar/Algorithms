/*
 *		Insertion Sort
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

void insertionsort(int arr[], int size)
{
	int key, j;

	for(int i=1; i<size; i++)
	{
		key = arr[i];
		j=i-1;

		while(j>=0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = key;
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

	insertionsort(arr, size);

	for(int i=0; i<size; i++)
		cout<<arr[i]<<" ";

	return 0;
}