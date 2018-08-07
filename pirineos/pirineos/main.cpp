#include <iostream>
#include <stdlib.h>
using namespace std;


void torres(int k,int n,int &numazules, int &numverdes,int &numrojos,int na,int nv,int nr, int sol[], bool &sw)
{
	for(int i=0; i<3;i++)
	{
		if (((i==2) && (sol[k-1]!=2) && ((numverdes < numazules) && (numverdes <nv))) || (i==1 && abs(numrojos) < nr) ||(i==0 && numazules<na))
		{
			sol[k]=i;
			if (i==2)
				numverdes++;
			if (i==1)
				numazules++;
			if (i==0)
				numrojos++;
			
			if ((k == n-1) && (numrojos < numverdes+numazules))
			{
				for(int j=0;j<n;j++)
				{
					if (sol[j]==0)
					cout << "Rojo" << " ";
					if (sol[j]==2)
						cout << "Verde" << " ";
					if (sol[j]==1)
						cout << "Azul" << " ";
				}
				cout <<endl;
				sw=true; 
			}
			else if (k<n-1)
				torres(k+1,n,numazules,numverdes,numrojos,na,nv,nr,sol,sw);
		
		if (sol[k]==2)
			numverdes--;
		if (sol[k]==1)
			numazules--;
		if (sol[k]==0)
			numrojos--;

			
		}
	}
}

bool resuelve()
{
	int n;
	int sol[10000];
	int k=1;
	int numv=0;
	int numa=0;
	int numr=1;
	cin >> n;
	if (n==0)
		return false;
	
	int v;
	int a;
	int r;
	cin >> a;
	cin >> r;
	cin >> v;
	sol[0]=0;
	bool sw=false;
	torres(k,n,numv,numa,numr,a,v,r,sol,sw);
	if (!sw)
		cout <<"SIN SOLUCION"<< endl;
	return true;
}

int main()
{
	while(resuelve());
	
	return 0;
}