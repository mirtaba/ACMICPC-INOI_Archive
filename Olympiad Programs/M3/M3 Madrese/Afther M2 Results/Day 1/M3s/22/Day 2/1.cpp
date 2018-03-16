#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define pf push_front
#define FOR(i,s,f) for (int i=s;i<f;i++)

typedef long long LL ;
typedef  pair <int ,int > PII;
typedef  pair <LL , LL >  PLL;

const int Maxn = 1000 +25;
const int Mod  = 1000*1000*1000 +9;
const int Del = 11117;


int main()
{
    ios::sync_with_stdio(0);
    cout << (1<<26) << endl;
    int M=(1<<26);
    M%=Del;
    M*=M;
    M%=Del;
    M*=3;
    M%=Del;
    cout << M << endl;
}
