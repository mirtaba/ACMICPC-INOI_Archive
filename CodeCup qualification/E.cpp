/*
ID: One O'Clock
PROG: Watering
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
typedef pair <long double , long long > PDI;

const int Maxn = 1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;

vector<int> Graph[Maxn];
long double weight[Maxn][Maxn];

pair<long double,long double> st[Maxn];



double Prim (int V)
{
    vector <double> d (Maxn, abMax);
    vector <bool> mark (Maxn , 0);
    double res = 0;
    set < pair<double ,int> > S;
    d[V]=0;
    S.insert(make_pair(d[V],V));
    while(S.size())
    {
        int u=S.begin() -> second;
        res += S.begin() -> first;
        mark[u]=true;
        S.erase(make_pair(d[u],u));
        for (int i=0;i<Graph[u].size();i++)
        {
            int x=Graph[u][i];
            //cerr << d[x] << ' ' <<  weight[u][x] << endl;
            if(d[x]>(weight[u][x]) && !mark[x])
            {
                S.erase(make_pair(d[x],x));
                d[x]=(weight[u][x]);
                S.insert(make_pair(d[x],x));
            }
        }
    }

    return res;

}



int main()
{
    int n;
    long double x,y;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> x >> y;
        st[i].first = x;
        st[i].second = y;
    }
    st[0].first = 0;
    st[0].second = 0;
    n++;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j != i)
            {
                Graph[i].push_back(j);
                double f1 = (st[i].first - st[j].first) * (st[i].first - st[j].first);
                double f2 = (st[i].second - st[j].second) * (st[i].second - st[j].second);
                double ww = (double) sqrt( (double)(f1 + f2) );
                weight[i][j] = (ww);
            }
        }
    }


    cout.precision(2);
    cout << fixed << Prim(0) << endl;

    return 0;
}

