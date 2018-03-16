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

const int Maxn = 1000 * 1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

bool isPrime[Maxn];

string s;

vector <int> ans;
pair<LL,LL> p[Maxn];
LL time1[Maxn];
LL maxi = -1;
int n;

int main()
{
	ios::sync_with_stdio(0);
    LL m,n;
    cin >> m >> n;
    for(int i=0;i<m;i++)
    {
        int s,v;
        cin >> s >> v;
        p[i].first = s;
        p[i].second = v;
    }
    for(int i=0;i<n;i++)
    {
        cin >> time1[i];
    }
    for(int i=0;i<n;i++)
    {
        maxi = -1;
        int x = time1[i];
        for(int j=0;j<m;j++)
        {
            if((x*p[j].second + p[j].first)>maxi)
                maxi = (x*p[j].second + p[j].first);
        }
        cout << maxi << ' ';
    }
}


