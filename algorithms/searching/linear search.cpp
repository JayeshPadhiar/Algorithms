/*
 * Linear Search
 * Time Complexity = O(n)
 */

#include <iostream>
using namespace std;

int linearsearch(int arr[], int size, int num)
{
	for(int i=0; i<size; i++)
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

	int index = linearsearch(arr, size, num);
	cout<<"Index: "<<index;

	return 0;
}