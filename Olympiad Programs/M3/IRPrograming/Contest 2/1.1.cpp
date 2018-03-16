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

const int Maxn = 1000 * 1000 * 1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

vector <int> pr,tp;
bool mark[Maxn];
int tmp,tmp2;

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,2,Maxn)
	{
	    if(!mark[i])
        {
            //cerr << i << endl;
            tmp=i;
            tp.clear();
            tp.pb(tmp%10);
            tmp/=10;
            while(tmp>0)
            {
                if((*tp.end())!=tmp%10)
                    tp.pb(tmp%10);
                tmp/=10;
            }
            //cerr << i << endl;
            reverse(tp.begin(),tp.end());
            if(pr.size()>0)
                if(tp[0]==(*pr.end()))
                {
                    tmp=1;
                }
                else
                {
                    tmp=0;
                }
            FOR(j,tmp,tp.size())
            {
                pr.pb(tp[j]);
                if(tp[j]==7)
                {
                    tmp2++;
                }
            }
            if(tmp2>=777)
            {
                cout << i+1 << endl;
                break;
            }
            //cerr << i << endl;
            for(int j= ( 2 * i) ;j < Maxn ;j+=i)
            {
                mark[j]=true;
            }
            //cerr << i << endl;
        }
	}
	cerr << "Main Cal done" << endl;
	/**
	FOR(i,0,pr.size())
	{
	    while(pr[i]==pr[i+1])
        {
            pr.erase(pr.begin()+i);
        }
	}
	/**/
	cout << pr.size() << endl;
	cout << pr[0] << endl;
	FOR(t,0,pr.size())
	{
	    cout << pr[t];
	    //system("pause");
	}
}
