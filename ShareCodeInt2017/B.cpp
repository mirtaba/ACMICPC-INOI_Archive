#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 10*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

LL d[Maxn][Maxn];

int LCS (vector <int> in1, vector <int> in2
         //, vector <int> &out
         ){


    for(int i = 0 ; i < in1.size()+1; i++){
        d[i][0] = 0;
    }
    for(int j = 0 ; j < in2.size()+1; j++){
        d[0][j] = 0;
    }

    LL maxe=0;

    for (int i=1;i<=in1.size();i++)
    {
        for (int j=1;j<=in2.size();j++)
        {
            if(in1[i-1] == in2[j-1])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j-1],max(d[i][j-1],d[i-1][j]));

            maxe = maxe < d[i][j] ? d[i][j] : maxe;
        }
    }
    return maxe;
}

int LCSCustom(vector <int> in1, vector <int> in2){

    LL ans = 0;
    for(int i = 0 ; i < in1.size(); i++){
        if(i != 0 && in1[i-1] == in1[i]){
            continue;
        }
        vector<int>::iterator it1 = lower_bound(in2.begin(),in2.end(),in1[i]);
        vector<int>::iterator it2 = upper_bound(in2.begin(),in2.end(),in1[i]);

        vector<int>::iterator it3 = lower_bound(in1.begin(),in1.end(),in1[i]);
        vector<int>::iterator it4 = upper_bound(in1.begin(),in1.end(),in1[i]);

        ans += min(it2-it1,it4-it3);

    }
    return ans;

}


int T , n , m;

vector <int > in1,in2;

int main() {
	ios::sync_with_stdio(0);
	cin >> T;
	while(T--){
        cin >> n >> m;
        in1.clear();
        in2.clear();
        for(int i = 0; i < n ; i++){
            int tmp;
            cin >> tmp;
            in1.push_back(tmp);
        }
        for(int i = 0; i < m ; i++){
            int tmp;
            cin >> tmp;
            in2.push_back(tmp);
        }
        sort(in1.begin(),in1.end());
        sort(in2.begin(),in2.end());
        cout << LCSCustom(in1,in2) << endl;
	}

}
