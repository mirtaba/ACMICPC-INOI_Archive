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

const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout


double degToRad(double d) {
	return d * PI / 180.0;
}
double radToDeg(double r) {
	return r * 180.0 / PI;
}

struct point {
	double x, y;
	point() {
		x = abMax, y = abMax;
	}
	point(double _x, double _y) {
		x = _x, y = _y;
	}
	bool operator <(point other) const {
		if (fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}
};

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct line {
	double a, b, c;
};

void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) // vertical line
		l.a = 1.0, l.b = 0.0, l.c = -p1.x;
	else {
		l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double) (l.a * p1.x) - p1.y;
	}
}

struct vec {
	double x, y;
	vec(double _x, double _y) {
		x = _x, y = _y;
	}
};

vec toVector(point p1, point p2) {
	return vec(p2.x - p1.x, p2.y - p1.y);
}

vec scaleVector(vec v, double s) {
	return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

double distToLine(point p, point a, point b, point &c) {
	vec AP = toVector(a, p), AB = toVector(a, b);
	double u = dot(AP, AB) / norm_sq(AB);
	//cerr << ' ' << u << endl;
	//cerr << dot(Ap, AB) << endl;
	//cerr << norm_sq(AB) << endl;
	c = translate(a, scaleVector(AB, u));
	return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c) {
	vec AP = toVector(a, p), AB = toVector(a, b);
	//cerr << AB.x << endl;
	double u = dot(AP, AB) / norm_sq(AB);
	//cerr << "  " << u << endl;
	if (u < 0.0) {
		c = point(a.x, a.y);
		return dist(p, a);
	}
	if (u > 1.0) {
		c = point(b.x, b.y);
		return dist(p, b);
	}
	return distToLine(p, a, b, c);
}

double angle(point a, point o, point b) { // returns angle aob in "rad"
    vec oa = toVector(o, a), ob = toVector(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = ( ( ( p1.x - p2.x) * (p1.x - p2.x) ) + ( (p1.y - p2.y) * (p1.y - p2.y) ) );
    double det = r * r / d2 - 0.25;
    if (det < 0.0)
        return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}


int main()
{
	ios::sync_with_stdio(0);
	int n;
	double a;
	while(cin >> n && n) {



        cin >> a;

        point p1(0,0);
        point p2(0,a);
        point p3(a,0);
        point p4(a,a);

        double b,c, distance;
        int cnt = 0;

        for (int i = 0 ; i < n ; i++) {
            bool flag = true;
            cin >> b >> c;
            point tp(b,c);

            distance = dist(tp,p1);
            if(distance > a)
                flag = false;

            distance = dist(tp,p2);
            if(distance > a)
                flag = false;

            distance = dist(tp,p3);
            if(distance > a)
                flag = false;

            distance = dist(tp,p4);
            if(distance > a)
                flag = false;

            if(flag)
                cnt++;
        }
        int s = a*a;
        double ans = ((double)cnt)/n;
        ans *= s;
        cout << setprecision(5) << fixed << ans << endl;

    }

}
