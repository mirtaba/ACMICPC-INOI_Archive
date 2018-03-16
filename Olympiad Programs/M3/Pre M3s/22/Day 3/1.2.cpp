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

int gcd (int a ,int b)
{
    return b ? gcd(b,a%b) : a ;
}

int a[(1<<120)];
long long Ans,d[Del+20],tmp;

int main()
{
    ios::sync_with_stdio(0);
    FOR(i,1,Del)
    {
        for(int j=i;j<Del;j+=i)
        {
            d[j]++;
        }
    }
    FOR(i,1,20)
    {
        cerr << d[i] << ' ' ;
    }
    cerr << endl;
    FOR(i,1,Del)
    {
        FOR(j,1,Del)
        {
            if(d[gcd(i,j)]==48)
            {
                Ans++;
            }
        }
    }
    cerr << Ans << endl;
    tmp=Ans;
    FOR(i,0,tmp)
    {
        Ans*=tmp;
        Ans%=Del;
    }
    cout << Ans << endl;

}
