#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("last.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int main() {
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while(T--){

		string s1[Maxn],s2[Maxn];
        int n;
		cin >> n;
		vector <char> s[Maxn];
		for(int i = 0 ; i < 6 ;i++)
            cin >> s1[i];
		for(int i = 0 ; i < 6 ;i++)
            cin >> s2[i];
        for(int i = 0 ; i < 5 ;i++){
            for(int j = 0 ; j < 6 ;j++){

                for(int k = 0 ; k < 6 ;k++){

                    if(s1[j][i] == s2[k][i]){

                        s[i].push_back( s1[j][i]);
                    }

                }

            }
        }

		for(int i = 0 ; i < 5 ;i++){
			sort(s[i].begin(),s[i].end());
			auto it = unique(s[i].begin(),s[i].end());
			s[i].resize(distance(s[i].begin(),it));
		}

        int sum = 0;
        bool flag = 1;
        for(int i = 0 ; i< s[0].size() && flag;i++){
            for(int j = 0 ; j< s[1].size() && flag;j++){
                for(int k = 0 ; k< s[2].size() && flag;k++){
                    for(int t = 0 ; t< s[3].size() && flag;t++){
                        for(int p = 0 ; p< s[4].size() && flag;p++){
                            sum++;
                            if(sum == n){
                                cout << s[0][i] << s[1][j] <<s[2][k] <<s[3][t] <<s[4][p] <<endl;
                                flag = 0;
                            }
                        }
                    }
                }
            }
        }
        if(flag){
            cout << "NO" << endl;
        }



	}
}
