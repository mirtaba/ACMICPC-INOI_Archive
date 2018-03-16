/*
ID: ghoolha1
PROG: proximity
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

const int Maxn = 1000*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;


ofstream fout ("proximity.out");
ifstream fin ("proximity.in");

#define cin fin
#define cout fout


long in[Maxn],N,K,ans,siz,A,E,M,tmp;
bool mark[Maxn];
pair <long ,long> chek[Maxn];

long find (long x)
{
    //cerr << x << endl;
    A=0;
    E=siz;
    while((E-A)>1)
    {
        //cerr << ' ' << M << endl;
        M=((E+A)/2);
        if (chek[M].X==x)
        {
            return chek[M].Y;
        }
        if (chek[M].X > x)
        {
            E=M;
        }
        else
        {
            A=M;
        }
    }
    //cerr << M << ' ' << chek[M].X << endl;
    return -1;
}

void inn(long x,int i)
{
    //cerr << x << ' ' <<  i << endl;
    siz++;
    chek[siz].X=x;
    chek[siz].Y=i;
    sort(chek,chek+siz);
}

void del(long x ,long i)
{
    //cerr << "del" << x << endl;
    A=0;
    E=siz;
    while((E-A)>1)
    {
        M=((E+A)/2);
        if (chek[M].X==x && chek[M].Y==i)
        {
            break;
        }
        if (chek[M].X > x)
        {
            E=M;
        }
        else
        {
            A=M;
        }
    }
    swap (chek[M],chek[siz]);
    siz--;
    sort(chek,chek+siz);
}
int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	FOR(i,0,N)
	{
	    cin >> in[i];
	}
	if (K==1)
	{
	    FOR(i,0,N-1)
	    {
	        if (in[i]==in[i+1])
	        {
	            mark[i]=true;
	            mark[i+1]=true;
	        }
	    }
	}
	else
	{
        FOR(i,0,N)
        {
            //cerr << i << endl;
            tmp=find(in[i]);
            //cerr <<in[i] << ' ' <<  chek[0].X << endl;
            //cerr << tmp << endl;
            if (tmp!=(-1))
            {
                mark[i]=true;
                mark[tmp]=true;
            }
            if (i>=K)
                del(in[i-K],i-K);
            inn(in[i],i);
        }
	}
	FOR(i,0,N)
	{
	    if (mark[i])
	    {
	        ans++;
	    }
	}
	cout << ans << endl;
}
