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

#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second

using namespace std;

typedef long long LL;

typedef pair <int, int> PII;

const int maxn = 5000 +25;
const int mod = 1000 * 1000 * 1000 + 7;

vector <LL> V[maxn];
LL tmp,tmp1,tmp2,a,b;

int main()
{
    while(cin >> tmp >> tmp2)
    {
        V.clear();
        cin >> a;
        cin >> b;
        /*for(int i=0;i<tmp;i++)
        {
            V.push_back(i);

        }*/
        for(int i=0;i<tmp2;i++)
        {
            cin >> a >> b;
            V[a].push_back(b);
        }
    }
}
