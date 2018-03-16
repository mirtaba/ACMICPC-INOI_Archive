#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL, LL> PLL;
const int Maxn = 5*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

LL dx[] = {1,1,-1,1};
LL dy[] = {-1,1,1,1};

PLL pos[10*Maxn];
int T[Maxn][Maxn];

int main() {
	ios::sync_with_stdio(0);
	memset(T,-1,sizeof(T));
    T[0][0] = 0;
    pos[0] = {0,0};
    T[1][1] = 1;
    pos[1] = {1,1};
	int i = 2 , j = 0;
	while(i < 10200){
        pos[i] = {pos[i-1].X+dx[j],pos[i-1].Y+dy[j]};
        //cerr << i << endl;
        //cerr << pos[i].X << ' ' << pos[i].Y << endl;
        T[pos[i].X][pos[i].Y] = i;
        i++;
        j++;
        j%=4;
	}
	//T[0][0] = 0;
	int t;
	cin >> t;
	for(int p = 0 ; p < t;p++){
        int x , y;
        cin >> x >> y;
        cout << T[x][y] << endl;
	}
}
