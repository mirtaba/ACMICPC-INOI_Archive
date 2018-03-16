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

#define track(a) cerr << #a <<"  " <<a<<endl;

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 1000 * 1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

ofstream fout ("A.out");
//ifstream fin ("greetings.in");

#define cout fout
//#define cin fin

int T , n;


int main()
{
	ios::sync_with_stdio(0);
	cin >> T;
	int ttt = 0;
	while(ttt!=T)
    {
        ttt++;
        cin >> n;
        vector <bool> mark (10,0);
        bool ansed = 0;
        for(LL i = n ; i < (LL)(101*n) ; i+=n)
        {
            int j = i;
            while(j>0)
            {
                mark[j%10] = true;
                j/=10;
            }
            bool flag = 0;
            FOR(j,0,10)
            {
                if(!mark[j])
                    flag = 1;
            }
            if(!flag)
            {
                cout << "Case #" << ttt << ": " << i << endl;
                ansed = true;
                break;
            }
        }
        if(!ansed)
        {
            cout << "Case #" << ttt << ": INSOMNIA"  << endl;
        }
    }

}
