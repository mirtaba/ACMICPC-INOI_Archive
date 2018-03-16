/*
ID: ghoolha1
PROG: greetings
LANG: C++
*/
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <cmath>
#include <fstream>
*/

#include <bits/stdc++.h>

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MIN(a,b) (((a) < (b))? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second
#define Traxe(X) cerr << #X << " = " << X << endl
#define _ << " _ " <<


using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

ofstream fout ("441.out");
//ifstream fin ("greetings.in");

//#define cin fin
#define cout fout

int main() {
	ios::sync_with_stdio(0);
    int n;
    bool flag = true;
    while( cin >> n , n) {
        if(flag) {
            flag = false;
        }
        else {
            cout << endl;
        }
        vector <int> in;
        for( int i = 0 ; i < n ; i++ ) {

            int tmp;
            cin >> tmp;
            in.push_back( tmp);

        }
        sort(in.begin(),in.end());
        for(int a = 0 ; a < n -5 ; a++) {
            for(int b = a+1 ; b < n -4 ; b++) {
                for(int c = b+1 ; c < n - 3 ; c++) {
                    for(int d = c+1 ; d < n -2 ; d++) {
                        for(int e = d+1 ; e < n - 1 ; e++) {
                            for(int f = e+1 ; f < n ; f++) {

                                cout << in[a] << ' ' << in[b] << ' ' << in[c] << ' ' << in[d] << ' ' << in[e] << ' ' << in[f] << endl;

                            }
                        }
                    }
                }
            }
        }

    }
}
