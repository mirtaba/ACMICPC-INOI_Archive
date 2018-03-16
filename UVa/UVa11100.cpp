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

int cnt[Maxn];
int main() {
	ios::sync_with_stdio(0);

	int n;
	while(cin >> n , n){

        memset(cnt,0,sizeof(cnt));
        vector <int> in;
        PII maxi = {0,0};

        for(int i = 0 ; i < n ; i++){
            int tmp;
            cin >> tmp;
            in.push_back(tmp);

            cnt[tmp]++;
            if(cnt[tmp] > maxi.X){

                maxi.X = cnt[tmp];
                maxi.Y = tmp;

            }

        }

        vector < vector<int> > ans(maxi.X , vector<int>(0) );

        sort(in.begin(),in.end());
        auto it = lower_bound(in.begin(),in.end(),maxi.Y);
        int pos = it - in.begin();
        //cerr << pos << endl;

        int ansIt = 0;

        for(int i = pos -1 ; i>-1; i--){
            //cerr << ansIt << endl;
            ans[ansIt].push_back(in[i]);
            ansIt = (ansIt+1) %(maxi.X);
        }
        for(int i = pos ; i < in.size();i++){
            //cerr << in[i] << endl;
            ans[ansIt].push_back(in[i]);
            ansIt = (ansIt+1) %(maxi.X);
        }
        cout << maxi.X << endl;
        for(int i = 0 ; i < maxi.X; i++){
            if(ans[i].size()>0){
                sort(ans[i].begin(),ans[i].end());
                cout << ans[i][0];
                for(int j = 1; j < ans[i].size(); j++){
                    cout << ' ' << ans[i][j];
                }
                cout << endl;
            }
        }
        cout << endl;
        //cerr << ans[ansIt].size() << endl;

	}
}
