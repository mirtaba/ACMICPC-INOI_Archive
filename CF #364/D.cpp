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
const double ep = 1e-7;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout


int n , k;
double l , v1 ,v2;

bool valid(int m)
{

}


int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> l >> v1 >> v2 >> k;
	double i = l/v2;
	double j = l/v1;
	if(i>=j){
        cout << i << endl;
        return 0;
	}

	//cerr << valid(5) << endl;
	/**/
	while((j-i)>ep)
	{
	    double m = (i+j)/2;
	    //cerr << m << ' ' << valid(m) << endl;
	    if(valid(m))
        {
            j = m;
        }
        else
        {
            i = m;
        }
	}
	if(valid(i))
        cout << i << endl;
    else
        cout << j << endl;
    /**/


}
