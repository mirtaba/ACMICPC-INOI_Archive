#include <bits/stdc++.h>
using namespace  std;


typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define L(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

#define Trace(X) cerr << #X << " = " << X << endl
#define _ << " _ " <<

int main(int argc, char const *argv[])
{
	int a[100];
	for(int i = 0 ; i < 10 ; i++)
		a[i] = i*i;

	for(int i = 0 ; i < 10 ; i++)
		Trace(a[i] _ i);
	return 0;
}
