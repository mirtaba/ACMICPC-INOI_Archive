#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define X first
#define Y second
#define FOR(i,s,f) for(int i=s;i<f;i++)

const int Maxn = 10 + 125;
const int Mod = 10000 + 7;
const int Del =  12101;
const int m=3;
const int n=50;

typedef long long LL;
typedef pair <int ,int> PII;

LL dr[Maxn],db[Maxn];

int main()
{
    ios::sync_with_stdio(0);
    FOR(i,0,m)
    {
        db[i]=1;
    }
    db[m]=1;
    dr[m]=1;
    FOR(i,m+1,n+1)
    {
        db[i]=(db[i-1]+dr[i-1]);
        FOR(j,m,i+1)
        {
            dr[i]+=db[i-j];
        }
    }
    cout << db[n]+dr[n] << endl;

}
