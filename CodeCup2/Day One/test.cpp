#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

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
int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	int maxi =0;
	for(int i=0;i<n;i++){
        cin >> s;
        /**
        set<char> myset;
        maxi =0;
        for(int j=0;j<s.size();j++){
            myset.insert(s[j]);
        }
        maxi = max(maxi , (int)myset.size());
        /**/
        sort(s.begin(),s.end());
        auto it = unique(s.begin(),s.end());
        s.resize(it-s.begin());
        maxi = s.size();
	}
	cout << maxi << endl;
}

