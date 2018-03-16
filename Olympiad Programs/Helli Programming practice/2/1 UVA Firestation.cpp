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
#define in insert

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL, LL> PLL;

const int Maxn = 5*100 + 25;
const int test=100;
const int Mod = 1000 * 1000 * 1000 + 7;

LL dis[Maxn][Maxn],in[Maxn][Maxn],T,tmp1,tmp2,tmp,N,f,V,dissta[Maxn],maxe,u;
PLL best;
bool mark[Maxn];
string s,tmps;
stringstream ss;
vector <LL> st;
set <PLL> ff;

void dijestra(LL v)
{
    d[v][v]=0;
    ff.in(mp(d[v][v],v));
    while(ff.size())
    {
        u=ff.begin() -> Y;
        mark[v][u]=true;
        ff.erase(mp(d[v][u],u));
        FOR(i,0,N)
        {

        }

    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> T;
    while(T--)
    {
        MEM(in,0);
        MEM(dissta,0x1F);
        cin >> f >> N;
        FOR(i,0,f)
        {
            cin >> tmp;
            st.pb(tmp-1);
            mark[tmp-1]=true;
        }
        getline(cin,tmps);
        getline(cin,s);
        while(s!="")
        {
            ss << s;
            ss >> tmp1 >>  tmp2 >> tmp;
            in[tmp1-1][tmp2-1]=tmp;
            in[tmp2-1][tmp1-1]=tmp;
            getline(cin,s);
        }
        floyd();
        FOR(i,0,st.size())
        {
            FOR(j,0,N)
            {
                if (i!=j)
                {
                    dissta[j]= min(dissta[j],dis[j][st[i]]);
                    cerr << dissta[j] << endl;
                }
            }
        }
        FOR(i,0,N)
        {
            maxe=0;
            FOR(j,0,N)
            {
                cerr << maxe <<' '<< dis[i][j] << ' ' << dissta[j] << endl;
                if((dis[i][j]<dissta[j]) && (maxe<dis[i][j]))
                    maxe=dis[i][j];
                //cerr << maxe << endl;
            }
            if (maxe < best.X)
            {
                best.X=maxe;
                best.Y=i;
            }
        }
        cout << best.Y << endl;
    }
    return 0;
}
