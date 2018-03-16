#include <bits/stdc++.h>

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MIN(a,b) (((a) < (b))? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define DFOR(i,a) for(int i=a;i>-1;i--)
#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second
#define Trace(X) cerr << #X << " = " << X << endl
#define _ << " _ " <<


using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <long double, long double> PDD;
typedef pair <LL,LL> PLL;

const int Maxn = 3*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int T,n;
PII in[Maxn];


int main()
{
	ios::sync_with_stdio(0);

	cin >> T;
	while(T--)
    {

        cin >> n;
        FOR(i,0,n)
        {
            cin >> in[i].X >> in[i].Y;
        }

        sort(in,in+n);


        PII lMax = in[n-1];
        PDD ans = {0.0,0.0};
        double AnsLength = 0;
        DFOR(i,n-2)
        {
            //cerr << lMax.X << ' ' << lMax.Y << endl;
            //cerr << in[i].X << ' ' << in[i].Y << endl;
            if(lMax.Y < in[i].Y)
            {
                //cerr << in[i].X << ' '<< in[i].Y << ' ' << in[i+1].X << ' '<< in[i+1].Y << endl;
                double m = ( (double) (in[i].Y - in[i+1].Y) / (double)(in[i].X - in[i+1].X) );
                //cerr << "M: " << m << endl;
                if(m == 0)
                    continue;
                else
                {
                    double x = ((lMax.Y- in[i].Y )/m) ;
                    //cerr << "X: " << x << ' ' << in[i].X << endl;
                    ans.X = abs(x);
                }
                ans.Y = abs(in[i].Y - lMax.Y);
                AnsLength += sqrt( (ans.X*ans.X) + (ans.Y * ans.Y) );
                lMax = in[i];
            }
        }
        //cerr << ans.X << ' ' << ans.Y << endl;


        cout << setprecision(2) << fixed << AnsLength << endl;

    }
}
