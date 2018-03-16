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
pair<LL,LL> p2[Maxn];
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

        p2[i].first = v;
        p2[i].second = s;
    }
    for(int i=0;i<n;i++)
    {
        cin >> time1[i];
    }
    sort(p,p+m);
    sort(p2,p2+m);
    for(int i=0;i<n;i++)
    {
        int x = time1[i];
        int ans1 = p2[]
    }
}



