#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR(i,x,t) for(int i=t;i<x;i++)
#define pb push_back
#define mp make_pair

typedef PII pair<int,int>;
typedef LL long long;

const int Maxn = 1000+25;
const int Mod = 1234567;

int d[4][Maxn];

int main()
{
    ios::sync_with_stdio(0);
    d[0][0]=80;
    d[1][0]=20;
    d[2][0]=5;
    d[3][0]=25
    FOR(i,1,Maxn)
    {
        ( d[0][i] =(LL)(36 * (d[0][i-1]) ) ) %= Mod;
        ( d[0][i] =(LL)(90 * (d[1][i-1]) ) ) %= Mod;
        ( d[0][i] =(LL)(90 * (d[2][i-1]) ) ) %= Mod;

    }
}
