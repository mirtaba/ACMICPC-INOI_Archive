/*
ID: ghoolha1
PROG: greetings
LANG: C++
*/
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <cmath>
#include <fstream>
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
typedef pair <double,double> PDD;

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout


double dist (PDD a , PDD b){
    double xDiff = a.X - b.X;
    double yDiff = a.Y - b.Y;
    return sqrt((xDiff*xDiff)+(yDiff*yDiff));
}

double dot (PDD a ,PDD b) {
    return  ((a.X*b.X)+(a.Y*b.Y));
}


double distToLine(PDD p, PDD a, PDD b, PDD &c) {

    PDD apVec = {p.X-a.X , p.Y-a.Y};
    PDD abVec = {b.X-a.X , b.Y-a.Y};

    double u = (dot(apVec, abVec) / ((abVec.X*abVec.X)+(abVec.Y*abVec.Y)));
    //cerr << ' ' << u << endl;
	//cerr << dot(apVec, abVec) << endl;
	//cerr << ((abVec.X*abVec.X)+(abVec.Y*abVec.Y)) << endl;
    PDD acVec = {abVec.X * u , abVec.Y* u};
    c = {a.X + acVec.X , a.Y + acVec.Y};
    return dist(p,c);
}

double distToLineSegment(PDD p, PDD a, PDD b, PDD &c) {
    PDD apVec = {p.X-a.X , p.Y-a.Y};
    PDD abVec = {b.X-a.X , b.Y-a.Y};
    //cerr << p.X-b.X << endl;
    double u = dot(apVec, abVec) / ((abVec.X*abVec.X)+(abVec.Y*abVec.Y));
    //cerr << "  " << u << endl;
    if (u < 0.0) {
        c = {a.X, a.Y};
        return dist(p, a);
    }
    if (u > 1.0) {
        c = {b.X, b.Y};
        return dist(p, b);
    }
    return distToLine(p, a, b, c);
}

int N;

int main() {
	ios::sync_with_stdio(0);
    PDD M;
    while(cin >> M.X >> M.Y) {
        cin >> N;
        PDD p1 ,p2 ;
        cin >> p1.X >> p1.Y ;
        if (N == 0) {
            cout << dist(M,p1) << endl;
            continue;
        }
        double ans = abMax;
        PDD ansPoint;
        FOR(i,0,N) {
            cin >> p2.X >> p2.Y ;
            PDD tmp;
            double tp = distToLineSegment(M,p1,p2,tmp);
            //cerr << tp << endl;
            if(ans > tp) {
                ans = tp;
                ansPoint = tmp;
            }
            p1.X = p2.X;
            p1.Y = p2.Y;
        }
        cout << setprecision(4) << fixed << ansPoint.X << endl;
        cout << ansPoint.Y << endl;

    }

}

