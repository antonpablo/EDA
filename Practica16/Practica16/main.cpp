#include "lista.h"
#include "diccionario.h"
#include <iostream>
#include <string>
using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
public:
	string alumno;
	int nota;
	Puntuacion(const string& nombre, int puntuacion) : alumno(nombre), nota(puntuacion) {}
};


//metodo que sirve para sumar la puntuacion de las dos listas : lista mal y lista bien
void introDiccionario(Diccionario<string, int> & nota, const Lista<string>& puntos, int suma){
	
	Lista<string>::ConstIterator iterador = puntos.cbegin();
	
	while (iterador != puntos.cend())
	{
		//si en dicionario no contiene la nota se inserta
		if (!nota.contiene(iterador.elem()))
			nota.inserta(iterador.elem(), suma);
		//si en el diccionario esta la nota del alumno se le suma 1 o -1 dependiendo si la lista es de notas bien o notas mal
		else
			nota.busca(iterador.elem()).valor() = nota.busca(iterador.elem()).valor() + suma;

		iterador.next();
	}
}

void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	
	Diccionario<string, int> nota;
	
	//introducir en el diccionario la suma de la nota de cada alumno
	introDiccionario(nota, mal, -1);
	introDiccionario(nota, bien, 1);

	Diccionario<string, int>::Iterator iteradorDic = nota.begin();

	while (iteradorDic != nota.end())
		{
			if (iteradorDic.valor() != 0)
			{
				//si al recorrer el diccionario encontramos notas diferentes a cero, guardamos la Puntuacion
				//y lo colocamos al final de la lista
				Puntuacion p = Puntuacion(iteradorDic.clave(), iteradorDic.valor());
				listado.pon_final(p);
			}
		
		iteradorDic.next();
	}
}

void imprimePuntuaciones(Lista<Puntuacion>& listado) {
	Lista<Puntuacion>::ConstIterator i = listado.cbegin();
	Lista<Puntuacion>::ConstIterator e = listado.cend();
	while (i != e) {
		cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
		i.next();
	}
	cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
	string comienzo;
	while (cin >> comienzo) {
		Lista<string> bien;
		Lista<string> mal;
		Lista<Puntuacion> listado;
		leeResultados(bien, mal);
		califica(bien, mal, listado);
		imprimePuntuaciones(listado);
	}
	return 0;
}