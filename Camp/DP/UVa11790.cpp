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


int LIS(int n ,int in[], int width[]){

    int L[Maxn];

    L[0] =  width[0] ;

    int ans = L[0];

    for(int i = 1; i < n ;i++){

        int maxLIS = -1;

        for(int j = 0; j < i;j++){

            if(in[j] < in[i] && L[j] > maxLIS){

                maxLIS = L[j];
            }

        }

        L[i] = max(0,maxLIS) + width[i];
        ans = max(ans, L[i]);
    }
    return ans;
}



int in[Maxn] , width[Maxn];



int main() {

	//ios::sync_with_stdio(0);

    int T;
	cin >> T;


    for(int tt = 1 ; tt <= T ; tt++){

        int n;
        cin >> n;

        for(int i = 0; i < n ;i++){
            cin >> in[i];
        }
        for(int i = 0; i < n ;i++){
            cin >> width[i];
        }

        int ansInc = LIS(n,in,width);

        reverse(in,in+n);
        reverse(width,width+n);
        int ansDec = LIS(n,in,width);

        if(ansInc >= ansDec){

            printf("Case %d. Increasing (%d). Decreasing (%d).\n" , tt , ansInc,ansDec);
        }
        else{

            printf("Case %d. Decreasing (%d). Increasing (%d).\n" , tt , ansDec,ansInc);
        }



    }
}
