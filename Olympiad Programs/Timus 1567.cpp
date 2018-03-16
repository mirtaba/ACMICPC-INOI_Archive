#include <iostream>
#include <cstdio>

using namespace std;
char a;
long long b;

int main()
{
	//cin.get(a,10010);
	while(cin >> noskipws >> a)  
	{
		if (int(a)>=97 && int(a)<=122)
		{
		if((a%3)==0)
			b+=3;
		else
			b+=(a%3);
		}
		if(int(a)==32)
		b++;
		if(int(a)==33)
		b+=3;
		if(int(a)==44)
		b+=2;
		if(int(a)==46)
		b++;
	}
	cout << b << endl;
}
