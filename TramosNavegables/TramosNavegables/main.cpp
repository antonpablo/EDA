#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int tramoNavegable(const Arbin<int> &cuenca, int &navegable)
{
	int izquierda = 0;
	int derecha = 0;
	int suma = 0;

	if (!cuenca.hijoIz().esVacio() || !cuenca.hijoDer().esVacio())
	{
	//cuando el hijo no es vacio, llama a caso recursivo con ese hijo
	if (!cuenca.hijoIz().esVacio())
		izquierda = tramoNavegable(cuenca.hijoIz(), navegable);
	if (!cuenca.hijoDer().esVacio())
		derecha = tramoNavegable(cuenca.hijoDer(), navegable);

	//resto el caudal de la raiz, y sumo los caudales de sus hijos
	suma = cuenca.raiz() + izquierda + derecha;

	//si la suma es menor que cero, ponemos el caudal a cero. 
	//si la suma es mayor o igual que tres le sumamos 1 xq es tramo navegable
	if (suma < 0)
		suma = 0;
	else if (suma >= 3)
		navegable = navegable + 1;
	
	}
	else//Hoja del arbol, sumamos 1 al caudal
		suma = 1;

	return suma;
}

int numeroTramosNavegables(const Arbin<int>& cuenca) {

	int navegable = 0;
	int ultimoNavegable = tramoNavegable(cuenca, navegable);
	
	//no contar el ultimo tramo del arbol
	if (ultimoNavegable >= 3)
		navegable = navegable - 1;

	return navegable;
}


Arbin<int> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
				  int raiz;
				  in >> raiz;
				  in >> c;
				  return Arbin<int>(raiz);
	}
	case '(': {
				  Arbin<int> iz = leeArbol(in);
				  int raiz;
				  in >> raiz;
				  Arbin<int> dr = leeArbol(in);
				  in >> c;
				  return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> cuenca;
	while (cin.peek() != EOF)  {
		cout << numeroTramosNavegables(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}