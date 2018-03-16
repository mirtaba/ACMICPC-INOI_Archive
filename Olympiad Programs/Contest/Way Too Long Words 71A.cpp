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

int main()
{
	cin >> n;
	while(n--)
	{
		string s;
		cin >> s;
		if(s.length()<=10)
            cout << s << endl;
		else
		{
			cout<<s[0]<<s.length()-2<<s[s.length()-1]<<endl;
		}
	}
}
