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

string s1,s2;

int val(string s){

    if(s[0] == 'm'){
        return 0;
    }
    if(s[0] == 't'){
        if(s[1] == 'u')
            return 1;
        else
            return 3;
    }
    if(s[0] == 'w'){
        return 2;
    }
    if(s[0] == 'f'){
        return 4;
    }
    if(s[1] == 'a')
        return 5;
    return 6;

}


int main() {
	ios::sync_with_stdio(0);
	cin >> s1 >> s2;
	int tp1 = val(s1);
	int tp2 = val(s2);

	if( tp1 == tp2 || ( (tp1+2)%7 == tp2 || (tp1+3)%7 == tp2 ) ){
        cout << "YES" << endl;
	}
	else{
        cout << "NO" << endl;
	}

}
