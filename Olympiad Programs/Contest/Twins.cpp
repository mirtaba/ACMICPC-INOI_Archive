/*
ID: ghoolha1
PROG: greetings
LANG: C++
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
#include <cmath>
#include <fstream>

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

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 10*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int a[Maxn],n,t,tt,ans;

int main()
{
    cin >> n;
    FOR(i,0,n)
    {
        cin >> a[i];
        t+=a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    /**
    FOR(i,0,n)
    {
        cerr << a[i] << endl;;
    }
    /**/
    //cerr << t << endl;
    while((2*tt)<=(t))
    {
        tt+=a[ans++];
        //cerr << tt << endl;
        if (ans==n)
            break;
    }
    cout << ans << endl;

}
