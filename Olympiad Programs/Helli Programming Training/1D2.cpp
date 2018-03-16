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

using namespace std;

unsigned long long N,answer;
int main()
{
    cin >> N;
    if (N==9)
    cout << 8 << endl;
    else
    if(N<9)
        cout << 0 << endl;
    else
    {
        cout << 72 ;
        for (long long i=1;i<=N-10;i++)
            cout << 0 ;
        cout << endl;
    }
}
