#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

const int MaxN=4*100*100+25;

int in[MaxN],Count[MaxN],size1,size2,size3,a,b,c,counter;

void put (int input,int size)
{
	int j=0;
	while((in[j]<=input)&&(j<size))
	{
		if(in[j]==input)
			{
				Count[j]++;
				j=size;
			}
		j++;
	}
}

int main()
{
	cin >> size1;
	for (int i=0;i<size1;i++)
	{
		cin >> in[i];
	}	
	cin >> size2;
	for (int i=0;i<size2;i++)
	{		
		cin >> a;
		put(a,size1);
	}	
	cin >> size3;
	for (int i=0;i<size3;i++)
	{
		cin >> a;
		put(a,size1);
	}
	for(int i=0;i<size1;i++)
	{
		//cout << Count[i] << endl;
		counter= (Count[i]==2)? counter+1 : counter;
	}
	cout << counter << endl;
	//system("pause");
}
