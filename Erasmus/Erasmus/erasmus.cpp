#include <iostream>
using namespace std;

// { 0 <= n <= long(v) }
// fun SanFermin(int v[], int n) return int r
// Q { max = MAX w : 0 <= w < n : V[w]}
int erasmus(int v[], int n) {
  
	long r = 0;


	return r;
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

    long numErasmus = erasmus(v, n);
    cout << numErasmus << endl;
	
    return true;
}

int main() {
    
    while (resuelve()) ;
    return 0;
}
