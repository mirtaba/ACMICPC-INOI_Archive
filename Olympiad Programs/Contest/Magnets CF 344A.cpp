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

using namespace std;

const int Maxn= 100*1000 + 250;
int in[Maxn];
int N,tmp,ans;

int main ()
{
    cin >> N;
    in[N]=5;
    while((N--)>0)
    {
        cin >> in[N];
        if (in[N]!=in[N+1])
            ans++;
        //cerr << N << ' ' << ans << endl;
    }
    cout << ans << endl;

}
