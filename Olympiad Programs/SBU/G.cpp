
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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int s2i(string str)
{
    stringstream ss;
    int out;
    ss << str;
    ss >> out;
    return out;
}
int len(int a)
{
    int countr = 0;
    if (a == 0) return 1;
    while(a != 0)
    {
        a/=10;
        countr++;
    }
    return countr;
}

int main()
{
	ios::sync_with_stdio(0);
	int max1 = 0,max2 = 0;
	string s;
	cin >> s;
	while(s != "END")
    {
        if(s == "GetFinal")
        {
            FOR(j,0,6-len(max2))
            cout << '0';
            cout << max2 << endl;
        }
        else
        {
            int temp = s2i(s);
            if(max1 < temp)
            {
                max2 = max1;
                max1 = temp;
            }
            else if(temp > max2)
            {
                max2 = temp;
            }
        }
        cin >> s;
    }
	return 0;
}
