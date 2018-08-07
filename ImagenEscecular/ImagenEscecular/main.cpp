#include <iostream>
using namespace std;

//P{result = ( Vj : 0 <= j < K : v[j] < v[j+1] and
//   )}
int montana(int v[], int &c,int &f) {
  
 int m = (c+f)/2;
 int ind;
 if (f==c+1)
 {
	 if (v[c] > v[f])
		return ind=c;
	 else
		return ind=f;
 }
 else{ //caso recursivo
 if ((v[m] > v v[m+1]) && v[m] > v[m-1])
	 return ind= m;
 else if (v[m] < v[m+1])
	 return ind= montana (v,m+1,f);
 else
	 return ind=montana (v,c,m-1);
 
 }

  
}

bool resuelve() {
    // Leer tamaño del vector
    int num;
    cin >> num;
    if (num == 0)
        return false;  //sale de la funcion si el primer arg es 0

     Leer elementos del vector
    int v[100000];
    for (int i=0; i<n; ++i)
        cin >> v[i];


    int numMontana = montana(num, 0);

   // cout <<numMontana << endl;
    return true;
}

int main() {
   
    	while (resuelve()) ;
    
    return 0;
}

