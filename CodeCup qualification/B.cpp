/*
ID: One O'Clock
PROG: circular prime
LANG: C++
*/

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

const int Maxn = 1000 * 1000 * 10 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

bool isPrime[Maxn];

string s;


int main()
{
	ios::sync_with_stdio(0);

	FOR(i,2,Maxn)
	{
	    isPrime[i] = 1;
	}
	FOR(i,2,Maxn)
	{
	    if(isPrime[i])
        {
            for(int j = 2*i ; j <Maxn ; j+=i)
            {
                isPrime[j] = 0;
            }
        }
	}


	cin >> s;
    while( !(s[0]=='0' && s.size() == 1 ))
    {
        int sizei = s.size();
        bool flag = 1;
        FOR(j,0,sizei)
        {
            rotate(s.begin(), s.end()-1 , s.end());
            int n = stoi(s,nullptr);
            if(!isPrime[n])
            {
                flag = 0;
            }
        }
        if(flag)
        {
            cout << "circular prime" << endl;
        }
        else
        {
            cout << "non-circular prime" << endl;
        }
        cin >> s;
    }


}

