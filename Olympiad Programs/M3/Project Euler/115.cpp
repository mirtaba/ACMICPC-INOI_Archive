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

const int Maxn = 1000*1000+ 125;
const int Mod = 1000*1000;
const int Del =  12101;
const int m=50;

typedef long long LL;
typedef pair <int ,int> PII;

LL dr[Maxn],db[Maxn],n,Ans;

int main()
{
    ios::sync_with_stdio(0);
    n=0;
    while(Ans <(Mod))
    {
        FOR(i,0,Maxn)
        {
            db[i]=0;
            dr[i]=0;
        }
        n++;
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
        Ans=(db[n]+dr[n]);
        cerr << Ans << endl;
        //system("pause");
    }
    cout << n << endl;

}
