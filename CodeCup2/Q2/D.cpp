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

int n , k;
vector <int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> k;
	int i = 1 , j =2;
	vector <int> tmp;
	while(j < k+2){
        tmp.push_back(i);
        i += k;
        if(i>n){
            i = j;
            j++;
            for(int i = tmp.size()-1; i>=0; i--){
                ans.push_back(tmp[i]);
            }
            tmp.clear();
        }
	}
	bool flag = true;
	for(int i = 1 ; i< ans.size();i++){
        if(abs(ans[i] - ans[i-1]) < k){
            flag = false;
        }
	}
	if(!flag){
        cout << "Impossible" << endl;
	}
	else{
        cout << ans[0];
        for(int i = 1 ; i< ans.size();i++){
            cout << ' ' << ans[i];
        }
        cout << endl;
	}

}
