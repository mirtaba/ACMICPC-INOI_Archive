#include <bits/stdc++.h>
#define X first
#define Y second

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

#define bitAt(a,b) (a & (1<<b))

int main() {
	ios::sync_with_stdio(0);

    int t , n;
    while(cin >> t >> n , n , t){
        vector <int> in;
        for(int i = 0 ; i < n; i++){

            int tmp;
            cin >> tmp;
            in.push_back(tmp);
        }
        sort(in.begin(),in.end());
        reverse(in.begin(),in.end());
        vector <string> ans;

        for(int i = 0; i < (1 << n); i++){
            string s;
            int tmp = 0;
            for(int j = 0; j < n ; j++){
                if(bitAt(i,j)){
                    tmp += in[j];
                    s+= to_string( in[j]);
                    s+='+';
                }
            }
            if(tmp == t){
                s.erase(s.end()-1);
                ans.push_back(s);
            }
        }
        cout << "Sums of " << t << ":" << endl;
        if(ans.size() == 0){
            cout << "NONE" << endl;
        }else{
            sort(ans.begin(),ans.end());
            auto it = unique(ans.begin(),ans.end());
            ans.resize(distance(ans.begin(),it));
            reverse(ans.begin(),ans.end());
            for(int i = 0 ; i < ans.size(); i++){
                    cout << ans[i] << endl;
            }
        }

    }


}
