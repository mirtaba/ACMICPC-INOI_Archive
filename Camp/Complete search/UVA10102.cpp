#include <bits/stdc++.h>

using namespace std;

const int Maxn = 100 + 25;
const int abMax = 1 << 28;

#define X first
#define Y second


typedef pair <int,int> PII;

int dx[] = {-1,+1,0,0};
int dy[] = {0,0,-1,+1};

int n;


int dist(PII a , PII b){

    //cerr << a.X << ' ' << a.Y << endl;
    return(abs(a.X-b.X) + abs(a.Y-b.Y));

}


int main()
{
	ios::sync_with_stdio(0);


	while(cin >> n){

        char ch;
        vector <PII> one , three;
		for(int i = 0; i < n ; i++){
			for (int j = 0; j < n; j++){

				cin >> ch;
				int tp = ch - '0';
				if(tp == 1){

                    one.push_back({i,j});
				}else if (tp == 3){

                    three.push_back({i,j});
				}
			}
		}

		int ans = 0;

		for(int i = 0; i < one.size() ; i++){
            int localMax = abMax;
			for (int j = 0; j < three.size(); j++){

                localMax = min(localMax,dist(one[i],three[j]));

			}
			ans = max(ans,localMax);
		}
		cout << ans << endl;


	}


	return 0;
}
