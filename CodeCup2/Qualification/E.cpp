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

        LL n,cnt=0;
        cin >> n;

        if(n%2 == 0){
            double tp1 = (n/48.0d);
            tp1 *= n;
            LL tp2 = tp1;
            //cout << round(tp1) << endl;
            /**/
            if((float)(tp1-tp2) <= 0.5){
                cout << tp2 << endl;
            }
            else{
                cout << tp2+1 << endl;
            }
            /**/

        }
        else{
            double tp1 = (n+3)/48.0d;
            tp1 *= (n+3);
            LL tp2 = tp1;
            //cout << round(tp1) << endl;
            /**/
            if((float)(tp1-tp2) <= 0.5){
                cout << tp2 << endl;
            }
            else{
                cout << tp2+1 << endl;
            }
            /**/
        }

    }
