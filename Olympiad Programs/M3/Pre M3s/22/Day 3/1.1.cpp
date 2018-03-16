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

long long Ans;

int main()
{
    ios::sync_with_stdio(0);
    FOR(i,1,Del)
    {
        FOR(j,1,Del)
        {
            if(gcd(i,j)==1)
            {
                Ans++;
            }
        }
    }
    cerr << Ans << endl;
    Ans*=Ans;
    Ans%=Del;
    cerr << Ans << endl;
    Ans*=Ans;
    Ans%=Del;
    cerr << Ans << endl;
    Ans*=Ans;
    Ans%=Del;
    cout << Ans << endl;

}
