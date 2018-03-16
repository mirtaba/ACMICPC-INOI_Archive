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


string sname , sadj , sverb;
char  tmp[Maxn];

map <string , string> nametr , adjtr , verbtr;

int main()
{
	ios::sync_with_stdio(0);
	cin.getline(tmp, Maxn-1);
	string ss(tmp);

	bool flag = false;

    int i =0;
    while( i<ss.size() && (64<ss[i] && ss[i] <123) )
    {
        sname += ss[i];
        i++;
    }
    while(i<ss.size() && ss[i] == ' ' )
        i++;
    while(i<ss.size() && (64<ss[i] && ss[i] <123))
    {
        sverb += ss[i];
        i++;
    }
    while(i<ss.size() && ss[i] == ' ' )
        i++;
    while( i<ss.size() && (64<ss[i] && ss[i] <123) )
    {
        sadj += ss[i];
        i++;
    }

    if(ss[i] == '.' && ss.size() == i+1)
    {
        flag = true;
    }

    if(flag)
    {
        nametr["I"] = "Man";

        nametr["You"] = "Shoma";

        nametr["We"] = "Ma";

        nametr["They"] = "Anha";

        nametr["She"] = "Oo";

        nametr["He"] = "Oo";


        adjtr["stupid"] = "nadan";
        adjtr["excellent"] = "aali";
        adjtr["noob"] = "mobtadi";
        adjtr["geek"] = "khafan";
        adjtr["student"] = "daneshju";
        adjtr["professor"] = "ostad";

        verbtr["is"] = "ast";

        verbtr["am"] = "hastam";

        if(nametr.find(sname) == nametr.end())
        {
            cout << sname << ' ';
        }
        else
        {
            cout << nametr[sname] << ' ';
        }
        if(adjtr.find(tolower(sadj) ) == adjtr.end())
        {
            cout << sadj << ' ';
        }
        else
        {
            cout << adjtr[sadj] << ' ';
        }
        if(verbtr.find(sverb) == verbtr.end())
        {
            if(sverb == "are")
            {

            }
            else
                cout << sverb << ' ';
        }
        else
        {
            cout << verbtr[sverb] << ' ';
        }



    }
    else
    {
        cout << "Not Supported Yet!" << endl;
    }


}
















