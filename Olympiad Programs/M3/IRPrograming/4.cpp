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
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int table[9][9];
int M,N;
LL Ans;
bool flag;

int did(int l,int x,int y)
{
    if(x==0 || x==8)
        flag=true;
    if(y==0 || x==8)
        flag=true;
    if(l>16)
        flag=true;
    if(!flag)
    {
        if(x==3 && y==3)
            Ans++;
        did(l+1,x-1,y);
        did(l+1,x+1,y);
        did(l+1,x,y-1);
        did(l+1,x,y+1);
    }
    flag=false;
}

int main()
{
	ios::sync_with_stdio(0);
	did(-1,4,4);
	cout << Ans << endl;
}
