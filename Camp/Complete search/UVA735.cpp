#include <bits/stdc++.h>

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MIN(a,b) (((a) < (b))? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second
#define Traxe(X) cerr << #X << " = " << X << endl
#define _ << " _ " <<


using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("735.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int main() {
	//ios::sync_with_stdio(0);
	vector <int> points;
	for (int i = 0 ; i < 21 ; i++){
        points.push_back(i);
        points.push_back(2*i);
        points.push_back(3*i);
	}
	points.push_back(50);
	sort(points.begin(),points.end());
	auto it = unique(points.begin(),points.end());
	points.resize(distance(points.begin(),it));
    //reverse(points.begin(),points.end());

    LL n;
	while (cin >> n && n > 0){

        LL combAns = 0 , perAns = 0;
        for(int i = 0; i < points.size(); i++){

            LL tmp = points[i];
            if(tmp > n){
                tmp -= points[i];
                continue;
            }
            for(int j = i; j < points.size();j++){

                tmp += points[j];
                if(tmp > n){
                    tmp -= points[j];
                    continue;
                }
                for(int t = j; t < points.size();t++){

                    tmp += points[t];
                    if(tmp == n){
                        combAns++;
                    }
                    tmp -= points[t];
                }
                tmp -= points[j];
            }
            tmp -= points[i];
        }

        if(combAns == 0){
            cout << "THE SCORE OF "<< n <<" CANNOT BE MADE WITH THREE DARTS."<<endl;
            printf("%s\n",string(70,'*').c_str());
            continue;
        }

        for(int i = 0; i < points.size(); i++){

            LL tmp = points[i];
            if(tmp > n){
                tmp -= points[i];
                continue;
            }
            for(int j = 0; j < points.size();j++){

                tmp += points[j];
                if(tmp > n){
                    tmp -= points[j];
                    continue;
                }
                for(int t = 0; t < points.size();t++){

                    tmp += points[t];
                    if(tmp == n){
                        perAns++;
                    }
                    tmp -= points[t];
                }
                tmp -= points[j];
            }
            tmp -= points[i];
        }

        cout <<"NUMBER OF COMBINATIONS THAT SCORES "<< n << " IS "<< combAns << "." << endl;
        cout <<"NUMBER OF PERMUTATIONS THAT SCORES "<< n << " IS "<< perAns << "." << endl;
        printf("%s\n",string(70,'*').c_str());

	}
	cout << "END OF OUTPUT" << endl;
}
