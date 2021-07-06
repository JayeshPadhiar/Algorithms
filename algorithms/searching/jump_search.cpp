/*
 *		Jump Search
 * 		Time Complexity: O(root n)
 */

#include <iostream>
#include <math.h>
using namespace std;

int jumpsearch(int arr[], int size, int num)
{
	int steps = ceil(sqrt(size));
	cout<<"Steps: "<<steps<<endl;

	int index = 0;

	for(int i=0; i<=steps; i++)
	{
		index = i*steps;

		if(arr[index] == num)
			return index;

		if(arr[index] > num)
			break;
	}

	for(int i=index; i>(index-steps); i--)
		if(arr[i] == num)
			return i;

	return -1;
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

	int index = jumpsearch(arr, size, num);
	(index == -1)? cout<<"Not found"<<endl:cout<<"Found at index: "<<index;

	return 0;
}