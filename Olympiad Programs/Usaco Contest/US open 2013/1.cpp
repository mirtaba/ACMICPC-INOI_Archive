/*
ID: ghoolha1
PROG: greetings
LANG: C++
*/
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

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

LL jav;
bool flag;
pair<int,int> FL,FR,RL,RR,tp,ansp,ansm,ans;
char in[3],ts[2];
//short hex[10000][10000];
int N;
pair <int,int> rot(pair <int,int> po,pair <int,int> piv)
{
    po.X-=piv.X;
    po.Y-=piv.Y;
    tp.X=po.Y+piv.X;
    tp.Y=(-po.X)+piv.Y;
    return tp;
}
void doo(pair<int,int> &x)
{
    if(in[2]=='F')
    {
        x.Y++;
    }
    else
    if(in[2]=='B')
    {
        x.Y--;
    }
    else
    if(in[2]=='L')
    {
        x.X--;
    }
    else
    {
        x.X++;
    }
}
void cal(pair <int,int> ino)
{
    if (ino.X>0)
    {
        ansp.X=max(ansp.X,ino.X);
    }
    else
    {
        ansm.X=min(ansp.X,ino.X);
    }
    if (ino.Y>0)
    {
        ansp.Y=max(ansp.Y,ino.Y);
    }
    else
    {
        ansm.Y=min(ansp.Y,ino.Y);
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
    FL.Y=1;
    FR.X=1;
    FR.Y=1;
    RR.X=1;
	FOR(i,0,N)
	{
	    cin >> in;
        if (in[2]=='P')
        {
            if (in[0]=='F' && in[1]=='L')
            {
                FR=rot(FR,FL);
                RL=rot(RL,FL);
                RR=rot(RR,FL);
            }
            else
            if (in[0]=='F' && in[1]=='R')
            {
                FL=rot(FL,FR);
                RL=rot(RL,FR);
                RR=rot(RR,FR);
            }
            else
            if (in[0]=='R' && in[1]=='L')
            {
                FR=rot(FR,RL);
                FL=rot(FL,RL);
                RR=rot(RR,RL);
            }
            else
            {
                FR=rot(FR,RR);
                RL=rot(RL,RR);
                FL=rot(FL,RR);
            }
            cerr << FL.X << ' ' << FL.Y << endl;
            cerr << FR.X << ' ' << FR.Y << endl;
            cerr << RL.X << ' ' << RL.Y << endl;
            cerr << RR.X << ' ' << RR.Y << endl;
        }
        else
        {
            if (in[0]=='F' && in[1]=='L')
            {
                doo(FL);
                if (FL==FR)
                    flag=true;
                if (FL==RL)
                    flag=true;
                if (FL==RR)
                    flag=true;
            }
            else
            if (in[0]=='F' && in[1]=='R')
            {
                doo(FR);
                if (FR==FL)
                    flag=true;
                if (FR==RL)
                    flag=true;
                if (FR==RR)
                    flag=true;
            }
            else
            if (in[0]=='R' && in[1]=='L')
            {
                doo(RL);
                if (RL==FR)
                    flag=true;
                if (RL==FL)
                    flag=true;
                if (RL==RR)
                    flag=true;
            }
            else
            {
                doo(RR);
                if (RR==FR)
                    flag=true;
                if (RR==FL)
                    flag=true;
                if (RR==RL)
                    flag=true;
            }
        }
        if (flag)
        {
            cout << -1 << endl;
            return 0;
        }
        cal(FL);
        cal(FR);
        cal(RL);
        cal(RR);
	}
	ans.X=(abs(ansm.X)+abs(ansp.X));
	ans.Y=(abs(ansm.Y)+abs(ansp.Y));
	jav=max(ans.X,ans.Y);
	cout << (LL)(jav*jav) << endl;
}

