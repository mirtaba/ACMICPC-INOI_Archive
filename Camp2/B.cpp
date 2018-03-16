#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long LL;

int main(){
    LL n;
    vector<pair<LL,LL> > a;
    cin >> n;
    for(int i = 0; i < n; i++){
        LL x,y;
        cin >> x >> y;
        a.push_back({y,-1*x});
    }
    sort(a.begin(),a.end());

    LL sum = 0,tmp = 0;
    sum = -a[0].Y;tmp = -a[0].Y  - a[0].X;
    for(int i=1;i<n;i++){
        if(-a[i].Y - tmp > 0){
            sum += -a[i].Y-tmp;
            tmp = -a[i].Y - a[i].X;
        }
        else{
            tmp = tmp - a[i].X;
        }
    }
    cout << sum << endl;
    return 0;
}
