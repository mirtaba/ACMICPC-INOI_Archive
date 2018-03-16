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

int n , in[Maxn], goal ;

int main() {

	ios::sync_with_stdio(0);
	while(cin >> n){

        for(int i = 0; i < n ; i++){

            cin >> in[i];
        }

        cin >> goal;
        sort(in,in+n);



        /**/

        int i = 0, j = n-1;

        PII ans;
        //cerr << i << ' ' << j << endl;
        while(i < j){
            int sum = in[i] + in[j];
            if(sum == goal) {
                    ans.X = i;
                    ans.Y = j;
            }
            if(sum < goal) i++;
            else j--;
        }
        cout << "Peter should buy books whose prices are " << in[ans.X] << " and " << in[ans.Y] << "." << endl;
        cout << endl;
        /**/

	}
}
