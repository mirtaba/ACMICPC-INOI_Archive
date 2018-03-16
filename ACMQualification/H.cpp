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

map<string,LL> m;

int main() {
	ios::sync_with_stdio(0);
	m["negative"] = -1;
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    m["ten"] = 10;
    m["eleven"] = 11;
    m["twelve"] = 12;
    m["thirteen"] = 13;
    m["fourteen"] = 14;
    m["fifteen"] = 15;
    m["sixteen"] = 16;
    m["seventeen"] = 17;
    m["eighteen"] = 18;
    m["nineteen"] = 19;
    m["twenty"] = 20;
    m["thirty"] = 30;
    m["forty"] = 40;
    m["fifty"] = 50;
    m["sixty"] = 60;
    m["seventy"] = 70;
    m["eighty"] = 80;
    m["ninety"] = 90;
    m["hundred"] = 100;
    m["thousand"] = 1000;
    m["million"] = 1000000;

	string s;
	while(getline(cin,s)){
        stringstream ss;
        LL sign = 1;
        LL res = 0;
        LL part = 0;
        LL prevVal = 0;
        string tmp;
        ss << s;
        while(ss >> tmp){
            LL val = m[tmp];
            //cerr << "debug  " << val << endl;
            if(val == -1){
                sign = -1;
            }
            else if(val != 1000 && val != 1000000){
                if(val == 100){
                        part *= val;
                }
                else{
                    part += val;
                }
            }
            else{
                    if(prevVal != 1000 && prevVal != 1000000){
                        part *= val;
                        res += part;
                        part = 0;
                    }
                    else{
                        res *= val;
                    }
            }
        prevVal = val;
        }
        res += part;
        cout << res * sign << endl;
	}
}
