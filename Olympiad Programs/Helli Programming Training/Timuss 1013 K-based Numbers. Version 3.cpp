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

#define bigvar vector <int>

using namespace std;

const int Maxn=2*1E3+25;

unsigned long long N,K;

bigvar d[2][2],answer;

void coutt (bigvar ans)
{
	if (!ans.size())
		cout << 0;
	for (int i = ans.size() - 1 ; i >= 0 ; i--)
		cout << ans[i];
	cout << endl;
}
bigvar bbmultiply (bigvar a, int b , int c)
{
	bigvar ans;
	for (int i = 1 ; i <= c ; i++)
        ans.push_back(0);
	int carry = 0;
	for (int i = 0 ; i < a.size() ; i++)
	{
		ans.push_back((a[i] * b + carry) % 10);
		carry = (a[i] * b + carry) / 10;
	}
	while (carry)
	{
		ans.push_back (carry % 10);
		carry /= 10;
	}
	while (ans.size() && ans[ans.size() - 1] == 0)
		ans.pop_back ();
	return ans;
}

bigvar bplus(bigvar a , bigvar b)
{
	bigvar ans;
	a.resize(max(a.size() , b.size()) , 0);
	b.resize(max(a.size() , b.size()) , 0);
	int carry = 0;
	for (int i = 0 ; i < max (a.size() , b.size()) ; i++)
	{
		ans.push_back((a[i] + b[i] + carry) % 10);
		carry = (a[i] + b[i] + carry) / 10;
	}
	while (carry)
	{
		ans.push_back(carry % 10);
		carry /= 10;
	}
	while (ans.size() && ans[ans.size() - 1] == 0)
		ans.pop_back();
	return ans;
}
bigvar bmultiply(bigvar a , bigvar b)
{
    bigvar ans;
    for (int i = 0 ; i < a.size() ; i++)
        ans = bplus(ans , bbmultiply(b , a[i] , i));
    return ans;
}

bigvar numtobigvar(int input)
{
    bigvar ans;
    while(input > 0)
    {
        ans.push_back(input % 10);
        input /= 10;
    }
    return ans;
}

int main()
{
    cin >> N >> K;
    d[0][1]=numtobigvar(1);
    d[1][1]=numtobigvar(1);
    bool bb=false;
    for(int i=2;i<=N;i++)
    {
        bb=i%2;
        //cerr << " i were there" << endl;
        for (int j=0;j<2;j++)
        {
            d[j][bb]=numtobigvar(0);
            //cerr << " i was there" << endl;
            for(int t=0;t<2;t++)
            {
                if(t==0)
                {
                    if(j==0)
                        continue;
                    else
                    {
                        d[j][bb]=bplus(d[j][bb],d[t][!bb]);
                    }
                }
                else
                {
                    //cerr << " i'm here" << endl;
                    d[j][bb]=bplus(d[j][bb],bmultiply(numtobigvar(K-1),d[t][!bb]));
                }
            }
        }
    }
    /*for(int i=0;i<=N;i++)
    {
        for (int j=0;j<K;j++)
        {
            coutt(d[j][i]);
            cerr << ' ';
        }
        cerr << endl;
    }*/
    coutt(bmultiply(numtobigvar(K-1),d[1][bb]));
}

