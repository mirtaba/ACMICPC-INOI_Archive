/*
ID: One O'Clock
PROG: circular prime
LANG: C++
*/

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

map <PII,int> poll;
vector <int> Graph[Maxn] , order;

LL n , m , a , b , c ,d;

int main()
{
	ios::sync_with_stdio(0);
    cin >> n >> m;

    int al = 1;

    FOR(i,1,n+1)
    {
        FOR(j,1,n+1)
        {
            if(i!=j)
            {
                poll[mp(i,j)] = al++;
            }
        }
    }

    FOR(i,1,al)
    {
        order.pb(i);
    }

    FOR(i,0,m)
    {
        cin >> a >> b >> c >> d;
        int t1 =  poll[mp(a,b)];
        int t2 =  poll[mp(c,d)];
        Graph[t1].pb(t2);
        Graph[t2].pb(t1);
    }
    /**
    int ans = abMax;
    do
    {
        vector <int> label (Maxn , 0);

        int localAns = 1;

        label[order[0]] = 1;
        FOR(i,1,order.size())
        {
            int u = order[i];
            //cerr << u << endl;
            int maxi = 0;
            vector <bool> mark (Maxn , 0);
            FOR(j,0,Graph[u].size())
            {
                mark[label[Graph[u][j]]] = 1;
                maxi = max (maxi , (label[Graph[u][j]]==abMax) ? (0) : (label[Graph[u][j]]) );
            }
            //cerr << u << endl;
            FOR(j,1,maxi+2)
            {
                if(!mark[j])
                {
                    label[u] = j;
                    localAns = max(localAns,j);
                    break;
                }
            }

        }

        ans = min(ans,localAns);

    }
    while( next_permutation(order.begin(),order.end()) );
    /**/

    if( n == 1)
        cout << 1 << endl;
    else
        cout << 2 << endl;

}

