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

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL adjx[4]={0,1,0,-1};
LL adjy[4]={1,0,-1,0};

bool mark[Maxn][Maxn],in[Maxn][Maxn];
PLL match[Maxn][Maxn],dmatch[Maxn][Maxn];
LL N,P,tmp,tmp2,xx,yy;

vector  <PLL> H,V;

bool dfsm(PLL a)
{
    if (a.X == -1 && a.Y == -1) return true;
    if (mark[a.X][a.Y] == true)
        return false;
    mark[a.X][a.Y]=true;
    FOR (i,0,4)
    {
        if((a.Y+adjy[i]>0 && a.Y+adjy[i]<=N) && (a.X+adjx[i]>0 && a.X+adjx[i]<N+1))
        {
            xx=a.X+adjx[i];
            yy=a.Y+adjy[i];
            if (!in[xx][yy])
            {
                if(dfsm(dmatch[xx][yy]))
                {
                    dmatch[xx][yy].X=a.X;
                    dmatch[xx][yy].Y=a.Y;
                    match[a.X][a.Y].X = xx;
                    match[a.X][a.Y].Y = yy;
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    MEM(match,0xFF);
    MEM(dmatch,0xFF);
	ios::sync_with_stdio(0);
    cin >> N >> P;
    FOR(i,0,P)
    {
        cin >> tmp >> tmp2;
        in[tmp][tmp2]=true;
    }
    FOR(i,1,N+1)
    {
        FOR (j,1,N+1)
        {
            if ( ( !in[i][j] && (i+j)%2 ) )
            {
                MEM(mark,0);
                dfsm(mp(i,j));
            }
        }
    }
    FOR(i,1,N+1)
    {
        FOR (j,1,N+1)
        {
            if ( (!in[i][j]) )
            {
                if (match[i][j]==-1)
                {
                    tmp=dmatch[i][j].X;
                    tmp2=dmatch[i][j].Y;
                }
                else
                {
                    tmp=match[i][j].X;
                    tmp2=match[i][j].Y;
                }
                if (tmp2-j == 1)
                {
                    H.pb(mp(i,j));
                }
                else
                {
                    if ( == 1)
                    {
                        V.pb(mp(i,j));
                    }
                }
            }
        }
    }
    if (H.size()==0 && V.size()==0 )
    {
        cout << "No" << endl;
        return 0;
    }
    else
    {
        cout << "Yes" << endl;
        cout << H.size() << endl;
        FOR(i,0,H.size() )
        {
            cout << H[i].X << ' ' << H[i].Y << endl;;
        }
        cout << V.size() << endl;
        FOR(i,0,V.size())
        {
            cout << V[i].X << ' ' << V[i].Y << endl;
        }
    }
    return 0;
}
