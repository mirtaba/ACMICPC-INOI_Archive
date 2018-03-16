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
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second

using namespace std;

ofstream fout ("problem3.out");
ifstream fin ("problem3.in");

#define cin fin
#define cout fout

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL mat[Maxn][Maxn],R,C,T,mark[Maxn][Maxn],ans;

int main()
{
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--)
    {
        MEM(mat,0);
        MEM(mark,0);
        cin >> R >> C;
        FOR(i,0,R)
        {
            FOR(j,0,C)
            {
                cin >> mat[i][j];
            }
        }
        //W -> E && E -> W
        LL maxe=0;
        FOR(i,0,R)
        {
            maxe=mat[i][0];
            FOR(j,0,C)
            {
                if (mat[i][j]>=maxe)
                {
                    mark[i][j]=true;
                    maxe=mat[i][j];
                }
            }
            maxe=mat[i][C-1];
            for(int j=C-1;j>=0;j--)
            {
                if(mat[i][j]>=maxe)
                {
                    mark[i][j]=true;
                    maxe=mat[i][j];
                }
            }

        }
        //N -> S && S -> N
        FOR(i,0,C)
        {
            maxe=mat[0][i];
            FOR(j,0,R)
            {
                if(mat[j][i]>=maxe)
                {
                    mark[j][i]=true;
                    maxe=mat[j][i];
                }
            }
            maxe=mat[R-1][i];
            for (int j=R-1;j>=0;j--)
            {
                if(mat[j][i]>=maxe)
                {
                    mark[j][i]=true;
                    maxe=mat[j][i];
                }
            }
        }
        ans=0;
        FOR(i,0,R)
        {
            FOR(j,0,C)
            {
                if (!mark[i][j]) ans++;
            }
        }
        cout << ans << endl;
    }
}
