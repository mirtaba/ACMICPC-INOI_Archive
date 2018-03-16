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

LL n , k , tmp ;
vector <LL> in;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> k;
    FOR(i,0,n)
    {
        cin >> tmp;
        in.pb(tmp);
    }
    sort(in.begin(),in.end());
    if((in[n-1]-in[0])<2)
    {
        cout << 0 << endl;
        return 0;
    }

    int i = 0;
    int j = n-1;
    bool f1 = 0 , f2 = 0;
    while(in[i] == in[i+1] && i <(n-1))
        i++;
    while(in[j] == in[j-1] && j > 0)
        j--;
    int c1 = (n-j) * (in[j]-in[j-1]);
    int c2 = (i+1) * (in[i]-in[i+1]);
    if(c1 > c2)
    {
        f1 = 1;
    }
    else
    {
        f2 = 1;
    }
    int ccc = abs(c1-c2);
    while(true)
    {
        while((in[i] == in[i+1] && i <(n-1)) && (f2 && i < (j-1)))
            i++;
        while((in[j] == in[j-1] && j > 0) && (f1 && j > (i+1) ))
            j--;
        int c1 = (n-j) * (in[j]-in[j-1]);
        int c2 = (i+1) * (in[i]-in[i+1]);
        if(f1 && !f2)
        {

            if(k<c1)
            {
                int t1 = k/(n-j);
                int t2 = k/(i+1);

                cout << max( (in[j]-in[i]-t1-t2) , 0LL) << endl;
                break;
            }
            k-=c1;
            j--;
            if(ccc > c1)
            {
                ccc -=c1;
            }
            else
            {
                ccc = c1 - ccc;
                f1 = 0;
                f2 = 1;
            }
            continue;
        }
        if(f2 && !f1)
        {

            if(k<c2)
            {
                int t1 = k/(n-j);
                int t2 = k/(i+1);

                cout << max( (in[j]-in[i]-t1-t2) , 0LL) << endl;
                break;
            }
            k-=c2;
            i++;
            if(ccc > c2)
            {
                ccc -=c2;
            }
            else
            {
                ccc = c2 - ccc;
                f1 = 1;
                f2 = 0;
            }
            continue;
        }
    }


}
