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

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    cout << max(abs(s1[0]-s2[0]) , abs(s1[1]-s2[1])) << endl;
    while(s1!=s2)
    {
        if(s1[0]<s2[0]){cout<<"R";s1[0]++;}
        if(s1[0]>s2[0]){cout<<"L";s1[0]--;}
        if(s1[1]<s2[1]){cout<<"U";s1[1]++;}
        if(s1[1]>s2[1]){cout<<"D";s1[1]--;}
        cout<<endl;
    }
    return 0;
}
