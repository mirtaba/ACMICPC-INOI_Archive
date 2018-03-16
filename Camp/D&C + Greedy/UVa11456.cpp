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

//ofstream fout ("11456.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout



void LIS(vector <int> in, vector <int> &out , bool mark[]){

    if(in.size() == 0) return;

    vector <int> par(in.size(),(int)-1) ;
	vector <int> lisNumb , lisIndex;

	for(int i = 0; i < in.size(); i++){

        if(mark[i]) continue;

        auto it = lower_bound(lisNumb.begin(),lisNumb.end(),in[i]);

        int index = it-lisNumb.begin();
        if(it == lisNumb.end()) {

                lisNumb.push_back(in[i]);
                lisIndex.push_back(i);
        }
        else{
           lisNumb[index] = in[i];
           lisIndex[index] = i;
        }

        if(index != 0)
            par[i] = lisIndex[index-1];

	}

	out.push_back(in[lisIndex[lisIndex.size()-1]]);
	int tp = par[lisIndex[lisIndex.size()-1]];
	while(tp != -1){

        out.push_back(in[tp]);
        tp = par[tp];

	}

}



int main() {

	ios::sync_with_stdio(0);
    int T;
    cin >> T;

    for(int tt = 0 ; tt < T ; tt++){

        int n;
        cin >> n ;
        if(n == 0) {cout << 0 << endl; continue;}
        vector <int> in;
        for(int i = 0 ; i < n ; i++){
            int tmp;
            cin >> tmp;
            in.push_back(tmp);
        }

        int ans = -1;
        bool mark[Maxn];

        for(int i = 0 ; i< n ;i++){

            memset(mark,0,sizeof(mark));
            for(int j = 0 ; j < n ; j++){

                if(j<i || in[j] < in[i]){
                    mark[j] = true;
                }
            }

            vector <int> lis, lds;

            LIS(in,lds,mark);

            memset(mark,0,sizeof(mark));
            for(int j = 0 ; j < n ; j++){

                if(j<i || in[j] > in[i]){
                    mark[j] = true;
                }
            }

            reverse(in.begin(),in.end());
            reverse(mark,mark+n);

            LIS(in,lis,mark);

            reverse(in.begin(),in.end());

            ans = max(ans, (int)(lds.size()+lis.size() -1));

            /**
            cerr << in[i] << ":" << endl;
            for(int j = 0; j < lis.size(); j++){
                cerr << lis[j] << ' ';
            }
            cerr << endl;
            for(int j = 0; j < lds.size(); j++){
                cerr << lds[j] << ' ';
            }
            cerr << endl;
            /**/

        }

        cout << ans << endl;


    }

}
