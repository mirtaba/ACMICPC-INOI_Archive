/*
ID: ghoolha1
PROG: checker
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
#define LL long long

#define For(i, a, b) for ( int i = (a); i < (b); i++ )
#define Fors(i, sz) for ( size_t i = 0; i < sz.size (); i++ )
#define Set(a, s) memset (a, s, sizeof (a))

using namespace std;

int n;
bool col_avail [13 + 3];
bool right_diag [30];
bool left_diag [30];
int col_pos [13 + 3];
int print;
int cnt;

void printArray ()
{
    printf ("%d", col_pos [0] + 1);

    for ( int i = 1; i < n; i++ )
        printf (" %d", col_pos [i] + 1);
    printf ("\n");

    print++;
}

void bktk (int at_row)
{
    if ( at_row == n ) {
        if ( print < 3 )
            printArray ();
        cnt++; return;
    }

    for ( int i = 0; i < n; i++ ) {
        if ( col_avail [i] && right_diag [i - at_row + 13] && left_diag [i + at_row]) {
            col_avail [i] = right_diag [i - at_row + 13] = left_diag [i + at_row] = false;
            col_pos [at_row] = i;
            bktk (at_row + 1);
            col_avail [i] = right_diag [i - at_row + 13] = left_diag [i + at_row] = true;
        }
    }
}

int main(int argc, char** argv)
{
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);

    scanf ("%d", &n);
    print = cnt = 0;

    Set (col_avail, true);
    Set (right_diag, true);
    Set (left_diag, true);

    bktk (0);

    printf ("%d\n", cnt);


    return 0;
}
