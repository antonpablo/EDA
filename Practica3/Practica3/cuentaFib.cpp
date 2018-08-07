#include <iostream>
using namespace std;


bool resuelve() {
    int numero;
    cin >> numero;
    if (numero <= 0)
        return false;  
	int v[10000];
	int suma=0;
	int num=0;
	int n=0;
    while (numero>0)
	{
		v[n]= numero % 10;
		n++;
		suma= suma + numero % 10; 
		numero =numero / 10;
	}

	for(int i=n-1;i>=0;i--)
	{
		cout << v[i];
		if (i>0)
			cout <<" + ";
	}


	cout <<" = "<< suma << endl;
	return true;
}

int main() {
   
    	while (resuelve()) ;
    
    return 0;
}

