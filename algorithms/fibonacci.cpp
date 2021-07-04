//	Fibonacci Sequence

#include <iostream>
using namespace std;

int fibonacci(int n)
{
	int x=0, y=1, ans=y;
	
	if(n == 0)
		return 0;
	
	for(int i=1; i<n; i++)
	{
		cout<<ans<<endl;
		ans = x+y;
		x = y;
		y = ans;
	}
	
	return ans;
}

int main()
{
	int n;
	
	cout<<"Enter fibo : ";
	cin>>n;
	cout<<fibonacci(n);	
	return 0;
}
