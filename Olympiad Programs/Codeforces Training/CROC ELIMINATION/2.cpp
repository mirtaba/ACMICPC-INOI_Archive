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

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MIN(a,b) (((a) < (b))? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

string s,s1,s2;
LL pos;

int main()
{
	ios::sync_with_stdio(0);
	cin >> s;
	if (s[0]=='f')
	{
	    pos=s.find("ru");
	    if (pos==3) pos =s.find("ru",pos+2);;
	    s1=s.substr(3,pos-3);
	    s2=s.substr(pos+2);
	    cout << "ftp://" << s1 << ".ru" ;
	    if (s2.size()>0)
            cout << "/" << s2 << endl;
	    else
            cout << endl;
	}
	if (s[0]=='h')
	{
        pos=s.find("ru");
        if (pos==4) pos =s.find("ru",pos+2);;
	    s1=s.substr(4,pos-4);
	    s2=s.substr(pos+2);
	    cout << "http://" << s1 << ".ru" ;
        if (s2.size()>0)
            cout << "/" << s2 << endl;
	    else
            cout << endl;
	}

}
