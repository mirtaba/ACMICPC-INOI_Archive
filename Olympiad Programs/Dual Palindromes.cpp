/*
ID: ghoolha1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

ofstream fout ("dualpal.out");
ifstream fin ("dualpal.in");

#define cin fin
#define cout fout

const int MAXN=3*100;
const int MAXB=2*10;

char changed[MAXB];

void inbase(int b,int input)
{
    	for( int i = 0; i < MAXB; i++ )
            changed[i] = 0;
        for( int i = 0; input ; i++)
        {
            if( input%b < 10 )
                changed[i] = '0' + (input%b);
            else
                changed[i] = 'A' + (input%b) - 10;
            input /= b;
        }
}
bool compare ()
{
    int B = (MAXB - 1);
	while( !changed[B] )
		B--;
	for( int i = 0; i < (B + 1) / 2; i++ )
		if( changed[i] != changed[B - i] )
			return false;
	return true;
}
int main()
{
    int n=0,s=0;
    cin >> n >> s;
    for (int i=0;i<n;i++)
    {
        while(n==n)
        {
            s++;
            int p=0;
			for( int j = 2; j <= 10; j++ )
			{
				inbase(j,s);
				if(compare())
					p++;
				if(p==2)
					break;
            }
            if( p == 2 )
				break;
        }
        cout << s << endl;
    }
}
