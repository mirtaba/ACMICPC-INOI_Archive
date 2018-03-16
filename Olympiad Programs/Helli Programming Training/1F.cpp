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

long long ab=0,ba=0;
float a=0,b=0;

int main()
{
    cin >> a >> b;
    ab=pow(a,b);
    ba=pow(b,a);
    cout << ab-ba << endl;
}
