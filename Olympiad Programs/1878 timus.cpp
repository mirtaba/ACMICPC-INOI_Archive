#include <iostream>
#include <cmath>
#include <cstdio>
#include<algorithm>

using namespace std;
const int MAXn = 4*10 +5;
int table [MAXn][MAXn];
int cou=0,color[5],bcolor;

int main()
{
	for (int i=1;i<=4;i++)
	{
		for (int d=1;d<=4;d++)
		{
			cin >> table[i][d];
		}
	}
	for (int i=1;i<=2;i++)
	{
		for (int d=1;d<=2;d++)
		{
			color[table[i][d]]++;
		}
	}
	bcolor =1;
	for (int i=1;i<=4;i++)
		{
				bcolor=(color[bcolor]<color[i])?i:bcolor;
		}
	for (int i=1;i<=2;i++)
	{
		for (int d=1;d<=2;d++)
		{
			cou=(table[i][d]==(bcolor+1)) ? cou+1 : cou+0;
			cou=(table[i][d]==(bcolor-1)) ? cou+1 : cou+0;
			cou=(table[i][d]==(bcolor+2)) ? cou+2 : cou+0;
			cou=(table[i][d]==(bcolor-2)) ? cou+2 : cou+0;
			cou=(table[i][d]==(bcolor+3)) ? cou+1 : cou+0;
			cou=(table[i][d]==(bcolor-3)) ? cou+1 : cou+0;
		}
	}
	cout << cou << endl;
}
