#include <stdio.h>

void input(int arr[], int size)
{
	for(int i=0; i<size; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void pointerinput(int *arr, int size)
{
	for(int i=0; i<size; i++)
	{
		scanf("%d", arr+i);
	}
}

void output(int arr[], int size)
{
	for(int i=0; i<size; i++)
	{
		printf("%d ", arr[i]);
	}
}

void pointeroutput(int *arr, int size)
{
	for(int i=0; i<size; i++)
	{
		printf("%d ", *(arr+i));
	}
}

int main()
{
	int n;
	int arr[10];

	printf("Length of array : ");
	scanf("%d", &n);

	pointerinput(arr, n);
	pointeroutput(arr, n);

}