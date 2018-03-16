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
#define FOR(a,b) for(int i=a;i<b;i++)
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

const int Maxn = 100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL a,b,N;
string S;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	while(N--)
	{
	    cin >> S;
	    cout << S.size() << ' ';
	    if (S.size()%2)
	    {
	        cout << S[(LL)(S.size()-1)/2] << endl;
	    }
	    else
	    {
	        cout << S[(LL)(S.size()-2)/2] << S[(LL)(S.size())/2] << endl;
	    }
	}
}
