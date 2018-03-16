
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <utility>


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

using namespace std;

ofstream fout ("problem2.out");
ifstream fin ("problem2.in");

#define cin fin
#define cout fout

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 1000*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

string S[Maxn],s[Maxn];
LL T,tmp1,tmp2,tmp;
bool Mark[Maxn],flag,flag2;

int main()
{
	ios::sync_with_stdio(0);
	cin >> T;
    FOR(i,0,T)
    {
        flag2=false;
        cin >> S[i];
        tmp1=S[i].size();
        cin >> s[i];
        tmp2=s[i].size();
        if (tmp1==tmp2)
        {
            if (S[i]==s[i])
            {
                cout << "YES" << endl;
                break;
            }
            else
            {
                cout << "NO" << endl;
                break;
            }
        }
        else
        {
            S[i]+=S[i];
            FOR(t,0,(tmp1+tmp1-tmp2)+2)
            {
                MEM(Mark,0);
                tmp=t;
                flag=false;
                FOR(j,0,tmp2)
                {
                    //cerr << S[i][tmp] << ' ' << tmp << ' ' << s[i][j] << ' ' << j<< ' '<< flag<<  endl;
                    if (S[i][tmp]==s[i][j] && (!Mark[tmp%tmp1]) )
                    {
                        Mark[t%tmp1]=true;
                        tmp++;

                    }
                    else
                    {
                        flag=true;
                        break;
                    }
                }
                if (!flag)
                {
                    cout << "YES" << endl;
                    flag2=true;
                    break;
                }
            }
            reverse(S[i].begin(),S[i].end());
            FOR(t,0,(tmp1+tmp1-tmp2)+2)
            {
                MEM(Mark,0);
                tmp=t;
                flag=false;
                FOR(j,0,tmp2)
                {
                    //cerr << "Here we go reverse: "<< S[i][tmp] << ' ' << tmp << ' ' << s[i][j] << ' ' << j<< ' '<< flag<<  endl;
                    if (S[i][tmp]==s[i][j] && (!Mark[tmp%tmp1]) )
                    {
                        Mark[t%tmp1]=true;
                        tmp++;

                    }
                    else
                    {
                        flag=true;
                        break;
                    }
                }
                if (!flag)
                {
                    cout << "YES" << endl;
                    flag2=true;
                    break;
                }
            }
            if (!flag2)
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
