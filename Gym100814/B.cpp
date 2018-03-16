#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

char sampleInput[] = {'A','B','C','D'};
set <char> sample (sampleInput , sampleInput+4);

vector < set <char> > ansFind ;
vector < char > ans ;
int t, q , m;



int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--){
        cin >> q >> m;
        ans.clear();
        ansFind.clear();
        for(int i = 0 ; i < q ; i++){
            ansFind.push_back(sample);
            ans.push_back('?');
        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < q ; j++){
                char quest , answer;
                cin >> quest >> answer;
                if(answer == 'T'){
                    ans[j] = quest;
                }
                else{
                    ansFind[j].erase(quest);
                }
            }
        }

        if(ans[0] != '?'){
                cout << ans[0];
            }
            else{
                if(ansFind[0].size() == 1){
                    cout << *ansFind[0].begin();
                }
                else{
                    cout << ans[0];
                }
            }

        for(int i = 1 ; i < q ; i++){
            if(ans[i] != '?'){
                cout << ' ' << ans[i];
            }
            else{
                if(ansFind[i].size() == 1){
                    cout << ' ' << *ansFind[i].begin();
                }
                else{
                    cout << ' ' << ans[i];
                }
            }
        }
        cout << endl;
	}
}
