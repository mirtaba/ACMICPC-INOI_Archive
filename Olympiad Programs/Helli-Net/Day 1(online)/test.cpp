#include <iostream>
#include <string>

using namespace std;

short m,n,mark[100][100];
bool map[100][100];
int CurrentID=1;
double MaxMM=0.0;

void Explore(int x,int y)
{
	if(map[x][y]&&mark[x][y]==0)
	{
		mark[x][y]=CurrentID;
		Explore(x+1,y);
		Explore(x-1,y);
		Explore(x,y+1);
		Explore(x,y-1);
	}
}

int Mohit(int x, int y)
{

	int cmoh=0;
	if(mark[x+1][y]==0)
	{
		cmoh++;
	}
	if(mark[x-1][y]==0)
	{
		cmoh++;
	}
	if(mark[x][y+1]==0)
	{
		cmoh++;
	}
	if(mark[x][y-1]==0)
	{
		cmoh++;
	}
	return	cmoh;
}

int main()
{
	cin >> m >> n;

	for(int i=0;i<m;i++)
	{

		string t;
		cin >> t;
		for(int j=0;j<n;j++)
		{
			if(t[j]=='0')
			{
				map[i][j]=false;
			}
			else
			{
				map[i][j]=true;
			}

			mark[i][j]=0;
		}

	}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(map[i][j]&&mark[i][j]==0)
			{
				Explore(i,j);
				CurrentID++;
			}
		}
	}

	for(int CId=1;CId<=CurrentID;CId++)
	{
		int moh=0,mas=0;

		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(mark[i][j]==CId)
				{
					mas++;
					moh+=Mohit(i,j);
				}
			}
		}

		double MM=(double)mas/(double)moh;
		if(MM>MaxMM)
		{
			MaxMM=MM;
		}

	}

	cout.precision(6);

	cout << fixed << MaxMM << endl;

	return 0;
}
