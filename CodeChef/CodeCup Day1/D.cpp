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

const int Maxn = 1000 *1000 + 250 ;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

vector <int> G[Maxn];

int n , m , app[Maxn] ,apples , st, fn;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	FOR(i,0,n)
	{
	    cin >> app[i];
	    apples += app[i];
	    cin >> m;
	    int tmp;
	    FOR(j,0,m)
        {
            cin >> tmp;
            G[i].pb(tmp-1);
        }
	}
	cin >> st >> fn;
	st--;
	fn--;
	stack <int > q;
	q.push(st);

    vector <int> par (Maxn, -1);
    vector <bool> mark (Maxn, 0);


    mark[st] = 1;


    int ansi = abMax;
    while(q.size())
    {
        int u = q.top();
        q.pop();

        FOR(i,0,G[u].size())
        {
            int v = G[u][i];
            if(!mark[v])
            {
                mark[v] = 1;
                q.push(v);
                par[v] = u;
            }
            if(v == fn)
            {

                    int cntApple = 0 , cntAns = 0;
                    int pt = fn;
                    while(pt!=(-1))
                    {
                        cntAns++;
                        if(app[pt] == 0)
                            cntApple++;
                        pt = par[pt];
                    }
                    if(apples < cntAns)
                    {
                    }
                    else
                    {
                        //cerr << cntApple << endl;
                        ansi = min(ansi ,cntApple);
                    }

            }
        }
    }


    if(ansi == abMax)
    {
        cout << "No Solution" << endl;
    }
    else
    {
        cout << ansi << endl;
    }

}
