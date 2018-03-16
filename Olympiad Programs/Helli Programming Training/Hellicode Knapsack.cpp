#include <iostream>

using namespace std;

const int Maxn=1E3+25;

int d[Maxn][Maxn],v[Maxn],c[Maxn],N,V;

int main()
{
    ios::sync_with_stdio(0);

    cin >> N >> V;

    for (int i=0;i<N;i++)
    {
        cin >> v[i] >> c[i];
    }
    for (int i=0;i<N;i++)
    {
        d[0][i] = 0;
        for (int j=1;j<=V;j++)
        {
            if (j-v[i]<0)
                d[j][i]=d[j][i-1];
            else
                d[j][i]=max(d[j-v[i]][i-1]+c[i],d[j][i-1]);
        }
    }
    int maxe=0;
    /*for (int i=0;i<N;i++)
    {
        for (int j=1;j<=V;j++)
        {
            cerr << d[j][i] << " ";
        }
        cerr << endl;
    }*/

    for (int j=0;j<=V;j++)
    {
        maxe= maxe<d[j][N-1] ? d[j][N-1] : maxe;
    }
    cout << maxe << endl;
}
