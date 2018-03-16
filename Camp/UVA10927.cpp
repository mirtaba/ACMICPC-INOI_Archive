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
//#define Traxe(X) cerr << #X << " = " << X << endl
//#define _ << " _ " <<

#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;

//ofstream fout ("10927.out");
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

struct capsol{

    point p;
    double hight, dist, ang;

};

bool cmp(capsol a,capsol b)
{
    if( a.ang == b.ang )
        return a.p.x*1ll*a.p.x + a.p.y*1ll*a.p.y < b.p.x*1ll*b.p.x + b.p.y*1ll*b.p.y;
    return a.ang < b.ang;
}

capsol ps[Maxn];
int n;
int main()
{
	ios::sync_with_stdio(0);
    int T = 0;
    while ( (cin >> n) && (n))
    {
        T++;
        double t1, t2, tmp;
        point O(0,0);
        point posX(Maxn,0);
        FOR(i,0,n) {
            cin >> t1 >> t2 >> tmp;
            point tp(t1,t2);
            ps[i].p = tp;
            ps[i].hight = tmp;
            ps[i].ang = atan2(t2,t1);
            vec vecTp(t1,t2);
            ps[i].dist = norm_sq(vecTp);
        }
        sort(ps,ps+n,cmp);
        double localMax = ps[0].hight;
        vector <point> ans;
        FOR(i,1,n)
        {
            if(ps[i].ang != ps[i-1].ang)
            {
                localMax = ps[i].hight;
            }
            else
            {
                if(ps[i].hight <= localMax)
                {
                    ans.pb(ps[i].p);
                }
                else
                {
                    localMax = ps[i].hight;
                }

            }
        }
        sort(ans.begin(),ans.end());
        cout << "Data set " << T << ":" << endl;
        if(ans.size() == 0)
        {
            cout << "All the lights are visible." << endl;
        }
        else
        {
            cout << "Some lights are not visible:" << endl;
            FOR(i,0,(ans.size()-1))
            {
                cout << "x = " << ans[i].x << ", y = " << ans[i].y << ';' << endl;
            }
            cout << "x = " << ans[(ans.size()-1)].x << ", y = " << ans[(ans.size()-1)].y << '.' << endl;
        }




    }

}


