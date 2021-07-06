/*
 *		Merge Sort
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

void merge(int arr[], int left, int mid, int right)
{
	int lsize = mid-left+1;
	int rsize = right-mid;

	int L[lsize], R[rsize];

	for(int i=0; i<lsize; i++)
		L[i] = arr[left+i];

	for(int i=0; i<rsize; i++)
		R[i] = arr[mid+i+1];


	int i=0, j=0, k=left;

	while(i<lsize && j<rsize)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i<lsize)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j<rsize)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergesort(int arr[], int left, int right)
{
	if(left < right)
	{
		int mid = left + (right-left)/2;
		mergesort(arr, left, mid);
		mergesort(arr, mid+1, right);
		merge(arr, left, mid, right);
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

	mergesort(arr, 0, size);

	for(int i=0; i<size; i++)
		cout<<arr[i]<<" ";

	return 0;
}