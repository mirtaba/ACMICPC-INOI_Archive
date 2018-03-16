/*
ID: ghoolha1
PROG: palsquare
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

ofstream fout ("palsquare.out");
ifstream fin ("palsquare.in");

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
    int b;
    cin >> b;
    for( int i = 1; i <= 300; i++ )
	{
		inbase(b,i*i);
		if( compare() )
		{
			inbase(b,i);
			int t = MAXB - 1;
			while( !changed[t] )
				{
				    t--;
				}
			for( int j = t; j >= 0; j-- )
				{
				    cout << changed[j];
				}
			cout << ' ';
			inbase(b,i*i);
			t = MAXB - 1;
			while( !changed[t] )
				{
				    t--;
				}
			for( int j = t; j >= 0; j-- )
				{
				    cout << changed[j];
				}
			cout << endl;
		}
	}
}
