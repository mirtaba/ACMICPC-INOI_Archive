/*
ID:ghoolha1
PROG:subset
LANG:C++
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
#include <fstream>

using namespace std;

ofstream fout("subset.out");
ifstream fin("subset.in");

#define cin fin
#define cout fout

const int Maxsum = 40*40;
const int Maxn = 40;

int N,S,dp[Maxsum][Maxn];

int main()
{
    cin >> N;
    S=(N*(N+1));
    if (S % 4)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        S/=4;
        int i=0,j=0;
        dp[0][0]=1;
        for (i = 1; i < N; i++)
        {
            for (j = 0; j <= S; j++)
                dp[j][i] = dp[j][i-1];
            for (j = 0; j <= S-i; j++)
                dp[j+i][i] += dp[j][i-1];
        }
        cout << dp[S][N-1] << endl;
    }
}
