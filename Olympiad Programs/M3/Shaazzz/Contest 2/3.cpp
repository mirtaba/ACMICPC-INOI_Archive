#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
#include <set>

using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define X first
#define Y second
#define FOR(i,s,f) for(int i=s;i<f;i++)

typedef long long LL;
typedef pair <int,int> PII;

const int Maxn=1000*1000*1000;
const int Mod = 1000 *1000 *1000;
const int Del = 33083;

vector <int> gog;
set <int> Ans;
int tmp1,tmp2,tp,Rez;
LL tmp;

int main()
{
    ios::sync_with_stdio(0);
    gog.pb(4);
    gog.pb(7);
    FOR(i,0,8)
    {
        tmp2=gog.size();
        FOR(j,tmp1,tmp2)
        {
            gog.pb( ((gog[j]*10)+4) );
            gog.pb( ((gog[j]*10)+7) );
        }
        tmp1=tmp2;
    }
    cout << gog.size() << endl;
    cout << gog[gog.size()-1] << endl;
    FOR(i,0,gog.size())
    {
        FOR(j,i,gog.size())
        {
            tmp=(gog[i]+gog[j]);
            if(tmp<=(Maxn))
                Ans.insert(tmp);
        }
    }
    cerr << "Done!" << endl;
    cout << Ans.size()%Del << endl;
}
