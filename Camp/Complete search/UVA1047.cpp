#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("1047.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int n,m,goal;

int numberOfOnes(int in){

    int ans = 0;

    while(in>0){

        ans += in%2;
        in /= 2;
    }
    return ans;

}

int main() {

	ios::sync_with_stdio(0);

	/**
	int i = 1;
	int j ;
	cerr << "skdjafkl" << endl;
	j = 2 << 2;
    cerr << j << endl;
    /**/
    int T = 0;
	while(cin >> n >> goal , n , goal){

        int tower[Maxn];
        vector <PII> meet;

        for(int i = 0; i < n ; i++){
            cin >> tower[i];
        }

        cin >> m;
        for(int i = 0; i < m ; i++){
            int tmp;
            cin >> tmp;

            int mask = 0;

            for(int j = 0; j < tmp ; j++){

                int tp;

                cin >> tp;
                tp--;

                mask |= ( 1 << tp );

            }

            int tmpVal;
            cin >> tmpVal;
            //cerr << mask << ' ' << tmpVal << endl;
            meet.push_back({mask,tmpVal});
        }

        int ansVal = 0 , ansMask = 0;

        for(int i = 0; i < (1<<(n)) ; i++){

            if(numberOfOnes(i) == goal){

                int sumOfTowers = 0;
                int tp = i;
                int cnt = 0;

                while(tp>0){

                    if(tp%2){
                        sumOfTowers += tower[cnt];
                    }

                    cnt++;

                    tp /= 2;
                }
                //if(i == 14) cerr << sumOfTowers << endl;
                for(int j = 0; j < m ; j++){

                    int tmp = meet[j].X & i;
                    if(numberOfOnes(tmp)>1){

                        sumOfTowers -= (numberOfOnes(tmp) - 1) * meet[j].Y;
                    }

                }

                //cerr << ansVal << ' ' << sumOfTowers << endl;
                if(sumOfTowers > ansVal){
                    //cerr << ansVal << ' ' << ansMask << endl;
                    ansVal = sumOfTowers;
                    ansMask = i;
                    //cerr << ansVal << ' ' << ansMask << endl;
                }
            }

        }

        cout << "Case Number  " << ++T << endl;
        cout << "Number of Customers: " << ansVal << endl;
        cout << "Locations recommended:";

        int cnt = 0;
        while(ansMask > 0){

            if(ansMask%2){
                cout << ' ' << cnt+1;
            }

            cnt++;

            ansMask /= 2;

        }
        cout << endl;
        cout << endl;




	}
    /**/


}
