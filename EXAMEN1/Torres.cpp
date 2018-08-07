#include <iostream>
#include <stdlib.h>
using namespace std;


void torres(int k,int n,int &numazules, int &numverdes,int &numrojos,int na,int nv,int nr, int sol[], bool &sw)
{

	for(int i=0; i<3;i++)
	{
		if (((i==2) && (sol[k-1]!=2) && (numverdes < numazules && numverdes <nv)) || (i==1 && numrojos < nr) ||(i==0 && numazules<na))
		{
			sol[k]=i;
			if (i==2)
				numverdes++;
			if (i==1)
				numazules++;
			if (i==0)
				numrojos++;
			
			if ((k < n-1) && (numrojos < numverdes+numazules))
			{
				//cout solucuion
				sw=true; //hay solucion
			}
			else (k<n-1)
				torres(k+1,n,numazules,numverdes,numrojos,na,nv,nr,sol[],sw);
			if (sol[i]== 2)

			
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
	int rep[10000];
	int sol[10000];
	if (n==0 || d==0)
		return false;
	int k=1;
	sol[0]=e;
	rep[0]=1;
	torres(1,n,d,e,sol);
	return true;
}

int main()
{
	while(resuelve());
	
	return 0;
}}
