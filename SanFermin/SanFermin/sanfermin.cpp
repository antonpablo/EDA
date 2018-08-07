#include <iostream>
using namespace std;

// { 0 <= n <= long(v) }
// fun SanFermin(int v[], int n) return int r
// Q { max = MAX w : 0 <= w < n : V[w]}
int SanFermin(int v[], int n) {
  
	int max = 0;
	int i=0;
//I  { ( 0 <= i < n ) and 
//max = MAX w : 0 <= w < n : V[w] }
//n-i
	while (i<n)
	{
		if (v[i] > max) 
			max = v[i];
		++i;
	}
		
		
	
	return max;
}

bool resuelve() {
    // Leer tamaño del vector
    int n;
    cin >> n;
    if (cin <= 0 || !cin)
    	return false;
    	  	// Leer elementos del vector
    int v[100000];  
	for (int i=0; i<n; ++i)
        cin >> v[i];

    int numMaximo = SanFermin(v, n);
    cout << numMaximo << endl;
	
    return true;
}

int main() {
    
    while (resuelve()) ;
    return 0;
}


