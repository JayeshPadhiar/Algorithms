/*
 *	Binary Search using recursion
 * 	Time complexity: O(log n)
 */

#include <iostream>
using namespace std;

int binarysearch(int arr[], int left, int right, int num)
{
	int mid = left+(right-left)/2;

	if(right >= left)
	{
		if(arr[mid] == num)
			return mid;
		else if(arr[mid] > num)
			return binarysearch(arr, left, mid-1, num);
		else
			return binarysearch(arr, mid+1, right, num);
	}
	else
	 return -1;
}

int main()
{
	int size, num;
	cout<<"Enter size: ";
	cin>>size;

	cout<<"Enter elements\n";

	int arr[size];

	for(int i=0; i<size; i++)
		cin>>arr[i];

	cout<<"Enter number to search: ";
	cin>>num;

	int ans = binarysearch(arr, 0, size, num);
	(ans != -1)? cout<<"Found number at "<<ans<<endl : cout<<"Number not in the array\n";

	return 0;
}