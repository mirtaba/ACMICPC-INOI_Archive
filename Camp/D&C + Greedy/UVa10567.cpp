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

string s,inS;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin >> s;
	cin >> n;
	for(int i = 0; i < n ; i++){
        cin >> inS;
        int t = 0;
        int startIndex = -1;
        int endIndex;

        for(int j = 0; j < s.size(); j++){

            if(t == inS.size()) break;

            if(inS[t] == s[j]){

                endIndex = j ;
                if(startIndex == -1){
                    startIndex = j ;
                }

                t++;

            }

        }

        if(t == inS.size()){
            cout << "Matched " << startIndex << ' ' << endIndex << endl;
        }
        else{
            cout << "Not matched" << endl;
        }
	}
}
