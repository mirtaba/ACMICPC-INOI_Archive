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

int main() {
	ios::sync_with_stdio(0);
	int n , m;
	while(cin >> n >> m , n , m){


        vector <int> head,knight;

        for(int i = 0 ; i < n ; i++ ){

            int tmp;
            cin >> tmp;

            head.push_back(tmp);
        }
        sort(head.begin(),head.end());

        for(int i = 0 ; i < m ; i++ ){

            int tmp;
            cin >> tmp;

            knight.push_back(tmp);
        }
        sort(knight.begin(),knight.end());

        int j = 0;//j iterates on knights
        int wage = 0 , cnt = 0;// cnt counts number of slayed dragon heads

        for(int i = 0; i < head.size();i++){
            while(knight[j]<head[i] && j < knight.size()) j++;
            if(j == knight.size()){
                break;
            }

            //cerr << j << endl;
            wage+= knight[j];
            j++;
            cnt++;
        }
        if(cnt < n){
            cout << "Loowater is doomed!" << endl;
            continue;
        }
        cout << wage << endl;



	}
}
