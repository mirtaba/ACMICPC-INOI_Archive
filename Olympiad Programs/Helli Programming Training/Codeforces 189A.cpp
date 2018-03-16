#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn=4*1E4+25;

int N,a,b,c;
//bool can[Maxn];
int num[Maxn];
int main()
{
    cin >> N >> a >> b >> c;
    num[a]=1;
    num[b]=1;
    num[c]=1;
    for (int i=1;i<=N;i++)
        if(num[i]!=0)
        {
            num[i+a]=max(num[i+a],num[i]+1);
            num[i+b]=max(num[i+b],num[i]+1);
            num[i+c]=max(num[i+c],num[i]+1);
        }
    cout << num[N] << endl;
}
