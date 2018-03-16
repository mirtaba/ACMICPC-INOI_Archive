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

const int maxN = 100*100*10 + 25;

int n, m, t1, s1[maxN], t2, s2[maxN];
pair<int, int> c1[maxN], c2[maxN];

bool cmp(pair<int, int> a, pair<int, int> b)
{
  return (a.first > b.first);
}

int main()
{
  cin >> n >> m;
  t1 = t2 = 0;
  for(int i = 0; i < n; ++ i)
  {
    int t, p;
    cin >> t >> p ;
    if(t == 1)
        c1[t1 ++] = make_pair(p, i + 1);
    else
        c2[t2 ++] = make_pair(p, i + 1);
  }
  sort(c1, c1 + t1, cmp);
  sort(c2, c2 + t2, cmp);
  s1[0] = s2[0] = 0;
  for(int i = 0; i < t1; ++ i)
    s1[i + 1] = (s1[i] + c1[i].first);
  for(int i = 0; i < t2; ++ i)
    s2[i + 1] = (s2[i] + c2[i].first);
  int ans = -1;
  int bst = -1;
  for(int i = 0; i <= t2; ++ i)
    if( (i * 2 <= m ) &&( s1[min(m - i * 2, t1)] + s2[i] > ans))
    {
      ans = s1[min(m - i * 2, t1)] + s2[i];
      bst = i;
    }
  cout << ans << endl;
  for(int i = 0; i < min(m - bst * 2, t1); ++ i)
    cout << c1[i].second  << endl;
  for(int i = 0; i < bst; ++ i)
    cout << c2[i].second  << endl;
  return 0;
}
