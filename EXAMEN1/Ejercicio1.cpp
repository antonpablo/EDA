#include <iostream>
using namespace std;

bool vector (int v[],int n,int d)
{

	int i=1;
	int cont=1;
	bool sw=true;
	while (i<=n && sw)
	{
	if (v[i]==v[i-1])
			cont++;
	else 
			cont=1;
		
		if ((cont>=d) || (v[i]>v[i-1] && v[i]- v[i-1] > 2))
			sw= false;
		i++;
	}

	return sw;
}

bool resuelve()
{
	int n;
	int d;
	cin>> d;
	cin >> n;
	int v[100000];
	if (n==0)
		return false;

	for (int i=0;i<n;i++)
			cin>>v[i];
	bool sw= vector(v,n,d);

	if (sw)
		cout << "SI" <<endl;
	else
		cout << "NO" << endl;


	return true;
}

int main()
{
	while(resuelve());
	
	return 0;
}
