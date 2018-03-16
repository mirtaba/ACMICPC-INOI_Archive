#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("Ans.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout
int in[Maxn][Maxn];

string BtoD(int n1 , int n2 , int m1 , int m2){ // [n1,n2) [m1,m2)

    bool flag = 1;
    int tmp = in[n1][m1];

    for(int i = n1; i < n2 && flag ;i++){
        for(int j = m1 ; j < m2 && flag;j++){
            //cerr << i << ' ' << j << endl;
            if(tmp != in[i][j]){

                flag = 0;

            }
        }
    }
    if(flag){
        //cerr << n1 << ' ' << n2 << ' ' << m1 << ' ' << m2 << endl;
        //cerr << to_string(in[n1][m1]) << endl;
        return to_string(in[n1][m1]);
    }

    int n = n2-n1;
    int m = m2-m1;

    string ans = "D";
    //cerr << ans << endl;
    ans += BtoD(n1, n1+(n+1)/2, m1, m1+(m+1)/2);
    if(m>1) ans += BtoD(n1, n1+(n+1)/2, m1+(m+1)/2, m2);
    if(n>1) ans += BtoD(n1+((n+1)/2), n2, m1, m1+(m+1)/2);
    if(m>1 && n>1) ans += BtoD(n1+((n+1)/2), n2, m1+(m+1)/2, m2);
    //cerr << ans << endl;
    return ans;

}

string s;
int x;

void DtoB(int n1 , int n2 , int m1 , int m2 ){ // [n1,n2) [m1,m2)

    if(x == s.size())
        return;
    if(s[x] == 'D'){
        x++;
        int n = n2-n1;
        int m = m2-m1;

        DtoB(n1, n1+(n+1)/2, m1, m1+(m+1)/2);
        if(m>1) DtoB(n1, n1+(n+1)/2, m1+(m+1)/2, m2);
        if(n>1) DtoB(n1+((n+1)/2), n2, m1, m1+(m+1)/2);
        if(m>1 && n>1) DtoB(n1+((n+1)/2), n2, m1+(m+1)/2, m2);

    }
    else{

        for(int i = n1; i < n2  ;i++){
            for(int j = m1 ; j < m2 ;j++){

                in[i][j] = s[x] - '0';
            }
        }
        x++;
    }


}


int main() {

	//ios::sync_with_stdio(0);

	char ch;
	bool flag = 0;
	while (cin >> ch && ch != '#'){

        if(ch == 'B'){
            int n,m;
            cin >> n >> m;

            for(int i = 0; i < n ; i++){
                for(int j = 0; j < m ; j++){
                    char tmp;
                    cin >> tmp;
                    in[i][j] = tmp - '0';
                    //cerr << in[i][j];

                }
                //cerr << endl;
            }

            printf("D%4d%4d\n" , n , m );

            string ans =  BtoD(0,n,0,m);
            int xx = 0;

            for(int i = 0 ; i < ans.size() ; i++){
                xx++;
                cout << ans[i];
                if(xx == 50){
                    cout << endl;
                    xx = 0;
                }
            }
            if(xx>0)
                cout << endl;

        }

        if(ch == 'D'){

            int n,m;
            cin >> n >> m;

            cin >> s;
            x = 0;
            DtoB(0,n,0,m);

            printf("B%4d%4d\n" , n , m );


            int xx = 0;
            for(int i = 0; i < n ; i++){
                for(int j = 0; j < m ; j++){
                    xx++;
                    cout << in[i][j];
                    if(xx == 50) {
                        cout << endl;
                        xx = 0;
                    }

                }
            }
            if(xx>0)
                cout << endl;

        }

	}
}

