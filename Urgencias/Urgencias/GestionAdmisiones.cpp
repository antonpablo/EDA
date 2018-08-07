/**
NOMBRE Y APELLIDOS:
LABORATORIO:
PUESTO:
USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/
#include "lista.h"
#include "GestionAdmisiones.h"
#include <iostream>
#include <string>
using namespace std;

/**
Implementación de las operaciones de la clase Paciente
*/



Paciente::Paciente(unsigned int codigo, const string& nombre, unsigned int edad, const string& sintomas) :
_codigo(codigo),_nombre(nombre), _sintomas(sintomas), _edad(edad) {}


unsigned int Paciente::codigo() const {
	return _codigo;
}
unsigned int Paciente::edad() const {
	return _edad;
}
const string& Paciente::nombre() const {
	return _nombre;
}
const string& Paciente::sintomas() const {
	return _sintomas;
}

/**
Implementa aquí los métodos de las clases adicionales
*/

Lista <Paciente> medico;
/**
Debes completar la implementación de las operaciones de GestionAdmisiones,
y justificar la complejidad de las mismas.
*/

/**
COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
GestionAdmisiones::GestionAdmisiones() {
	// A IMPLEMENTAR
	medico = Lista<Paciente>();
	
}

/**
COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas) {
	// A IMPLEMENTAR
	int code1 = codigo;
	for (Lista<Paciente>::Iterator it = medico.begin(); it != medico.end(); it.next()){
		
		if (it.elem().codigo()==code1)
			throw EPacienteDuplicado();

	
	}
	Paciente p = Paciente(code1,nombre, edad, sintomas);
	medico.pon_final(p);
	
	
}

/**
COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENTAR
	int code1 = codigo;
	int code2 = -1;
	for (Lista<Paciente>::ConstIterator it = medico.cbegin(); it != medico.cend(); it.next()){

		if (it.elem().codigo() == code1)

		{
			code2 = it.elem().codigo();
			nombre = it.elem().nombre();
			sintomas = it.elem().sintomas();
			edad = it.elem().edad();
		}


	}
	if (code2 < 0)
		throw EPacienteNoExiste();

}

/**
COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo) const {
	// A IMPLEMENTAR
	if (medico.esVacia())
		throw ENoHayPacientes();
	else{
		Lista<Paciente>::Iterator it = medico.begin();
		codigo = it.elem().codigo();
	}
	


}

/**
COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
bool GestionAdmisiones::hay_pacientes() const {
	// A IMPLEMENTAR
	if (medico.esVacia())
		return false;
	else
		return true;
}

/**
COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
	// A IMPLEMENTAR
	
	int code1 = codigo;
	
	/*for (Lista<Paciente>::Iterator it = medico.begin(); it != medico.end(); it.next()){
		cout << it.elem().codigo() << endl;
		if (it.elem().codigo() == code1)
			medico.eliminar(it);
			
			
	}*/
	

}