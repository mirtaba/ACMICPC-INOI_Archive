#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

string s;
string ans;
int main() {
	ios::sync_with_stdio(0);
    bool flag = false;
	while(getline(cin,s)){
        int a = 0 , b = 0;
        for(int i = 0 ; i < s.length();i++){
            switch(s[i]){
            case 'N':
                a++;
                break;
            case 'S':
                a--;
                break;
            case 'W':
                b++;
                break;
            case 'E':
                b--;
                break;
            }
        }
        //cerr << a << ' ' << b << endl;
        ans.clear();
        int tmp = abs(a);
        for(int j = 0 ; j < tmp ;j++){
            if(a<0){
                ans += 'S';
            }
            else{
                ans += 'N';
            }
        }

        tmp = abs(b);
        for(int j = 0 ; j < tmp ;j++){
            if(b<0){
                ans += 'E';
            }
            else{
                ans += 'W';
            }
        }
        //cerr << ans << endl;
        sort(ans.begin(),ans.end());
        cout << ans << endl;
	}
}
