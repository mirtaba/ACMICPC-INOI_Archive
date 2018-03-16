#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 1000*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout
int n;
LL buy[Maxn];
LL give[Maxn];
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	/**
	LL maxi = -abMax;

	LL sum = 0;
	for(int i = 0 ; i < n ; i++){
        int t;
        cin >> t;
        sum += t;
        maxi = max(maxi, sum);
	}
	if(maxi < 0)
        cout << 0 << endl;
    else
        cout << maxi << endl;
	/**/
	int f;
	cin >> f;
	if(f>0) buy[0] = f,give[0] = 0;
	else buy[0] = 0,give[0] = -f;
	for(int i=1;i<n;i++){
        int a;
        cin >> a;

        if(a<0){
            give[i] = -a;
        }
        else if(a>0 && give[i-1]-a < 0){
            buy[i] = abs(give[i-1]-a);
            give[i] = 0;
        }
        else{
            buy[i] = 0;
            give[i] = give[i-1] - a;
        }
	}
	LL sum = 0;
	for(int i=0;i<n;i++){
        sum += buy[i];
	}
	/**
	LL sum = 0;
	for(int i=0;i<n;i++){
        LL a;
        cin >> a;
        sum += a;
	}
	/**/
	cout << sum << endl;
}

