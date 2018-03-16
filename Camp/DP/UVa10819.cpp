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

vector <PII> in , sum;
int d[100 + 250][10 * 1000 + 250][2 + 5];

int knapsack(int n, int spentMoney , bool isAdded , int budget){

    if(spentMoney > budget + 200){
        return -abMax;
    }

    if(!isAdded && spentMoney > 2000 ){
        budget += 200;
        isAdded = 1;
    }
    if(n < 0){
        if(spentMoney > budget){
            return -abMax;
        }
        else{
            return 0;
        }

    }

    if(isAdded){
        if((sum[n].X + spentMoney) < budget){
            return sum[n].Y;
        }
    }
    else{
        if(((sum[n].X + spentMoney) > 2000) && ((sum[n].X + spentMoney) < (budget + 200))){
            return sum[n].Y;
        }
    }

    if(d[n][spentMoney][isAdded] != -1) return d[n][spentMoney][isAdded];

    return d[n][spentMoney][isAdded] = ( max (knapsack(n-1, spentMoney+in[n].X, isAdded , budget)+in[n].Y , knapsack(n-1,spentMoney,isAdded,budget)));

}


int main() {

	ios::sync_with_stdio(0);
    int n , money;
	while(cin >> money >> n){

        in.clear();
        sum.clear();
        memset(d,-1,sizeof(d));

        int tmpCostSum = 0 , tmpFavorSum = 0;
        for(int i = 0; i < n ; i++){
            int tmpCost, tmpFavor;
            cin >> tmpCost >> tmpFavor;
            in.push_back({tmpCost,tmpFavor});
        }

        sort(in.begin(),in.end());

        for(int i = 0 ; i < n ; i++){
            tmpCostSum += in[i].X;
            tmpFavorSum += in[i].Y;
            sum.push_back({tmpCostSum,tmpFavorSum});
        }
        cout << knapsack(n-1,0,0, money) << endl;

	}
}
