#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100*100*100 + 25;
string s;
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
			wh = (n[wh].l);
		if (s[i]=='R'&& n[wh].r != -1)
			wh = (n[wh].r);
		else
			if (s[i] != 'L' && s[i] != 'R')
			{
				if (n[wh].l != -1)
					n[n[wh].l].r = la ;
				else
					{
					f = la ;
					n[la].l = n[wh].l ;
					n[la].r = wh ;
					n[wh].l = la ;
					n[la].ch = n[i].ch;
					la++;
					}
			//n[wh].ch=s[i];
		//	n[wh] = node(kof+1,kof+1);
			//wh++;
			//r=0;l=0;
			}
	}
	wh=f;
	//cout << char (n[1].ch);
	for (int i=1;i<(f);i++)
		cout << char (n[i].ch);
		wh = n[wh].r;
}
