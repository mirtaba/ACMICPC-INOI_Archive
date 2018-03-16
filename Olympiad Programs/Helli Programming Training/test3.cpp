#include <map>
#include <vector>
#include <iostream>
using namespace std;

class star{
public:
star();
bool visited;
map<long, long> way;
};

star::star(){ visited=false; }

void in();
void solve();
void out();

const int Nmax=401;
long N,M,S,T;
star s[Nmax];
typedef vector<long> vec;
vector<vec> crystal;

int main(){
in();
solve();
out();
return 0;
}

void in(){
cin>>N>>M>>S>>T;
for (int i=1; i<=M; i++){
int j, k;
cin>>j>>k;
s[j].way[i]=k;
s[k].way[i]=j;
}
}

void solve(){
vector<long> front;
vector<long> newfront;

front.push_back(S);
s[S].visited=true;

while (!s[T].visited){
vec::const_iterator i;
vec ways;
for (i=front.begin(); i!=front.end(); i++){
map<long, long>::const_iterator j;
for (j=s[*i].way.begin(); j!=s[*i].way.end(); j++)
if (!s[j->second].visited){
newfront.push_back(j->second);
ways.push_back(j->first);
s[j->second].way.erase(j->first);
}
}
crystal.push_back(ways);
front=newfront;
for (i=front.begin(); i!=front.end(); i++)s[*i].visited=true;
newfront.clear();
}
}

void out(){

cout<<(long)crystal.size();

vector<vec>::const_iterator j=crystal.begin();

while(j!=crystal.end()){
vec crys=*j;
cout << endl;
cout<<(long)crys.size();
vec::const_iterator k;
for (k=crys.begin(); k!=crys.end(); k++) cout<<" "<<*k;

j++;
}
}
