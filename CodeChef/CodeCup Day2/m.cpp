/*
ID: ghoolha1
PROG: greetings
LANG: C++
*/
/*
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
#include <cmath>
#include <fstream>
*/

#include <bits/stdc++.h>

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MIN(a,b) (((a) < (b))? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second
#define Traxe(X) cerr << #X << " = " << X << endl
#define _ << " _ " <<


using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout
bool mark[Maxn];
int a[Maxn];
bool IS = 0;
int t,n,k;
bool cando(int n)
{
    while(n>0)
    {
        int r = n%10;
        if(r == 2 || r == 3 || r == 4 || r == 5 || r == 7)
        {
            IS = true;
            return false;
        }
        n/=10;
    }
    return true;
}
int change(int n)
{
    int nn = 0;
    while(n>0)
    {
        int r = n%10;
        nn = nn*10 + r;
        n/=10;
    }
    return nn;
}
bool same(int a[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i] == a[j])
                return true;
        }
    }
    return false;
}
int main()
{
	ios::sync_with_stdio(0);

	cin >> t ;
	while(t--)
    {
        IS = 0;
        cin >> k >> n;
        int b[Maxn];
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            cando(a[i]);
        }
        if(!IS)
        {
            if(!same(a))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            for(int i=0,k=0;i<n;i++,k++)
            {
                mark[k] = same(a);
                if(cando(a[i]))
                {
                    a[i] = change(a[i]);
                }
                mark[k+1] = same(a);
                k++;

            }
            bool flag = 1;
            for(int i=0;i<k;i++)
            {

                flag = flag && mark[i];
            }
            if(flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

    }

}


