/**
Este programa lee árboles de la entrada estándar,
codificados de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con
v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
con I la codificación del hijo izquierdo,
v el valor de la raíz, y D la codificación
del hijo derecho.
Para cada árbol leído, escribe en la salida estándar
el número de nodos singulares de dicho árbol.

Algunos casos representativos:

#
[0]
[5]
(([4]3[-3])1[-4])

-El primero representa el árbol vacío. Al no tener nodos,
un árbol vacío tiene 0 nodos sigulares.
-El segundo representa un árbol con un único nodo, cuyo valor
es 0. Dicho nodo es singular, ya que: (i) como no tiene
ascestros, la suma de los ancestros es 0, (ii) como no
tiene descendientes, la suma de los descendientes es 0.
-El tercero representa otro árbol con un único nodo, cuyo
valor es 5. Por la misma razón que en el segundo ejemplo,
este nodo es singular.
-El cuarto representa el siguiente árbol:

1
/  \
3  -4
/ \
4  -3

Este árbol tiene 2 nodos sigulares: la raíz, y la raíz del hijo
izquierdo.

Por tanto, la salida del programa para estos casos será:

0
1
1
2

*/
#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/**
COMPLEJIDAD: Explica aquí justificadamente cuál es la complejidad de
esta función
***A COMPLETAR***
La complejidad del algoritmo es de orden O(n log n), se llega a recorrer el arbol entero, ademas de
el tratamiento necesario a la vuelta del caso recursivo para saber si es singular o no.
*/
int sumar_arbol(Arbin<int> arbol, int sumaAnterior, int &singular) {
	// A IMPLEMENTAR
	int sumaHijos;
	
	if (!arbol.esVacio())
	{  //llamada recursiva por el hijo derecho e hijo izquierdo, sumando la raiz y el anteroir.
		//sumaAnterior no se puede hacer por referencia para que cada rama sea independiente
		int sumaIzq = sumar_arbol(arbol.hijoIz(), sumaAnterior + arbol.raiz(), singular);
		int sumaDer = sumar_arbol(arbol.hijoDer(), sumaAnterior + arbol.raiz(), singular);

		//sumamos los 2 hijos, y miramos si es singular.
		sumaHijos = sumaIzq + sumaDer;
		if (sumaHijos == sumaAnterior)
			singular++;

		sumaHijos = sumaHijos + arbol.raiz();
	}	
	else //cuando el arbol es vacio la suma de sus hijos es 0
		sumaHijos = 0;

	return sumaHijos;
	
}
unsigned int numero_singulares(Arbin<int> a) {
	// A IMPLEMENTAR
	int singular = 0;
	sumar_arbol(a, 0 ,singular);	
	return singular;
}


Arbin<int> lee_arbol(istream& in) {
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
				  Arbin<int> iz = lee_arbol(in);
				  int raiz;
				  in >> raiz;
				  Arbin<int> dr = lee_arbol(in);
				  in >> c;
				  return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		cout << numero_singulares(lee_arbol(cin));
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}
