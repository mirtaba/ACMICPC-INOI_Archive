#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>
#include <numeric>
#include <utility>

using namespace std;

#define pb push_back
#define mp make_pair
#define FOR(i,s,f) for(int i=s;i<f;i++)

const int Mod = 33083;


int gcd (int a ,int b)
{
    return ( (b!=0) ? (gcd(b,a%b)) : a);
}

int Ans;

int main()
{
    ios::sync_with_stdio(0);
    FOR(i,1,101)
    {
        FOR(j,1,101)
        {
            if(gcd(i,j)==1)
            {
                Ans++;
            }
            Ans%=Mod;
        }
    }
    Ans*=Ans;
    Ans%=Mod;
    cout << Ans << endl;
}
