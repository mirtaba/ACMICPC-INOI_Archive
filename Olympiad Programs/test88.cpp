/*
ID: ghoolha1
PROG: ariprog
LANG: C++
*/
// @BEGIN_OF_SOURCE_CODE
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

bool biSquare [4 * (251 * 251)];
int q_val [4 * (251 * 251)];

struct output {
	int start;
	int differnce;
} o [10000 + 5];

int in = 0;

bool cmp (output a, output b)
{
	if ( a.differnce < b.differnce ) return true;
	if ( a.differnce == b.differnce && a.start < b.start ) return true;
	return false;
}

int main(int argc, char **argv) {
	freopen ("ariprog.in", "r", stdin);
	freopen ("ariprog.out", "w", stdout);

	memset (biSquare, false, sizeof (biSquare));
	for ( int i = 0; i < 4 * (251 * 251); i++ )
		q_val [i] = N;
	// generate all biSquare
	for ( int p = 0; p <= 250; p++ ) {
		for ( int q = p; q <= 250; q++ ) {
			biSquare [p * p + q * q] = true;
			if ( q_val [p * p + q * q] > q ) q_val [p * p + q * q] = q;
		}
	}

	int n, m;
	scanf ("%d %d", &n, &m);

	int limit = 2 * m * m;

	for ( int a = 0; a <= limit; a++ ) {
		if ( !biSquare [a] ) continue;
		for ( int diff = 1; a + diff * (n - 1) <= limit; diff++  ) {
			int next = a + diff;
			int len = 1;
			while ( biSquare [next] && len < n && q_val [next] <= m ) {
				len++;
				next += diff;
			}
			if ( len == n ) {
				o [in].start = a;
				o [in].differnce = diff;
				in++;
			}
		}
	}

	sort (o, o + in, cmp);

	for ( int i = 0; i < in; i++ ) {
		printf ("%d %d\n", o [i].start, o [i].differnce);
	}

	if ( in == 0 ) printf ("NONE\n");

	return 0;
}

// @END_OF_SOURCE_CODE
