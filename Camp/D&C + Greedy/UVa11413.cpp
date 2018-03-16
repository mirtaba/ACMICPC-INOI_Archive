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

//ofstream fout ("11413.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int in[Maxn];

int numberOfContainers(int d, int n){
    int ret = 1 , tmpSum = 0;
    for(int i = 0; i < n ; i++){

        tmpSum += in[i];
        if(tmpSum > d){
            tmpSum = in[i];
            ret++;
        }
    }
    //cerr << d << ' ' << ret << endl;
    return ret;
}


int main() {
	ios::sync_with_stdio(0);
	int n,m;
	while(cin >> n >> m){
        int maxi = 0 , sum = 0;
        for(int i = 0 ; i < n ; i ++){
            cin >> in[i];
            maxi = max(maxi,in[i]);
            sum += in[i];
        }
        int i = maxi;
        int j = sum;
        while(j-i > 1){

            int mid = (i+j)/2;
            if(numberOfContainers(mid,n)<=m){
                j = mid;
            }
            else{
                i = mid;
            }

        }
        if(numberOfContainers(i,n) <= m){
            cout << i << endl;
        }
        else{
            cout << j << endl;
        }
	}
}
