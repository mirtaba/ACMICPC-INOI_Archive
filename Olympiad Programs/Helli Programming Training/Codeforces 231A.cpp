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

//typedef pair <int, int> PII;

#define X first
#define Y second
#define LL long long

using namespace std;

long long n,tmp1,tmp2,tmp3,tmp;
int cnt;

int main()
{
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        tmp=tmp1+tmp2+tmp3;
        if(tmp>1)
            cnt++;
    }
    cout << cnt << endl;
}
