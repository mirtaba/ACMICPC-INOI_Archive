/*
ID: ghoolha1
PROG: clocks
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;

int init_clock [9];
int check [9];

bool checkRes ()
{
	int in [9];
	int ch [9];

	for ( int i = 0; i < 9; i++ ) { in [i] = init_clock [i]; ch [i] = check [i]; }

	in [0] = ( in [0] + 3 * ch [0] + 3 * ch [1] + 3 * ch [3] ) % 12; // 124
	in [1] = ( in [1] + 3 * ch [0] + 3 * ch [1] + 3 * ch [2] + 3 * ch [4] ) % 12; // 1235
	in [2] = ( in [2] + 3 * ch [1] + 3 * ch [2] + 3 * ch [5] ) % 12; // 236
	in [3] = ( in [3] + 3 * ch [0] + 3 * ch [3] + 3 * ch [4] + 3 * ch [6] ) % 12; // 1457
	in [4] = ( in [4] + 3 * ch [0] + 3 * ch [2] + 3 * ch [4] + 3 * ch [6] + 3 * ch [8] ) % 12; // 13579
	in [5] = ( in [5] + 3 * ch [2] + 3 * ch [4] + 3 * ch [5] + 3 * ch [8] ) % 12; // 3569
	in [6] = ( in [6] + 3 * ch [3] + 3 * ch [6] + 3 * ch [7] ) % 12; // 478
	in [7] = ( in [7] + 3 * ch [4] + 3 * ch [6] + 3 * ch [7] + 3 * ch [8] ) % 12; // 5789
	in [8] = ( in [8] + 3 * ch [5] + 3 * ch [7] + 3 * ch [8] ) % 12; // 689

	for ( int i = 0; i < 9; i++ ) if ( in [i] != 0 ) return false;
	return true;
}

vector <int> v;

void saveIt ()
{
	int a [9];
	for ( int i = 0; i < 9; i++ ) a [i] = check [i];

	vector <int> tmp;
	tmp.clear ();

	for ( int i = 0; i < 9; i++ ) {
		while ( a [i] ) {
			tmp.push_back (i + 1);
			a [i]--;
		}
	}

	if ( tmp.size () < v.size () ) v = tmp;
}

int main ()
{
	freopen ("clocks.in", "r", stdin);
	freopen ("clocks.out", "w", stdout);

	for ( int i = 0; i < 100; i++ ) v.push_back (i);

	for ( int i = 0; i < 9; i++ ) scanf ("%d", &init_clock [i]);

	bool found;

	for ( int a = 0; a < 4; a++ ) {
		for ( int b = 0; b < 4; b++ ) {
			for ( int c = 0; c < 4; c++ ) {
				for ( int d = 0; d < 4; d++ ) {
					for ( int e = 0; e < 4; e++ ) {
						for ( int f = 0; f < 4; f++ ) {
							for ( int g = 0; g < 4; g++ ) {
								for ( int h = 0; h < 4; h++ ) {
									for ( int ii = 0; ii < 4; ii++ ) {
										check [0] = a;
										check [1] = b;
										check [2] = c;
										check [3] = d;
										check [4] = e;
										check [5] = f;
										check [6] = g;
										check [7] = h;
										check [8] = ii;
										found = checkRes ();
										if ( found ) { saveIt (); }
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf ("%d", v [0]);

	for ( int i = 1; i < v.size (); i++ ) printf (" %d", v [i]);

	printf ("\n");

	return 0;
}
