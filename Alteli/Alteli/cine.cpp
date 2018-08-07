
#include <iostream>    // cin, cout
#include <algorithm>  // max
using namespace std;

#define MAX 10000


bool cine(int v[], int n, int &gente) {
	bool ordenado = true;
	int cambio = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] % 2 == 0 && ordenado) {
			gente++;
		}
		else if(v[i] % 2 != 0 ){
			ordenado = false;
		}
		else
			return false;
	}
	return true;
}


bool resuelve() {
    // Leer tamaño del vector
    int n;
    cin >> n;
    if (n == 0)
        return false;  //sale de la funcion si el primer arg es 0

    // Leer elementos del vector
    int v[MAX];
    for (int i=0; i<n; ++i)
        cin >> v[i];

    return cine;
}

int main() {
      // Leer tamaño del vector
    int n;
    cin >> n;
	if (n==2)
		while (resuelve()) ;
      
   
    return 0;
}
