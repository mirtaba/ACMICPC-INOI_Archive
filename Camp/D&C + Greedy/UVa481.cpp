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

void LIS(vector <int> in, vector <int> &out){

    if(in.size() == 0) return;

    vector <int> par(in.size(),(int)-1) ;
	vector <int> lisNumb , lisIndex;

	for(int i = 0; i < in.size(); i++){

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
	int tmp;

	vector <int> in , ans;

	while(cin >> tmp) in.push_back(tmp);



    LIS(in,ans);

    cout << ans.size() << endl;
    cout << '-' << endl;
    for(int i = ans.size()-1; i>-1; i--){
        cout << ans[i] << endl;
    }


}
