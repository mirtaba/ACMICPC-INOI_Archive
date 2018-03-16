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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

LL n  , sum , mark[Maxn];
PII in[Maxn];
vector <PII> ans;
int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	MEM(mark,0);
	FOR(i,0,n)
	{
        cin >> in[i].X;
        in[i].Y = i;
        sum += in[i].X;
	}
	sum /= (n/2);
    sort(in,in+n);
    FOR(i,0,n)
    {
        if(!mark[i])
        {
            mark[i] = 1;
            for(int j = n-1 ; j >=0;j--)
            {
                if(!mark[j] && (in[i].X+in[j].X) == sum )
                {
                    mark[j] = 1;
                    ans.pb({in[i].Y+1,in[j].Y+1});
                    break;
                }
            }

        }

    }

    FOR(i,0,n/2)
    {
        cout << ans[i].X << ' ' << ans[i].Y << endl;
    }


}
