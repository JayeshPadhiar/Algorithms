/*
 *		Exponential Search
 * 		Time Complexity: O(log n)
 */

#include <iostream>
#include <math.h>
using namespace std;

int binarysearch(int arr[], int left, int right, int num)
{
	while(right >= left)
	{
		int mid = left+(right-left)/2;

		if(arr[mid] == num)
			return mid;
		else if(arr[mid] > num)
			right = mid-1;
		else
			left = mid+1;
	}

	return -1;
}

int exponentialsearch(int arr[], int size, int num)
{
	if(arr[0] == num)
		return 0;

	int i=1;
	while(i<size && arr[i]<=num)
	{
		if(arr[i]==num)
			return i;
		else
			i*=2;
	}

	return binarysearch(arr, i/2, min(i, size-1), num);
}

int main()
{
	int arr[100], size, num;

	cout<<"Enter Size : ";
	cin>>size;

	cout<<"Enter Elements\n";

	for(int i=0; i<size; i++)
		cin>>arr[i];

	cout<<"Enter num to search : ";
	cin>>num;

	int index = binarysearch(arr, 0, size, num);
	(index == -1)? cout<<"Not found"<<endl:cout<<"Found at index: "<<index;

	return 0;
}