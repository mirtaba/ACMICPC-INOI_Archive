/*
ID: ghoolha1
PROG: namenum
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

ofstream fout ("namenum.out");
ifstream fin ("namenum.in");
ifstream dicin( "dict.txt" );

//#define cin fin
//#define cout fout

const int MAXN = 5 * 10*100 + 20;
long long intdic[MAXN];
string strdic[MAXN];

long long change( string s )
{
	long long sum = 0;
	for( int i = 0; i < s.length(); i++ )
        if( s[i] == 'A' || s[i] == 'B' || s[i] == 'C' )
			sum = sum * 10 + 2;
		else if( s[i] == 'D' || s[i] == 'E' || s[i] == 'F' )
			sum = sum * 10 + 3;
		else if( s[i] == 'G' || s[i] == 'H' || s[i] == 'I' )
			sum = sum * 10 + 4;
		else if( s[i] == 'J' || s[i] == 'K' || s[i] == 'L' )
			sum = sum * 10 + 5;
		else if( s[i] == 'M' || s[i] == 'N' || s[i] == 'O' )
			sum = sum * 10 + 6;
		else if( s[i] == 'P' || s[i] == 'R' || s[i] == 'S' )
			sum = sum * 10 + 7;
		else if( s[i] == 'T' || s[i] == 'U' || s[i] == 'V' )
			sum = sum * 10 + 8;
		else if( s[i] == 'W' || s[i] == 'X' || s[i] == 'Y' )
			sum = sum * 10 + 9;
	return sum;
}
int main()
{
        ifstream din ( "dict.txt" );
	for( int i = 0; !din.eof(); i++ )
	{
		din >> strdic[i];
		intdic[i] = change( strdic[i] );
	}
	long long n;
	fin >> n;
	bool b = true;
	for( int i = 0; intdic[i]; i++ )
		if( n == intdic[i] )
		{
			b = false;
			fout << strdic[i] << endl;
		}
	if( b )
		fout << "NONE" << endl;

}
