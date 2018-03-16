
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

const int Maxn = 1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout



typedef pair<int, int> IndexValue;

struct IndexValueCompare{
    inline bool operator() (const IndexValue &one, const IndexValue &another){
        return one.second < another.second;
    }
};

vector<int> LIS(const vector<int> &sequence)
{
    vector<int> parent(sequence.size());
    set<IndexValue, IndexValueCompare> s;
    for(int i = 0; i < sequence.size(); ++i)
    {
        IndexValue iv(i, sequence[i]);
        if(i == 0)
        {
            s.insert(iv);
            continue;
        }
        set<IndexValue, IndexValueCompare> :: iterator index = s.lower_bound(iv);

        if(index != s.end())
        {
            if(sequence[i] < sequence[index->first])
            {
                if(index != s.begin())
                {
                    parent[i] = (--index)->first;
                    index++;
                }
                s.erase(index);
            }
        }
        else
        {
            parent[i] = s.rbegin()->first;
        }
        s.insert(iv);
    }
    vector<int> result(s.size());
    int index = s.rbegin()->first;
    for( set<IndexValue, IndexValueCompare> :: reverse_iterator iter = s.rbegin(); iter != s.rend(); index = parent[index], ++iter){
        result[distance(iter, s.rend()) - 1] = sequence[index];
    }
    return result;
}


bool mark[Maxn] , markch[Maxn] ;
string st , ans;
int n;
vector <int> in;
vector <int> out;

int main()
{
    cin >> n;
    FOR(I,0,n)
    {
        cin >> st;
        MEM(mark,0);
        MEM(markch,0);

        while(true)
        {
            in.clear();
            FOR(i,0,st.size())
            {
                if(markch[st[i]] == 0 )
                {
                    in.pb(st[i]);
                }
                else
                {
                    //st.erase(st+i,st+i+1);
                }
            }
            if(in.size() == 0)
            {
                break;
            }
            out = LIS(in);
            int t = st.size() - 1;
            for(int i = out.size()-1 ; i >=0 ; i--)
            {
                //cerr << (char)out[i] ;
                while(st[t]!= (out[i]) )
                {
                    t--;
                }
                markch[st[t]] = 1;
                mark[t] = 1;
            }
            //cerr << endl;
        }
        ans = "";
        FOR(i,0,st.size())
        {
            if(mark[i] == 1)
            {
                ans+=st[i];
            }
        }
        cout << ans << endl;
    }
}
