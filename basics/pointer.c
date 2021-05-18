#include <stdio.h>

int main()
{
	int x = 5;

	int *ptr;
	ptr = &x;

	printf("The value of x is %d\n", x);
	printf("The address of x is %p\n", &x);
	printf("The value of *ptr is %d\n", *ptr);
	printf("The value of ptr is %p\n", ptr);
	printf("The address of ptr is %p\n", &ptr);

	*ptr = 10;
	printf("\nThe value of x now is %d\n", x);
	printf("%d\n", *ptr);

	return 0;

}