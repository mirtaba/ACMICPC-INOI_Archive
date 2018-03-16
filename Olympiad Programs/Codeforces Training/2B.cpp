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

unsigned int input[Maxn][Maxn] , ouput[Maxn][Maxn];

int update(unsigned int a,unsigned int b)
{
    return (((input[a][b-1]*(input[a][b]))%10) > ((input[a-1][b]* input[a][b])%10)) ? ((input[a-1][b])*(input[a][b])) : ((input[a][b-1])*(input[a][b])) ;
}

int main()
{

}
