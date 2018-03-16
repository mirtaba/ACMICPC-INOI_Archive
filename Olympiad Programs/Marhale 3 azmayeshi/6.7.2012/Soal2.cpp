#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

long long  a[1000*1000+2],first,last,oper,S,forit=8388607;

void makeit()
{
	for (long long i=1; i<(1000*1000+1); i++)
	{
		
			a[i]=(a[i] ^ forit);
	}
	
}
void fromback();
void fromfront()
{
	cerr << "i'm front in:" << first << " and a[first] is:"<< a[first] <<endl;
	while (first!=last || a[first]!=0)
	{
		long long b=(a[first]>>1);
		cerr << a[first] << "  " <<b << endl;
		system("pause");
		long long d=(a[first]-b);
		if (d == 1)
		{
			a[first]=b;
			if (a[first]==0)	
			{
				cout <<"it works" << endl;
				first++;
			}
			makeit();
			S++;		
		}
		else
		{
			a[first]=b;
			if (a[first]==0)	
			{
				first++;
			}
			fromback();
		}
	}
}
void fromback()
{
	cerr << "i'm front in:" << last << " and a[last] is:"<< a[last] <<endl;
	while (first!=last || a[last]!=0)
	{
		if ((a[last]%2)== 1)
		{
			a[last]/=2;
			if (a[last]==0)	
			{
				last--;
			}
			makeit();
			S++;	
		}
		else
		{
			a[last]/=2;
			if (a[last]==0)	
			{
				last--;
			}
			fromfront();
		}
	}	
}
int main()
{
	for (long long i=1;i<(1000*1000+1);i++)
	{
		a[i]=i;
	}
	first=1;
	last=(1000*1000+1);
	oper=1;
	S=0;
	fromfront();
	
	cout << S;
	
	
	system("pause");
}
