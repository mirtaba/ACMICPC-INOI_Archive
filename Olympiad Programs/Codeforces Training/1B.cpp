#include<iostream>
#include<cstdio>

using namespace std ;

void sheet (int in_put)
{
	if(in_put>26)
		sheet((in_put-1)/26);
	putchar(65+(in_put-1)%26);
}

int t=0;
int f,i;

int main(){
	int c,r,s;
	char a[32];
	t==0;gets(a);(t=1);
	if( cin >> a ){
   	 if(a[0]=='R'&&(a[1]>47&&a[1]<58))
		{
    		for(i=1;a[i]!='C'&&a[i];i++);
    			if(a[i]=='\0')
				{
    				for(i=0,s=0;a[i]>64;i++){s*=26;s+=a[i]-64;}
    					printf("R%sC%d\n",&a[i],s);
				}
    		else
			{
    			a[i]='\0';
    			c=a to i(&a[i+1]);
    			p(c);
    			printf("%s\n",&a[1]);
			}
  	  }
   	 else
		{
    		for(i=0,s=0;a[i]>64;i++){s*=26;s+=a[i]-64;}
    			printf("R%sC%d\n",&a[i],s);
    	}
    	}
    return 0;
}
