
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

const int Maxn = 1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 25 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

string st ;
vector <char> ans;
int last[Maxn];
int n;

int main()
{
    cin >> n;
    FOR(I,0,n)
    {
        cin >> st;
        MEM(last, 0x7F);
        ans.clear();
        int si = st.size();
        FOR(i,0,si)
        {
            if(last[st[i]] > abMax )
            {
                last[st[i]] = ans.size();
                ans.pb(st[i]);
            }
            else
            {
                if(last[st[i]] + 1 < ans.size())
                {
                    if(ans[last[st[i]] + 1] < st[i])
                    {
                        ans.erase(ans.begin() + last[st[i]]);
                        ans.pb(st[i]);
                    }
                }
            }

            FOR(i,0,ans.size())
            {
                cerr << ans[i];
            }
            cerr << endl;
        }
        FOR(i,0,ans.size())
        {
            cout << ans[i];
        }
        cout << endl;
    }
}
