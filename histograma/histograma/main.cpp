#include <iostream>
//using namespace std;

//DIVIDE Y VENCERAS
void parcial(int v[], int c, int f, bool &ord, int &max, int &min){
	int m = (c + f) / 2;
	int maxiz = 0;
	int maxde = 0;
	int miniz = 100000;
	int minde = 100000;
	bool ordiz = true;
	bool ordde = true;
	//CASO BASE : cuando (comiendo == final) es cuando divides
	//el ultimo caso el array q queda es un numero y es maximo y minino y ordenacion es igual a TRUE
	if (c == f){
		max = v[c];
		min = v[c];
		ord = true;
	}
	else{
		//Caso recursivo para mirar si cada mitad el maximo de la derecha 
		parcial(v, c, m, ordiz, maxiz, miniz);
		parcial(v, m + 1, f, ordde, maxde, minde);

		//es mayor o igual a maximo de la izquierda. Y el minimo de al izquierda
		//es menor o igual a minimo de la derecha
		//se realiza un and para saber si es True las ordenacion de los 2 lados
		if (maxiz <= maxde && miniz <= minde){
			if (max <= maxde) 
				max = maxde;
			if (min >= miniz) 
				min = miniz;

			ord = ordde && ordiz;
		}
		//Sino cumple la condición de maximos y minimos devolvemos FALSE.
		else 
			ord = false;
		
	}
}

bool resuelve(){
	int n;
	int v[100000];
	int i;

	cin >> n;

	if (n == 0)
		return false;
	
	for (i = 0; i < 100000 && n != 0; i++){
		v[i] = n;
		cin >> n;
	}
	bool sw = false;
	int max = 0;
	int min = 100000;
	parcial(v, 0, i-1, sw, max, min);
	if (sw) 
		cout << "SI" << endl;
	else 
		cout << "NO" << endl;

	return true;
}

int main(){

	while (resuelve()){

	}

	return 0;
}