/*
ID: One O'Clock
PROG: circular prime
LANG: C++
*/

#include <bits/stdc++.h>

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MIN(a,b) (((a) < (b))? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
#define FOR(i,a,b) for(LL i=a;i<b;i++)
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

const int Maxn = 1000 * 1000  + 2500;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

bool isPrime[Maxn];

string s;

vector <LL> ans , primeList;

int n;

int main()
{
	ios::sync_with_stdio(0);

	FOR(i,2,Maxn)
	{
	    isPrime[i] = 1;
	}
	FOR(i,2,Maxn)
	{
	    if(isPrime[i])
        {
            primeList.pb(i);
            for(LL j = 2*i ; j <Maxn ; j+=i)
            {
                isPrime[j] = 0;
            }
        }
	}


	FOR(i,2,Maxn * 2 )
	{
        if(i < Maxn)
        {
            if(!isPrime[i]) continue;
            stringstream a;
            a << i;
            string s = a.str();
            bool f = true;
            FOR(j,1,s.size()+1)
            {
                string ss = s.substr(0,j);
                int n = stoi(ss,nullptr);
                f = isPrime[n] ?  f : false;
                if(!f) break;
            }
            if(f)
            {
                ans.pb(i);
            }
        }
        else
        {
            stringstream a;
            a << i;
            string  s = a.str();
            bool f = true;
            FOR(j,1,s.size()+1)
            {
                string ss = s.substr(0,j);
                int n = stoi(ss,nullptr);
                if(n < Maxn)
                {
                    f = isPrime[n] ?  f : false;
                }
                else
                {
                    int t = 0;
                    while(primeList[t] < ((int)(sqrt(n)+2)) )
                    {
                        if(n%primeList[t] == 0)
                        {
                            f = false;
                            break;
                        }
                        t++;
                    }
                }
                if(!f) break;
            }
            if(f)
            {
                ans.pb(i);
            }
        }

	}

	cin >> n;
	cout << ans[n-1] << endl;


}

