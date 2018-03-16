#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100*100*100 + 25;
string s;
char p[MAX];
int f=1,la=1;
struct node
{
	char ch;
	int r,l;
	node()
	{
		r = l = -1 ;
	}
	node(int i, int p)
	{
		r=i;
		l=p;
	}
} n[MAX];
int r=0,l=0;
int main()
{
	ios::sync_with_stdio (false);
	cin >> s;
	int wh=1;
	int kof=0;
	for (int i=0;i<(s.length());i++)
	{
		if (s[i]=='L'&& n[wh].l != -1)
			wh = (n[la].l);
		if (s[i]=='R'&& n[wh].r != -1)
			wh = (n[la].r);
		if (s[i] != 'L' && s[i] != 'R')
		{
			n[la].ch = s[i];
			if (n[kof].l!=-1)
			{
				n[n[kof].l].r=la;
				n[la].l=n[kof].l;
			}
			n[la].r=kof;
			n[kof].l=(la);
			la++;
		}
	}
	for (int i=0;i<=MAX-1;i++)
		p[i]=' ';
	//cout << char (n[1].ch);
	int tt=0;
	for (int i=0; i != -1;i = n[i].l)
		 p[tt]=(n[i].ch);
		 tt++;
	for (int i=0;i<=tt;i++)
		cout << p[i];
}
