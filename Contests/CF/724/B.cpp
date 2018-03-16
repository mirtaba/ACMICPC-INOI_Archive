#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int main() {
	ios::sync_with_stdio(0);

	int n,m;
	cin >> n >> m;
	int in[Maxn][Maxn] , mask[Maxn] , cnt[Maxn];

	for(int i = 0 ; i< n ; i ++){
        cnt[i] = 0;
        mask[i] = 0;
        for (int j = 0 ; j < m ; j++){
            int tp;
            cin >> tp;
            tp--;
            in[i][j] = tp;
            if(j != tp){
                cnt[i]++;
                mask[i] |= (1<<j);
            }
        }
	}

	int maskAll = mask[0] , maxCnt = 0;

    for(int i = 0 ; i< n ; i ++){

        if(cnt[i] > 4){
            cout << "NO" << endl;
            break;
        }
        maxCnt = max(maxCnt,cnt[i]);
        maskAll &= mask[i];
	}
	if(maxCnt < 3){
        cout << "YES" << endl;
        return 0;
	}

	int counter = 0;
    vector <int> itp;
	for(int j = 0 ; j < m ; j++){
        if(maskAll & (1<<j)){
            counter++;
            itp.push_back(j);
        }
	}
	if(counter < 2){
        cout << "NO" << endl;
        return 0;
	}
	else{
        for(int i = 0 ; i< n ; i ++){

            if(cnt[i] == 4){
                bool flag = false;
                for (int j = 0 ; j < itp.size() ; j++){
                    if(in[i][j] != j && in[i][in[i][j]] == j ){
                        flag = true;
                    }
                }
                if(!flag){
                    cout << "NO" << endl;
                    return 0;
                }

            }
        }

        cout << "YES" << endl;
        return 0;
	}
}
