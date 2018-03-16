 #include <iostream>
#include <cmath>

using namespace std;

int main()
{

int sx1,sx2,sy1,sy2,bx1,bx2,by1,by2;

cin >> sx1>>sy1>>sx2>>sy2>>bx1>>by1>>bx2>>by2;

if(sx1>sx2)
{
int b=sx1;
sx1=sx2;
sx2=b;
}

if(sy1>sy2)
{
int b=sy1;
sy1=sy2;
sy2=b;
}

if(bx1>bx2)
{
int b=bx1;
bx1=bx2;
bx2=b;
}

if(by1>by2)
{
int b=by1;
by1=by2;
by2=b;
}


int x1,x2,y1,y2;

x1=bx1;
if(sx1>bx1)
{
x1=sx1;
}

x2=bx2;
if(sx2<bx2)
{
x2=sx2;
}

y1=by1;
if(sy1>by1)
{
y1=sy1;
}

y2=by2;
if(sy2<by2)
{
y2=sy2;
}

int x= x2-x1;
int y= y2-y1;

if(x>0&&y>0)
cout << x*y;
else
cout << 0;
return 0;
}
