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
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <cmath>

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

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

int N,M,in[Maxn][Maxn];
char tmp;
bool flag;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	in[0][0]=1;
	FOR(i,1,N+1)
	{
	    FOR(j,1,M+1)
	    {
	        cin >> tmp;
	        if (tmp == 'B')
	        {
	            in[i][j]=1;
	        }
	    }
	}
    FOR(i,1,N+1)
	{
	    FOR(j,1,M+1)
	    {
	        if (flag)
	        {
	            if (in[i][j]==0 &&  (in[i][j+1]==1 && j!=M) )
                {
                    cout << "NO" << endl;
                    return 0;
                }
                else
                {
                    if (in[i][j]==1)
                    {
                        in[i][M+1]=j;
                    }
                }
	        }
	        else
	        if (in[i][j])
	        {
	            flag=true;
	            in[i][0]=j;
	            in[i][M+1]=j;
	        }
	    }
	    flag=false;
	}
	flag=false;
	FOR(i,1,M+1)
	{
	    FOR(j,1,N+1)
	    {
	        if (flag)
	        {
	            if (in[j][i]==0 &&  (in[j+1][i]==1 && j!=N) )
                {
                    cout << "NO" << endl;
                    return 0;
                }
                else
                {
                    if (in[j][i]==1)
                    {
                        in[N+1][i]=j;
                    }
                }
	        }
	        else
            if (in[j][i]==1)
            {
                flag=true;
                in[0][i]=j;
                in[N+1][i]=j;
            }
	    }
	    flag=false;
	}

    FOR(i,0,N+2)
	{
	    FOR(j,0,M+2)
	    {
	        cerr << in[i][j] <<' ';
	    }
	    cerr << endl;
	}

	int tmp1=0,tmp2=0,tmp3=0,tmp4=0;
	FOR(i,1,N+1)
	{
        tmp1=in[0][i];
        tmp2=in[N+1][i];
	    FOR(j,1,M+1)
	    {
	        tmp3=in[j][0];
	        tmp4=in[j][M+1];
	        cerr << tmp1 << ' ' << tmp2 << ' ' << tmp3 << ' ' << tmp4 << endl;
	        if (in[j][i])
                continue;
	        if (in[tmp1][tmp3]==0 &&( ( in[tmp3][tmp1]==0 ) && (tmp1!=0 && tmp3!=0)))
	        {
	            cerr << tmp1 << ' ' << tmp3 << endl;
	            cout << "NO" << endl;
	            return 0;
	        }
            if (in[tmp1][tmp4]==0 && ( ( in[tmp4][tmp1]==0 ) && (tmp1!=0 && tmp4!=0)))
	        {
	            cerr << tmp1 << ' ' << tmp4 << endl;
	            cout << "NO" << endl;
	            return 0;
	        }
            if (in[tmp2][tmp3]==0 &&( ( in[tmp3][tmp2]==0 ) && (tmp2!=0 && tmp3!=0)))
	        {
	            cerr << tmp2 << ' ' << tmp3 << endl;
	            cout << "NO" << endl;
	            return 0;
	        }
            if (in[tmp2][tmp4]==0 &&( ( in[tmp4][tmp2]==0 ) && (tmp2!=0 && tmp4!=0)))
	        {
	            cerr << tmp2 << ' ' << tmp4 << endl;
	            cout << "NO" << endl;
	            return 0;
	        }
	    }
	}
	cout << "YES" << endl;
	return 0;
}
