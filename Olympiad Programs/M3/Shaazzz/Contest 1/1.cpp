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

const int Maxn = 100*1000 + 25;
const int Mod = 33083;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

deque <short> a;
bool flag;
int Ans;

void add()
{
    int N=(a.size()-1);
    if(a[N]==0)
    {
        a[N]=1;
        if(a.size()>=2)
        {
            while(a[N]==a[N-1] && N>=2)
            {
                a[N-2]=1;
                a[N-1]=0;
                a[N]=0;
                N-=2;
            }
            if( a[0]==1 && a[0]==a[1] )
            {
                a.push_front(1);
                a[1]=0;
                a[2]=0;
            }
        }
    }
    else
    {
        if(a.size()==1)
        {
            a.push_front(1);
            a[1]=0;
        }
        else
        {
            a[N]=0;
            a[N-1]=1;
            N--;
            while(a[N]==a[N-1] && N>=2)
            {
                a[N-2]=1;
                a[N-1]=0;
                a[N]=0;
                N-=2;
            }
            if( a[0]==1 && a[0]==a[1] )
            {
                a.push_front(1);
                a[1]=0;
                a[2]=0;
            }
        }

    }
}


int main()
{
	ios::sync_with_stdio(0);
	a.pb(0);
    FOR(i,0,100001)
    {
        //cerr << i << " :";
        FOR(i,0,a.size())
        {
            //cerr << a[i];
            if (a[i]==1)
                (++Ans) %= Mod;
        }
        //cerr << " & So far Ans is: ";
        //cerr << Ans << endl;
        //system("pause");
        add();
    }
    cout << Ans << endl;
}
