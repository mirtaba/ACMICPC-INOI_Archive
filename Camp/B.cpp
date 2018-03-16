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

int n , a , ans = abMax , ansCnt = 0;
vector <int> leftV , rightV;

int main() {
	ios::sync_with_stdio(0);

	cin >> n >> a;

	for(int i = 0; i < n ; i++){
        int tmp;
        cin >> tmp;
        if(tmp == a){

            ansCnt++;
        }
        else{

            if(tmp < a){
                leftV.push_back(a-tmp);
            }
            else{
                rightV.push_back(tmp-a);
            }
        }
	}

	if(ansCnt > (n-2)) {
        cout << 0 << endl;
        return 0;
	}

	n-=ansCnt;

	sort(leftV.begin(),leftV.end());
	sort(rightV.begin(),rightV.end());

	if(leftV.size() >= (n-1)){
	    ans = leftV[n-2];
	}
    if(rightV.size() >= (n-1)){
	    ans = min(ans , rightV[n-2]);
	}

	for(int i = 0;i < max(leftV.size(),rightV.size());i++){
        int tmp = abMax;
        if(i<leftV.size()){

            tmp = leftV[i]*2;
            if((n-i-2)>0){
                if((n-i-2)<rightV.size())
                    tmp += rightV[n-i-3];
                else
                    tmp = abMax;
            }
        }
        ans = min(ans,tmp);
        //cerr << i << ' ' << ans << endl;
        if(i<rightV.size()){

            tmp = rightV[i]*2;
            if((n-i-2)>0){
                if((n-i-2)<leftV.size())
                    tmp += leftV[n-i-3];
                else
                    tmp = abMax;
            }
        }
        ans = min(ans,tmp);
        //cerr << ' ' << i << ' ' << ans << endl;
	}
	cout << ans << endl;

}
