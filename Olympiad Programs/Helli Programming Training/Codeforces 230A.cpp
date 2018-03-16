#include <iostream>
#include <vector>
#include <algorithm>

#define LL long long

using namespace std;

vector < pair<LL,LL> > in;
LL n;
unsigned long long s;

int main()
{
    cin >> s >> n;
    LL tmp1=0,tmp2=0;
    for(LL i=0;i<n;i++)
    {
        cin>> tmp1 >> tmp2;
        in.push_back(make_pair(tmp1,tmp2));
    }
    sort(in.begin(),in.end());
    for(int i=0;i<n;i++)
    {
        cerr << in[i].first << ' ' << in[i].second <<  endl;
    }
    LL i=0;
    while(s>in[i].first)
    {
        s+=in[i].second;
        i++;
        if (i==n)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
