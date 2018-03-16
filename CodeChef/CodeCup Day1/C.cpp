/*
ID: ghoolha1
PROG: greetings
LANG: C++
*/
/*
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
#include <fstream>
*/

#include <bits/stdc++.h>

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
#define Traxe(X) cerr << #X << " = " << X << endl
#define _ << " _ " <<


using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout
string s;
bool f1=0,has=0;
int main()
{
	ios::sync_with_stdio(0);
	while(cin >> s)
    {
        f1 = 0;
        has=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '.')
                has=1;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                cout << "1ILLEGAL" << endl;
                f1 = 1;
                break;
            }
        }
        if(f1) continue;
        int k = 0;
        while(has && s[k] != '.')
        {
            k++;
        }
        if(!has && (k!=(s.size()-1))&&(s[k-1]>='0' && s[k-1]<='9') && (s[k+1]>='0' && s[k+1]<='9') ){}
        else
        {
            cout << "2ILLEGAL" << endl;
            f1 = 1;
            break;
        }
        if(f1) continue;
        k = 1;
        while((k<s.size()) && !(s[k] != '+' ^ s[k] != '-'))
            k++;
        if(s[k-1] == 'e' || s[k-1] == 'E'){}
        else
        {
            cout << "3ILLEGAL" << endl;
            f1 = 1;
            break;
        }
        if(f1) continue;
        for(int i=k+1;i<s.size();i++)
        {
            if(s[i] == '.')
            {
                cout << "4ILLEGAL" << endl;
                f1 = 1;
                break;
            }
        }
        if(f1) continue;
        cout << "LEGAL" << endl;
    }
}
