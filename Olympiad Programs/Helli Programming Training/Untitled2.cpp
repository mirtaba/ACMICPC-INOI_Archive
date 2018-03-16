/*
ID: ghoolha1
PROG: pprime
LANG: C
*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int prime[10000];
bool isp[10000];
int num[11],pnum;

bool isprime(long l)
{
	int i;
	for (i=0;i<pnum;i++)
	{
		if (prime[i]>sqrt(l)) break;
		if (l%prime[i]==0) return false;
	}
	return true;
}
void init()
{
	int i,j;
	memset(isp,true,sizeof(isp));
	for (i=2;i<100;i++)
		if (isp[i])
			for (j=2;j<=10000/i;j++) isp[i*j]=false;
	j=0;
	for (i=2;i<10000;i++)
		if (isp[i])
		{
			prime[j]=i;
			j++;
		}
	pnum=j;
}
int main()
{
	FILE *in=fopen("pprime.in","r"),*out=fopen("pprime.out","w");
	long a,b,temp;
	int i,j,k,l;

	fscanf(in,"%ld%ld",&a,&b);
	fclose(in);
	init();

	//single-digit number
	for (i=5;i<10;i++)
	{
		if (i<a) continue;
		if (i>b)
		{
			fclose(out);
			return 0;
		}
		if (isprime(i)) fprintf(out,"%d\n",i);
	}
	//11
	if (11>=a && 11<=b) fprintf(out,"11\n");
	//3-digit number
	for (i=1;i<=9;i+=2)
		for (j=0;j<=9;j++)
		{
			temp=i*101+j*10;
			if (temp<a) continue;
			if (temp>b)
			{
				fclose(out);
				return 0;
			}
			if (isprime(temp)) fprintf(out,"%ld\n",temp);
		}
	//5-digit number
	for (i=1;i<=9;i+=2)
		for (j=0;j<=9;j++)
			for (k=0;k<=9;k++)
			{
				temp=i*10001+j*1010+k*100;
				if (temp<a) continue;
				if (temp>b)
				{
					fclose(out);
					return 0;
				}
				if (isprime(temp)) fprintf(out,"%ld\n",temp);
			}
	//7-digit number
	for (i=1;i<=9;i+=2)
		for (j=0;j<=9;j++)
			for (k=0;k<=9;k++)
				for (l=0;l<=9;l++)
				{
					temp=i*1000001+j*100010+k*10100+l*1000;
					if (temp<a) continue;
					if (temp>b)
					{
						fclose(out);
						return 0;
					}
					if (isprime(temp)) fprintf(out,"%ld\n",temp);
				}
	fclose(out);
	return 0;
}
