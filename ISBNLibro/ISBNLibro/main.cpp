#include <iostream>

using namespace std;

// { 0 <= n <= long(v) }
// fun mirador(int v[], int n) return int r
// Q { r = SUM w : 0 <= w < n : mirador (v,n,w)}
//mirador(v,n,w)  { V x: w < x < n : V[w] > V [x] } 


int ISBN(int num, int pos,int acum) {
  
	if (num>10)
	{
		ISBN(num/10,pos,acum);
		if (pos%2==1)
		{
			acum=acum+num%10;
			pos++;
		}else
		{
			acum=acum+(num%10)*3;
			pos++;
		}
	}
	else
	{
		acum=acum + (num%10)*3;
		pos=pos+1;
	}
	return acum;
}

bool resuelve() {
    // Leer tamaño del vector
    int n;
    cin >> n;
    if (n == 0)
        return false;  //sale de la funcion si el primer arg es 0

    // Leer elementos del vector
   // int v[100000];
   // for (int i=0; i<n; ++i)
//cin >> v[i];


    int libro = ISBN(n,1,0);

    cout <<libro << endl;
    return true;
}

int main() {
   
    	while (resuelve()) ;
    
    return 0;
}

