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


int in[Maxn] , n;

bool valid(int m)
{
    set <int> s;
    vector <int> ss;
    FOR(i,0,n)
    {
        s.insert(in[i]);
    }
    if(s.size()>m)
        return false;
    while(s.size())
    {
        ss.pb(*s.begin());
        s.erase(s.begin());
    }
    sort(ss.begin(),ss.end());
    int mark[100];
    MEM(mark,0);
    FOR(i,0,m)
    {
        mark[in[i]]++;
    }

    FOR(i,m,n)
    {
        bool flag = true;
        FOR(j,0,ss.size())
        {
            if(!mark[ss[j]]){
                //cerr <<i << ':' << (char)(ss[j]+'A') << endl;
                flag = false;
            }
        }
        if(flag)
            return true;
        else
        {
            mark[in[i]]++;
            mark[in[i-m]]--;
        }
    }
    bool flag = true;
        FOR(j,0,ss.size())
        {
            if(!mark[ss[j]]){
                //cerr <<n << ':' << (char)(ss[j]+'A') << endl;
                flag = false;
            }
        }
        if(flag)
            return true;
        else
            return false;
}


int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	char tmp;
	FOR(i,0,n)
	{
        cin >> tmp;
        in[i] = tmp-'A';
	}
	int i = 1;
	int j = n;
	//cerr << valid(5) << endl;
	/**/
	while((j-i)>1)
	{
	    int m = (i+j)/2;
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
