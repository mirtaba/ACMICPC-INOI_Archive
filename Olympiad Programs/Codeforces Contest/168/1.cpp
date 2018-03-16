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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

int in[3][3],out[3][3];

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,0,3)
	{
	    FOR(j,0,3)
	    {
	        cin >> in[i][j];
	        in[i][j]=(in[i][j]%2);
	    }
	}
    out[0][0]=(in[0][0]+in[0][1]+in[1][0]+1)%2;
    out[0][1]=(in[0][0]+in[0][1]+in[1][1]+in[0][2]+1)%2;
    out[0][2]=(in[0][1]+in[0][2]+in[1][2]+1)%2;
    out[1][0]=(in[0][0]+in[1][1]+in[1][0]+in[2][0]+1)%2;
    out[1][1]=(in[0][1]+in[1][0]+in[1][2]+in[2][1]+in[1][1]+1)%2;
    out[1][2]=(in[1][1]+in[1][2]+in[0][2]+in[2][2]+1)%2;
    out[2][0]=(in[2][0]+in[1][0]+in[2][1]+1)%2;
    out[2][1]=(in[2][0]+in[2][1]+in[2][2]+in[1][1]+1)%2;
    out[2][2]=(in[2][2]+in[2][1]+in[1][2]+1)%2;
    FOR(i,0,3)
	{
	    FOR(j,0,3)
	    {
	        cout << out [i][j];
	    }
	    cout << endl;
	}



}
