#include <iostream>
using namespace std;


// { 0 <= n <= long(v) }
// fun moda(int v[], int n) return int m
// Q { max = MAX w : 0 <= w < n : apariciones () >= apariciones }
int moda(int v[], int n) {
  
	int m = 0;
	int aux;
	int frecuencia=0;
    int frecuencia_moda=0;
    int moda=-1;
    
//I  { ( 0 <= i < n ) and 
//max = MAX w : 0 <= w < n : V[w] }
//n-i
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i;j++){
			if(v[j]>v[j+1]){
	            aux=v[j];
	            v[j]=v[j+1];
	            v[j+1]=aux;
					}
		}
	}



	frecuencia=0;
	frecuencia_moda=0;
	moda=-1;

	for(int i=0;i<n-1;i++){
		if(v[i]==v[i+1])
		{
			
                if(++frecuencia>frecuencia_moda){
                       frecuencia_moda=frecuencia;
                       moda=v[i];
				}
                                                        
                else frecuencia=0;
		}	
	}
 return moda;
}

bool resuelve() {
    // Leer tamaño del vector
    int n;
    cin >> n;
    if (n == 0)
        return false;  

  
    int v[100000];
    for (int i=0; i<n; ++i)
        cin >> v[i];


    int numMaximo = moda(v, n);

    cout << numMaximo << endl;
    return true;
}

int main() {
    
    while (resuelve());
    return 0;
}


