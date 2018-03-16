#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back

#define FOR(i,a,b) for(int i = a ; i < b ; i++)

const int Mod = 1000 * 1000 * 100 + 7;
const int Maxn = 10000 + 250 ;

vector <int> in;

int T , n , tmp , meh , msf ,ans , backans;
bool flag;

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n;

        meh = 0;
        msf = 0;
        ans = 0;
        backans = -1 * Mod;
        flag = 0;

        FOR(i,0,n)
        {
            cin >> tmp;
            if(tmp >= 0)
            {
                ans+=tmp;
                flag = 1;
            }
            backans = max(backans , tmp);
            meh = max(tmp , meh + tmp);
            msf = max(msf,meh);
        }
        if(flag)
            cout << msf << ' ' << ans << endl;
        else
            cout << backans << ' ' << backans<< endl;

    }


    return 0;
}

