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

bool mark[Maxn],flag;
int pr[Maxn],d[Maxn];
int tmp,tmp1,tmp2,tmp3,tp;

int main()
{
	ios::sync_with_stdio(0);
    FOR(i,1,Maxn)
	{
        for(int j=i;j<Maxn;j+=i)
        {
            pr[j]++;
        }
	}
	cerr << "primes found" << endl;
	FOR(i,0,Maxn)
	{
	    //cerr << "Just got started for: " << i;
	    {
            tmp=0;
            tp=i;
            flag=false;
            tmp3=0;
            while(tp>0)
            {
                if (tp%10==4)
                {
                    mark[tmp]=true;
                    //cerr << " 4 found";
                    break;
                }
                if (tp%10==9)
                {
                    flag=true;
                }
                if (tp%10==5)
                {
                    tmp3++;
                    if(tmp3>1)
                    {
                        mark[tmp]=true;
                        break;
                    }
                }
                tmp+=tp%10;
                tp/=10;
            }

            if( (21<tmp || tmp<=9) || !flag)
            {
                mark[i]=true;
            }
            //cerr << " Num Sum done";
        }
        {
            tmp1=0;
            tmp2=i;
            while(tmp2>0)
            {
                tmp1+=tmp2%2;
                tmp2/=2;
            }
            if(!(4<tmp1 && tmp1<=6))
            {
                mark[i]=true;
            }
            //cerr << " Bit counting done";
        }
        if(pr[i]<=4)
        {
            mark[i]=true;
        }
        //cerr << " Divisors count";
        if((i%2013)<=1000 || (i%2013)>1518)
        {
            mark[i]=true;
        }
        //cerr << " Mod done";
	}
	FOR(i,0,Maxn)
	{
	    if(!mark[i])
        {
            tmp=0;
            tp=i;
            while(tp>0)
            {
                tmp+=tp%10;
                tp/=10;
            }
            d[tmp]++;
            cout << i << ' ' << i%2013 << endl;
        }
	}
	cout << endl;
	FOR(i,0,46)
	{
        cout << i << ' ' << d[i] << endl;
    }

}
