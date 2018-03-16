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

int n;
char a[5][10]={"Sheldon","Leonard","Penny","Rajesh","Howard"};

int main()
{
cin >> n ;
n--;
while(n>=5)
{
    n-=5;
    n/=2;
    }
cout << a[n] << endl;
return 0;
}
