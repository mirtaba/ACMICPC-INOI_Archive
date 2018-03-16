//In the name of ALLAH
//Code By JahanaraCo
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

ifstream fin("rect.txt");
#define cin fin

const int MAXN = 10000;
const int delta = 300017;
int X[MAXN][2], Y[MAXN][2], D[MAXN][4], tmp[4];
int dir[4][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};

bool inside(int x, int y, int R){
  if(X[R][0] < x and x < X[R][1])
    if(Y[R][0] < y and y < Y[R][1])
      return true;
  return false;
}

int main(){
  for(int i=0;i<MAXN;i++){
    char c;
    cin>>c>>X[i][1]>>c>>Y[i][1]>>c>>c>>c>>X[i][0]>>c>>Y[i][0]>>c;
  }

  for(int i=0;i<MAXN;i++)
    for(int j=0;j<MAXN;j++){
      int ted = 0, pos;
      for(int k=0;k<4;k++){
	int x = X[i][dir[k][0]];
	int y = Y[i][dir[k][1]];
	if(inside(x, y, j)){
	  ted++; pos = k;
	}
      }
      if(ted == 1)
	D[j][pos]++;
    }

  long long ans = 0;
  for(int i=0;i<MAXN;i++){
    long long res = 1;
    for(int j=0;j<4;j++)
      (res *= D[i][j]) %= delta;
    (ans += res) %= delta;
  }
  cout<<ans<<endl;
  return 0;
}
