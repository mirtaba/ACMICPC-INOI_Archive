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
bool mark[501];
int sol[501],n,a[501];
int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int x = a[i];
        int k = 1;
        if(x == 0)
        {
            for(int j=1;j<=n;j++)
            {
                if(mark[j] == false)
                {
                    k = j;
                    break;
                }
            }
        }
        else
        {
            while(x!=0)
            {
                if(mark[k] == false)
                {
                    x--;
                }
                k++;

                //cout << k << endl;
            }
            while(mark[k] == 1)
                k++;
        }
        mark[k] = true;
        sol[k] = i;
    }
    for(int i=1;i<=n;i++)
    {
        cout << sol[i];
        if(i != n)
            cout << ',';
    }
    cout << endl;

}

