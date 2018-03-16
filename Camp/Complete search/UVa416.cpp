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


#define bitAt(a,b) (a & (1<<b))


//ofstream fout ("416.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int main() {
	ios::sync_with_stdio(0);

	int seg[Maxn];
	seg[0] = 0B0111111;
	seg[1] = 0B0000110;
	seg[2] = 0B1011011;
	seg[3] = 0B1001111;
	seg[4] = 0B1100110;
	seg[5] = 0B1101101;
	seg[6] = 0B1111101;
	seg[7] = 0B0000111;
	seg[8] = 0B1111111;
	seg[9] = 0B1101111;

    int n;
	while(cin >> n , n){
        vector <int> in;
        for(int i = 0 ; i < n; i++){
            int tmp = 0;
            for(int j = 0 ; j < 7 ; j++){
                char ch;
                cin >> ch;
                if(ch == 'Y'){
                    tmp |=  (1<<j);
                }

            }
            in.push_back(tmp);
        }
        bool ansNotFound = 1;
        for(int i = 9 ; i >(n-2) ; i--){
            int burned = 0;
            bool flag = 1;
            for(int j = 0;j < n && flag; j++){
                //cerr << ' ' <<  i << endl;
                //cerr << burned << endl;
                if((in[j] & burned) != 0){
                    flag = 0;
                    break;
                }
                int tmp = burned & seg[i-j];
                int numb = seg[i-j] ^ tmp;
                //cerr << numb << endl;
                int koft = numb & in[j];
                //cerr << koft << endl;
                if(koft == in[j] ){
                    burned |= seg[i-j] ^ koft;
                }
                else{
                    flag = 0;
                }
            }

            if(flag){
                //cerr << i << endl;
                //cerr << burned << endl;
                cout << "MATCH" << endl;
                ansNotFound = 0;
                break;
            }

        }
        if(ansNotFound){
            cout << "MISMATCH" << endl;
        }
	}

}
