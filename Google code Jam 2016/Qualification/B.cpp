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

void flip(int i , int j , string &S)
{
    if(j<=i)
        return;
    FOR(tt, i , j+1)
    {
        if(S[tt] == '+')
            S[tt] = '-';
        else
            S[tt] = '+';
    }
}



int T , n;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin >> T;
	int ttt = 0;
	while(ttt!=T)
    {
        ttt++;
        cin >> s;
        bool ansed = 0;
        int ans = 0;
        int en = 0;
        for(int i = s.size()-1 ; i>0 ; i--)
        {
            if(s[i] == '+')
            {
                en = i;
                break;
            }
        }
        cerr << en << endl;
        system("pause");
        while(en > 1)
        {
            int t=0;
            while(s[t] == '+')
                t++;
            flip(0,t-1,s);
            ans++;
            reverse(s.begin(),s.end()-en);
            cerr << s << "    " << en << endl;
            flip(0,s.size()-(1 + en),s);
            ans++;
                for(int i = s.size() ; i>0 ; i--)
                {
                    if(s[i] == '+')
                    {
                        en = i;
                        break;
                    }
                }
            cerr << s << ' ' << en << endl;
        }
        if()
        cout << "Case #" << ttt << ": " << ans << endl;
    }

}
