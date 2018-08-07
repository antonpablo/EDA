#include <iostream>

using namespace std;

// { 0 <= n <= long(v) }
// fun mirador(int v[], int n) return int r
// Q { r = SUM w : 0 <= w < n : mirador (v,n,w)}
//mirador(v,n,w)  { V x: w < x < n : V[w] > V [x] } 


bool ordenado(int v[], int c,int f) {
  int m=(c+f)/2;
   if (c+1==f)
   {
   	 if (v[c]>v[f] && v[f] - v[c] > 1)
   	 	return false;
   }
	else
	{
		ordenado(v,c,m);
		ordenado(v,m,f);
	}
	
  
}

bool resuelve()
{
	int n;
	cin >> n;
	int v[100000];
	if (n==0)
		return false;

	for (int i=0;i<n;i++)
			cin>>v[i];
	
	bool sw= ordenado(v,0,n-1);

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
