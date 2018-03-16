#include <iostream>
#include <complex>
#define X real()
#define Y imag()
#define double long double
using namespace std;
typedef complex<double> point;
double cross(const point& p,const point& q){
	return p.X*q.Y-p.Y*q.X;
}
point read_point(){
	double x,y;
	cin>>x>>y;
	return point(x,y);
}
double eps=1e-4;
double PI=atan((double)1)*4;
bool is_int(double d){
	return abs(d-floor(d+eps))<eps;
}
int main(){
	cout<<fixed;
	cout.precision(6);
	point A=read_point();
	point B=read_point();
	point C=read_point();
	double S=abs(cross(B-A,C-A));
	double a=abs(B-C);
	double b=abs(C-A);
	double c=abs(B-A);
	double R=a*b*c/(2*S);
	double C_ang=abs(arg((B-C)/(A-C)));
	double B_ang=abs(arg((C-B)/(A-B)));
	for (int den=3;den<=100;++den){
		if (is_int(B_ang*den/PI) && is_int(C_ang*den/PI)){
			cout<<sin(2*PI/den)*R*R*den/2<<endl;
			return 0;
		}
	}
	return 0;
}
