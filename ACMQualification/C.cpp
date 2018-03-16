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

map <string , int> tal;
int talCnt = 0;

int dis[Maxn];

vector <int> G[Maxn];
vector <int> consider[Maxn];
bool mark[Maxn];

int numbFind(string s){

    if(tal.find(s) == tal.end()){
        tal[s] = talCnt;
        talCnt++;
        return (talCnt-1);
    }
    else{
        return tal[s];
    }

}

int n;

int main() {
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	for(int tt = 0 ; tt < T ; tt++){
        tal.clear();
        cin >> n;
        talCnt = n;
        for(int i = n ; i < n+100; i++){
            consider[i].clear();
        }
        for(int i = 0 ; i < n ; i++){
            G[i].clear();
            int tmp = 0;
            cin >> tmp;
            for(int j = 0 ; j < tmp; j++){
                string s;
                cin >> s;
                G[i].push_back(numbFind(s));
                consider[numbFind(s)].push_back(i);
            }
        }
        for(int i = n ; i < talCnt;i++){
            //cerr << i << " : ";
            G[i].clear();
            int k = 0;
            bool flag = false;
            //sort(consider[i].begin(),consider[i].end());
            for(int j = 0 ; j <n;j++){
                if(!flag && j == consider[i][k]){
                    k++;
                    if(k == consider[i].size()){
                        flag = true;
                    }
                }
                else{
                    G[i].push_back(j);
                    //cerr << j << ' ';
                }
            }
            //cerr << endl;
        }

        queue <int> q;
        q.push(0);

        memset(mark,0,sizeof(mark));
        mark[0] = 1;

        memset(dis,-1,sizeof(dis));
        dis[0] = 0;

        while(q.size()){

            int u = q.front();
            q.pop();

            for(int i = 0 ; i < G[u].size();i++){
                int v = G[u][i];
                if(!mark[v]){
                    q.push(v);
                    mark[v] = true;
                    dis[v] = dis[u] + 1;
                }
            }

        }
        if(dis[numbFind("Un-Shuffle")] == -1){
            cout << "Puff, it's gone" << endl;
        }
        else{
            cout << (dis[numbFind("Un-Shuffle")]-1)/2 << endl;
        }
	}
}
