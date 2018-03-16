#include <bits/stdc++.h>

#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 500*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int t , n , k;
bool in[Maxn];

int main()
{
	ios::sync_with_stdio(0);
    cin >> t;
	while(t-- > 0)
    {
        memset(in,0,sizeof(in));
        cin >> n >> k;
        for(int i = 0 ; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            in[tmp] = true;
        }
        int ans = 0;
        while(in[ans]){
            ans++;
        }
        while(k > 0)
        {
            if(!in[ans])
            {
                in[ans] = true;
                ans++;
                k--;
            }
            else{
                ans++;
            }
        }
        while(in[ans]){
            ans++;
        }
        cout << ans << endl;
	}
}
