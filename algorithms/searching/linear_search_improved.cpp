/*
 * Improved Linear Search
 * Uses left++ and right--
 * Hence reduces time complexity
 */

#include <iostream>
using namespace std;


int linearsearch(int arr[], int size, int num)
{
	int left = 0;
	int right = size;
	while(left <= right)
	{
		if(arr[left] == num)
			return left;

		if(arr[right] == num)
			return right;

		left++;
		right--;
	}

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
	(index == -1)? cout<<"Not found"<<endl:cout<<"Found at index: "<<index;

	return 0;
}