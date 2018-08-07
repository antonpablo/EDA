#include <iostream>
#include <>
using namespace std;

void pdivertidos(int k,int n,int d,int e, int sol[],int rep[])
{

	for(int i=sol[k-1]; i<=sol[k-1]+1;i++)
	{
		if (rep[i-e]<d)
		{
			sol[k]=i; //i del for
			rep[i-e]++; //marcaje repetidos [0-n]
		
			if (k==n-1)
			{
				for (int i=0;i<n;i++)
				{
					cout << sol[i] <<" ";
				}
				cout << endl;
			}
			else 
				pdivertidos(k+1,n,d,e,sol,rep);
			
			rep[i-e]--;
		}
	}
}

bool resuelve()
{
	int n;
	int d;
	int e;
	cin>> n;
	cin>> d;
	cin>> e;
	int rep[1000000];
	int sol[1000000];
	if (n==0 || d==0 )
		return false;

	for (int i=0;i<n;i++)
	{
		rep[i]=0;
	}
	int k=1;
	sol[0]=e; //pasar la i del for dond empieza
	rep[0]=1; //marcaje de repetidos
	pdivertidos(k,n,d,e,sol,rep);
	return true;
}

int main()
{
	while(resuelve());
	
	return 0;
}
