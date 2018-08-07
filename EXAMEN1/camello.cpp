#include <iostream>
#include <stdlib.h>
using namespace std;

void camello(int k,int n,int &p1, int &p2, int p1_ini, int p2_ini, int v[],int w[],int sol[],int solmejor[],int beneficio, int maxBeneficio)
{

	for(int i=0; i<3;i++)
	{
		if ((i==1) && (w[k]<=p1))
		{
			sol[k]=i;
			p1=p1-w[k];
			beneficio=beneficio+v[k];
		}
		if ((i==2) && (w[k]<=p2))
		{
			sol[k]=i;
			p2=p2-w[k];
			beneficio=beneficio+v[k];
		}
		if (i==0)
			sol[k]=i;

		if ((k==n-1) && (( abs((p1_ini-p1)-(p2_ini-p1)))<=(5*p1_ini-p2_ini)/100))
		{
			if (maxBeneficio < beneficio)
			{
				maxBeneficio=beneficio;
				for (int i=0;i<n;i++)
				 solmejor[i]=sol[i];
			}

		}else if (k < n-1)
				camello(k+1,n,p1,p2,p1_ini,p2_ini,v,w,sol,solmejor,beneficio, maxBeneficio);

			
		if (sol[k]==2)
		{
			p2=p2+w[k];
			beneficio=beneficio-v[k];
		}
		if (sol[k]==1)
		{
			p1=p1+w[k];
			beneficio=beneficio-v[k];
		}
			
	}
}

bool resuelve()
{
	int n;
	int d;
	int e;
	cin >> n;
	cin>> d;
	cin>> e;
	int rep[10];
	int sol[10];
	if (n==0)
		return false;

	for (int i=0;i<n;i++)
	{
		rep[i]=0;
	}
	int k=1;
	sol[0]=e;
	rep[0]=1;
	//pdivertidos(k,n,d,e,sol,rep);
	return true;
}

int main()
{
	while(resuelve());
	
	return 0;
}
