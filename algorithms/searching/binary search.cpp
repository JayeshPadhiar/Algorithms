/*
 *	Binary Search
 * 	Time Complexity: O(log n)
 */

#include <iostream>
using namespace std;

int binarysearch(int arr[], int size, int num)
{
	int left=0, right=size;

	while(arr[left] <= num && num <= arr[right])     // while(r >= l)
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

	int ans = binarysearch(arr, size, num);
	(ans != -1)? cout<<"Found number at "<<ans<<endl : cout<<"Number not in the array\n";

	return 0;
}