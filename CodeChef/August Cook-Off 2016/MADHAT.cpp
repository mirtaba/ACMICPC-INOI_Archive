#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int in[Maxn];
LL fact[Maxn];

LL pick(int n , int m){

    LL tmp = fact[n];
    tmp /= fact[m];
    tmp /= fact[n-m];
}
bool flag = 0;

LL solve(int s, int e){

    int maxIndex = abMax;
    if(e-s == 1 || e-s == 0){
        return 1;
    }

    for(int i = s;i < e;i++){
        if( (e-i) == (in[i]+1) ){
            maxIndex = i;
            break;
        }
    }
    if(maxIndex == abMax){
        flag = 1;
    }

    int inSize = e-s-1;
    int sideSize = e-maxIndex-1;
    //cerr << inSize << ' ' << sideSize << endl;
    LL ret = pick(inSize,sideSize);
    //cerr << ret << endl;
    ret *= solve(s,maxIndex);
    ret %= Mod;
    //cerr << ret << endl;
    ret *= solve(maxIndex+1,e);
    ret %= Mod;
    //cerr << ret << endl;
    return ret;

}



int main() {
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	fact[0] = 1;
	for(int i = 1;i < Maxn ; i++){
        fact[i] = (LL)(fact[i-1] * i)%Mod;
	}
	while(T--){

        int n;
        cin >> n;
        flag = 0;
        for(int i = 0;i < n ; i++){

            cin >> in[i];
            if((in[i]+1)>(n-i)){
                flag = 1;
            }
        }
        LL ans = solve(0,n);
        if(flag){
            cout << 0 << endl;
        }
        else{
            cout << ans%Mod << endl;
        }
	}
}
