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

unsigned long long answer;

int main()
{
    for (long long i=1;i<=1000*1000;i++)
    {
        answer=((answer + i*(((i+2)*(i+1))/2))%(1000 * 1000 * 1000));
        answer=(answer%(1000 * 1000 * 1000));
        //cout << answer << endl;
        //system("pause");
    }
    //answer=answer%(10000*10000*10);
    cout << (long long)answer%32057<< endl;
}
