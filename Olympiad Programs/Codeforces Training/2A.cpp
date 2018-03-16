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

const int Maxn=100*10+25;

map<string,long long> input,input2;
map<string,long long> ::iterator iter;

string name[Maxn];
long long point [Maxn],n,m;

int main ()
{
        cin >> n;
        for (int i=0;i<n;i++)
        {
            cin >> name[i] >> point[i] ;
            input[name[i]]+= point[i];
        }
        for (iter=(input.begin());iter != (input.end());++iter)
        {
            m = max(m , iter -> second);
        }
        for (int i=0;i<n;i++)
        {
            input2[name[i]]+= point[i];
            if (input2[name[i]]>= m && input[name[i]]==m)
            {
                cout << name[i] << endl;
                break;
            }
        }
}
