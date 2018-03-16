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

const int Maxn = 1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

vector <int> G[Maxn * 100];
string s[Maxn];
int mark[Maxn][Maxn];

int n,l;

bool IS(int i, int j)
{
    int cnt = 0;
    FOR(t,0,Maxn)
    {
        //cerr << cnt << endl;
        //cerr << mark[i][t] << ' ' << mark[j][t] << endl;
        if(mark[i][t] != mark[j][t])
        {
            if(abs(mark[i][t]-mark[j][t]) > 1)
                return false;
            cnt += abs(mark[i][t]-mark[j][t]);
        }
        //cerr << cnt << endl;
        if(cnt>2)
            return false;
    }
    //cerr << i << ' ' << j << ' ' << cnt << endl;
    if(cnt == 2)
        return true;
}



bool IS2(int i, int j)
{
    int cnt = 0;
    FOR(t,0,Maxn)
    {
        //cerr << cnt << endl;
        //cerr << mark[i][t] << ' ' << mark[j][t] << endl;
        if(mark[i][t] != mark[j][t])
        {
            if(abs(mark[i][t]-mark[j][t]) > 1)
                return false;
            cnt += abs(mark[i][t]-mark[j][t]);
        }
        //cerr << cnt << endl;
        if(cnt>2*l)
            return false;
    }
    cerr << i << ' ' << j << ' ' << cnt << endl;
    if(cnt == 2*l)
        return true;
}


int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> l;
    FOR(i,0,Maxn)
    {
        FOR(j,0,Maxn)
        {
            mark[i][j] = 0;
        }
    }
	FOR(i,0,n)
	{
	    cin >> s[i];
	    FOR(j,0,s[i].size())
	    {
	        mark[i][s[i][j]-'a']++;
	    }
	}

	//cerr << IS(0,8) << endl;
    /**/
	FOR(i,0,n)
	{
	    FOR(j,i+1,n)
	    {

	        if(IS(i,j))
            {
                //cerr << i << ' ' << j << endl;
                G[i].pb(j);
                G[j].pb(i);
            }
	    }
	}
    /**/
    int ansi = abMax;

    vector <string> ss;

    vector <int> ansp;
    FOR(t,0,n)
    {
        vector <int> mark (Maxn , 0);
        vector <int> par (Maxn , -1);
        queue <int> q;
        q.push(t);
        mark[t] = 0;
        while(q.size())
        {
            int u = q.front();
            q.pop();

            FOR(i,0,G[u].size())
            {
                int v = G[u][i];
                if(!mark[v])
                {
                    mark[v] = mark[u]+1;
                    q.push(v);
                    par[v] = u;
                }
                if(IS2(t,v))
                {
                    int pt = v;
                    while(pt!=-1)
                    {
                        ss.pb(s[pt]);
                        pt = par[pt];
                    }
                    cout << s[t] << ' ';
                    reverse(ss.begin(),ss.end());
                    FOR(tt,0,ss.size())
                    {
                        cout << ss[tt] << ' ';
                    }
                    cout << s[v] << endl;
                    cout << endl;

                    return 0;
                }
            }
        }

    }

}
