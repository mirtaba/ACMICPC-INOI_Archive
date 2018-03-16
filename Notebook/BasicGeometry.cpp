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


bool areParallel(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}
bool areSame(line l1, line l2) {
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}

bool doIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;

    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return true;
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

double rInCircle(double a, double b, double c) {

    double p = (a+b+c)/2;
    double A = sqrt((p)*(p-a)*(p-b)*(p-c));
    double r = (A)/(p);
    return r;
}

double rInCircle(point a, point b, point c) {

    return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

// returns 1 if there is an inCircle center, returns 0 otherwise
// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle

int inCircle(point p1, point p2, point p3, point &ctr, double &r) {

    r = rInCircle(p1, p2, p3);

    if (fabs(r) < EPS)
        return 0;

    line l1, l2;
    double ration = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2, scaleVector(toVector(p2, p3), ration / (1 + ration)));
    pointsToLine(p1, p, l1);

    ration = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scaleVector(toVector(p1, p3), ration / (1 + ration)));
    pointsToLine(p2, p, l2);

    doIntersect(l1, l2, ctr);

    return 1;
}



double rCircumCircle(double a, double b, double c) {

    double p = (a+b+c)/2;
    double A = sqrt((p)*(p-a)*(p-b)*(p-c));
    double R = (a*b*c)/(4*A);
    return R;
}

double rCircumCircle(point a, point b, point c) {

    return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

void pointRotate(point o, point in, double ang ,point &out) {


    out.x = ((in.x - o.x) * cos(ang)) - ((in.y - o.y) * sin(ang)) + o.x;
    out.y = ((in.y - o.y) * cos(ang)) - ((in.x - o.x) * sin(ang)) + o.y;

}
