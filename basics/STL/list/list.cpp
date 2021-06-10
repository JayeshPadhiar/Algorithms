#include <iostream>
#include <list>
using namespace std;

void display(list<int> a)
{
	for(auto i=a.begin(); i!=a.end(); i++)
		cout<<*i<<" ";
	cout<<endl;
}

int main()
{
	list<int> a = {1,2,3,4,5};
	list<int> b = {9,8,7,6,5};

	display(a);

	cout<<a.size()<<endl;
	cout<<a.front()<<endl;
	cout<<a.back()<<endl;

	a.pop_front();
	a.pop_back();

	display(a);

	cout<<a.empty()<<endl;

	a.assign(b.begin(), b.end());

	a.sort();

	display(a);

	cout<<a.max_size()<<endl;

	a.clear();

	cout<<a.size();
	display(a);

	a = {1,2,3,4,5};
	b = {9,8,7,6,5};

	display(a);
	display(b);

	a.swap(b);

	display(a);
	display(b);

	a = b;

	display(a);
	display(b);

	return 0;
}