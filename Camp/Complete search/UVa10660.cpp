#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("10660.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int tt;

int dist(PII a , PII b){


    return(abs(a.X-b.X) + abs(a.Y-b.Y));

}


int main() {
	ios::sync_with_stdio(0);
    cin >> tt;
    while(tt--){
        int n;
        int in[Maxn][Maxn];
        memset(in,0,sizeof(in));
        cin >> n;
        vector <PII> points;
        for(int i = 0; i < n;i++){
            int t1,t2;
            cin >> t1 >> t2;
            cin >>in[t1][t2];
            points.push_back({t1,t2});
        }

        int ans = abMax;
        vector <int> ansCords;
        bool flag = true;
        for(int i = 0 ; i < 25;i++){
            PII I;
            I.X = i/5; I.Y =i%5;
            for(int j = i+1 ; j < 25;j++){
                PII J;
                J.X = j/5; J.Y =j%5;
                for(int t = j+1 ; t < 25 ;t++){
                    PII T;
                    T.X = t/5; T.Y =t%5;
                    for(int p = t+1 ; p < 25;p++){
                        PII P;
                        P.X = p/5; P.Y =p%5;
                        for(int q = p+1 ; q < 25 ;q++){
                            PII Q;
                            Q.X = q/5; Q.Y =q%5;
                            int  localAns = 0;

                            for(int e = 0; e<n;e++){

                                int localMin = abMax;
                                localMin = min(localMin , dist(I,points[e]) );
                                localMin = min(localMin , dist(J,points[e]) );
                                localMin = min(localMin , dist(T,points[e]) );
                                localMin = min(localMin , dist(P,points[e]) );
                                localMin = min(localMin , dist(Q,points[e]) );

                                localAns += localMin * in[points[e].X][points[e].Y];

                            }

                            if(ans > localAns){

                                ans = localAns;
                                ansCords.clear();
                                ansCords.push_back(i);
                                ansCords.push_back(j);
                                ansCords.push_back(t);
                                ansCords.push_back(p);
                                ansCords.push_back(q);
                            }

                        }
                    }
                }
            }
        }
        cout << ansCords[0];
        for(int i = 1 ; i < 5; i++){
            cout << ' ' << ansCords[i];
        }
        cout << endl;

    }
}
