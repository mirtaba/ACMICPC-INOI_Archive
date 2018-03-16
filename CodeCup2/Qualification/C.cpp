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

string convertTostring(int a){
    string ss;
    int r;
    while(a>0){
        r = a%10;
        char ch = r + '0';
        ss += ch;
        a/=10;
    }
    reverse(ss.begin(),ss.end());
    //cerr << ss << endl;
    return ss;
}

int main() {
	ios::sync_with_stdio(0);
	string s,ss;
	cin >> s;
	int tp = 0;
	while(s.size()!=1){
        tp = 0;
        for(int i=0;i<s.size();i++){
            tp += s[i]-'0';
        }
        s = convertTostring(tp);
	}

	cout << s << endl;
}

