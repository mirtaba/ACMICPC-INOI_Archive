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

char input[101];

int main()
{
    gets(input);
    if(input[5])
    cout << "bale" << endl;
    for(int i=0;input[i];i++)
    {
        if(!strchr("AOYEUIaoyeui",input[i]))
            cout << "." << char(tolower(input[i])) ;
    }
    cout << endl;
}
