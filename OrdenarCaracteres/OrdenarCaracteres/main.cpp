#include <iostream>
#include <string>
#include "pila.h"
using namespace std;

//comprobacion si es o no una pareja valida
bool encontrar(char i, char f){
	
	if ((i=='(' && f==')') || (i=='[' && f==']') || (i=='{' && f=='}'))
		return true;
	else 
		return false;
	
}

//utilizo el TAD pila para poder apilar el ultimo que entra
bool esEquilibrada(const string& cadena) {
	Pila<char> p;
	int i=0;
	bool sw=true;
	while(i<cadena.length() && sw)
	{
		//si es una parentesis que se abre apilamos
		if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{')
			p.apila(cadena[i]);
		//si es un parentesis que se cierra comprobamos si el anterior es igual desapilamos
		else if (cadena[i] == ')' || cadena[i] == ']' ||  cadena[i]== '}')
		{
			//si la cima esta vacia o no es una pareja devuelvo false
			if (p.esVacia() || !encontrar(p.cima(), cadena[i]))
				sw= false;
			else
				p.desapila();
		}

		i++;
	}
	if (!p.esVacia()) sw =false;// comprobacion por si la pila no esta vacia entonces devuelvo false
	return sw;

}


int main() {
	string cadena;
    while(getline(cin, cadena)) {
      if(esEquilibrada(cadena))
        cout << "EQUILIBRADA" << endl;
      else
        cout << "NO_EQUILIBRADA" << endl;		  
	}
	return 0;
}	