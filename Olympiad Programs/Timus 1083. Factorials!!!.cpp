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

string str;
long long num,result;
int main()
{
	cin >> num >> str ;

	result=num;
	while(num-str.length()>0)
	{
	    num=(num-str.length());
	    result*=num;
	}
	cout << result << endl;

}
