#include "Racional.h"
#include <cmath>


//contructor sin argumentos
Racional::Racional(){
	_numer = 0;
	_denom = 1;
}

//contructor con argumentos
Racional::Racional(long num, long den){
	
	if (den != 0) {
		_numer = num;
		_denom = den;
		reduce();
	}
	else
		throw EDenominadorCero();
}


  
  // Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

 // Metodos privados
void Racional::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);	
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}


//metodos publicos

//suma de dos fraciones
Racional Racional::suma(const Racional &rac) const{
	long num, den;
	den = mcm(_denom, rac._denom);
	num =  (_numer * (den / _denom)) + (rac._numer * (den / rac._denom));
	Racional suma = Racional(num, den);
	return suma;
}

//division de dos fraciones
Racional &Racional::divideYActualiza(Racional &rac) {
	
	Racional cero= Racional();

	//comprobamos que la fracion no es 0/1. Si lo es, lanzamos error
	if ( cero._numer == rac._numer && cero._denom == rac._denom )
		throw EDivisionPorCero();
	else
	{
		_numer = _numer * rac._denom;
		_denom = _denom * rac._numer;
		reduce();
	}
	
	return *this;
}

//resta de dos fraciones
Racional Racional::operator-(const Racional &rac) const{
	long num, den;
	den = mcm(_denom, rac._denom);
	num = (_numer * (den / _denom)) - (rac._numer * (den / rac._denom));
	Racional resta = Racional(num, den);
	return resta;
}

//multiplicacion de dos fraciones
Racional &Racional::operator*=(const Racional &rac) {
	_denom = _denom * rac._denom;
	_numer = _numer * rac._numer;
	reduce();
	return *this;
}

//comparacion de dos fraciones
bool Racional::operator==(const Racional &rac) {

	bool sw=false;
	if (_denom == rac._denom && _numer == rac._numer)
		sw=true;

	return sw;
}