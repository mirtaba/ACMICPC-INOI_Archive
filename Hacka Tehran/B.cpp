#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back


const int Mod = 1000 * 1000 * 100 + 7;
const int Maxn = 10000 + 250 ;


vector <int> lad[Maxn];
int minDis[Maxn];
int T , n ,tmp1,tmp2;

int main()
{
    cin >> T;
    while (T--)
    {
        for(int i = 0 ; i < 150 ; i++)
        {
            lad[i].clear();
        }
        cin >> n;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> tmp1 >> tmp2;
            lad[tmp2].pb(tmp1);
        }
        cin >> n;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> tmp1 >> tmp2;
            lad[tmp2].pb(tmp1);
        }
        minDis[1] = 0;
        for(int i = 2 ; i < 1000 ; i++)
        {
            minDis[i] = Mod;
        }
        for(int i = 2 ; i < 120 ; i++)
        {
            for(int j = 0 ;j < lad[i].size() ; j++)
            {
                if(minDis[lad[i][j]]<minDis[i])
                {
                    minDis[i] = minDis[lad[i][j]];
                }
            }
            for(int j = 1 ; j < 7 ; j++)
            {
                if((minDis[i-j]+1) < minDis[i])
                {
                    minDis[i] = (minDis[i-j]+1);
                }
            }
        }
        cout << minDis[100] << endl;
    }
    return 0;
}
