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

int n , m , T;
bool mark[Maxn];
vector <PII> D;
bool AnsFound = 0;

void backtrack(int x , int h , int t){

    if(AnsFound)
        return;

    if(x == 1){
        for(int i = 0 ; i < m ; i++){
            if(!mark[i]){
                if((D[i].X == h && D[i].Y == t) || (D[i].Y == h && D[i].X == t)){
                    AnsFound = 1;
                    return;
                }
            }
        }
    }

    for(int i = 0 ; i < m ; i++){
        if(!mark[i]){
            if(D[i].X == h){
                mark[i] = true;
                backtrack(x-1,D[i].Y,t);
                mark[i] = false;
            }
            else if(D[i].Y == h){
                mark[i] = true;
                backtrack(x-1,D[i].X,t);
                mark[i] = false;
            }
        }
    }


}

int main() {
	ios::sync_with_stdio(0);

	while(cin >> n >> m){

        int tp,head,tale;
        cin >> tp >> head;
        cin >> tale >> tp;
        D.clear();
        for(int i = 0; i < m ; i++){
            int t1,t2;
            cin >> t1 >> t2;
            D.push_back({t1,t2});
        }
        AnsFound = 0;
        memset(mark,0,sizeof(mark));
        backtrack(n,head,tale);
        if(AnsFound){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

	}
}
