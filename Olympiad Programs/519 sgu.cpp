#include <iostream>
#include <cmath>
#include <cstdio>
#include<algorithm>

using namespace std;
const int MAXn = 100*10 +20;
int table [MAXn][MAXn];
int m,n,answer;
string s[MAXn];

int check (int i,int j)
{
	int r=0,l=0,f=0,b=0,u=0,d=0;
	r=(table[i][j]>table[i][j+1])?r+(table[i][j]-table[i][j+1]):r;
	l=(table[i][j]>table[i][j-1])?l+(table[i][j]-table[i][j-1]):l;
	f=(table[i][j]>table[i+1][j])?f+(table[i][j]-table[i+1][j]):f;
	b=(table[i][j]>table[i-1][j])?b+(table[i][j]-table[i-1][j]):b;
	u=(table[i][j]>0)?u+1:u;
	d=(table[i][j]>0)?d+1:d;
	return (r+l+f+b+u+d);
}
int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> s[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			 table[i][j]=(s[i][j - 1]-'0');
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			answer+= check(i,j);
		}
	}

	cout << answer;

}
