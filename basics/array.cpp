#include <iostream>
using namespace std;

int main()
{
	int arr[200] = {1,2,3,4,5,6,7,8,9};

	int *p = arr;

//	int *p = arr;

	cout<<*p+1<<endl;

	return 0;
}