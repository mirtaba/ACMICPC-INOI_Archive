#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0);
	int n , tp;
	cin >> n;
	if(n == 1){
        char ch;
        cin >> ch;
        cout << '=' << endl;
        return 0;
	}
	double tmp = 1;
	double ans = 0;
	for(int i = 0 ; i < n-1 ; i++){

        tmp *=2;

        char ch;
        cin >> ch;
        if(ch == 'S'){
            ans-=tmp;
        }
        else{
            ans+=tmp;
        }

	}
	char ch;
	cin >> ch;

    if(ans > 0){
        cout << "W" << endl;
    }
    else{
        cout << "S" << endl;
    }

}
