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
const int Mod = 300017;

//ofstream fout ("greetings.out");
ifstream fin ("rect.txt");

#define cin fin
//#define cout fout

PII maxx[Maxn],minn[Maxn];
int N=10000,cnt[4][Maxn],tmp,Ans;
bool flag1,flag2,flag3,flag4;

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,0,N)
	{
	    cin.ignore(256,'(');
	    cin >> maxx[i].X ;
	    cin.ignore(256,',');
	    cin >> maxx[i].Y ;
	    cin.ignore(256,'(');
	    cin >> minn[i].X ;
	    cin.ignore(256,',');
	    cin >> minn[i].Y ;
	    //cerr << maxx[i].X << ' ' << maxx[i].Y  << ' ' << minn[i].X << ' ' << minn[i].Y << endl;
	}
	//cerr << maxx[0].X << ' ' << maxx[0].Y  << ' ' << minn[0].X << ' ' << minn[0].Y << endl;
	FOR(i,0,N)
	{
	    FOR(j,0,N)
	    {
	        flag1=false;
	        flag2=false;
	        flag3=false;
	        flag4=false;
	        tmp=0;
	        if ( (maxx[i].X>maxx[j].X && maxx[j].X>minn[i].X) && (maxx[i].Y>maxx[j].Y && maxx[j].Y>minn[i].Y) )
            {
                tmp++;
                flag1=true;
                //cerr << "1 " << i << ' ' << j << endl;
            }
            if ( (maxx[i].X>maxx[j].X && maxx[j].X>minn[i].X) && (maxx[i].Y>minn[j].Y && minn[j].Y>minn[i].Y) )
            {
                tmp++;
                flag2=true;
                //cerr << "2 " << i << ' ' << j << endl;
            }
            if ( (maxx[i].X>minn[j].X && minn[j].X>minn[i].X) && (maxx[i].Y>maxx[j].Y && maxx[j].Y>minn[i].Y) )
            {
                tmp++;
                flag3=true;
                //cerr << "3 " << i << ' ' << j << endl;
            }
            if ( (maxx[i].X>minn[j].X && minn[j].X>minn[i].X) && (maxx[i].Y>minn[j].Y && minn[j].Y>minn[i].Y) )
            {
                tmp++;
                flag4=true;
                //cerr << "4 " << i << ' ' << j << endl;
            }
            if(tmp==1)
            {
                if(flag1)
                {
                    cnt[0][i]++;
                    cnt[0][i]=(cnt[0][i]%Mod);
                    //cerr << "1" << endl;
                }
                if(flag2)
                {
                    cnt[1][i]++;
                    cnt[1][i]=(cnt[1][i]%Mod);
                   //cerr << "2" << endl;
                }
                if(flag3)
                {
                    cnt[2][i]++;
                    cnt[2][i]=(cnt[2][i]%Mod);
                    //cerr << "3" << endl;
                }
                if(flag4)
                {
                    cnt[3][i]++;
                    cnt[3][i]=(cnt[3][i]%Mod);
                    //cerr << "4" << endl;
                }
            }
	    }
	}
	//cerr << cnt[0][0] << ' ' << cnt[1][0] << ' ' << cnt[2][0] << ' ' << cnt[3][0] << endl;
	FOR(i,0,N)
	{
	    tmp=1;
	    tmp*=cnt[0][i];
	    tmp=(tmp%Mod);
	    tmp*=cnt[1][i];
	    tmp=(tmp%Mod);
	    tmp*=cnt[2][i];
	    tmp=(tmp%Mod);
	    tmp*=cnt[3][i];
	    tmp=(tmp%Mod);
	    Ans+=tmp;
	    Ans=(Ans%Mod);
	}
	cout << Ans << endl;

}
