/**
NOMBRE Y APELLIDOS:
LABORATORIO:
PUESTO:
USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/


#ifndef _GESTION_ADMISIONES_H
#define _GESTION_ADMISIONES_H

#include <string>
using namespace std;

/**
Tipo que representa el código de los
pacientes
*/
typedef unsigned int CodigoPaciente;

/**
Clase para almacenar los datos de un paciente
*/
class Paciente {
public:
	/**
	Operación de construcción
	*/
	Paciente(unsigned int codigo,const string& nombre, unsigned int edad, const string& sintomas);
	
	/**
	Operaciones observadoras para consultar los distintos
	datos del paciente: su nombre, su edad y los síntomas que
	tiene
	*/
	unsigned int codigo()const;
	unsigned int edad() const;
	const string& nombre() const;
	const string& sintomas() const;
private:
	/** Campos para almacenar los datos del paciente */
	unsigned int _codigo;
	string _nombre;
	string _sintomas;
	unsigned int _edad;
};


/**
RECUERDA QUE PUEDES DEFINIR AQUI TODAS LAS CLASES
Y TIPOS ADICIONALES QUE CONSIDERES OPORTUNO
*/

/**
Excepción que debe levantarse cuando trata de darse de alta
un paciente con un código duplicado
*/
class EPacienteDuplicado {};

/**
Excepción que debe levantarse cuando trata de consultarse los
datos de un paciente a través de un código que no existe.
*/
class EPacienteNoExiste {};

/**
Excepción que debe levantarse cuando trata de consultarse la información
del siguiente paciente a atender, pero no hay pacientes en el sistema.
*/
class ENoHayPacientes {};

/**
Clase que implementa el TAD
*/
class GestionAdmisiones {
public:
	/**
	Constructora: crea un sistema de gestión de admisiones vacío
	*/
	GestionAdmisiones();
	/**
	Añade un paciente al sistema.
	Levanta la excepción EPacienteDuplicado si ya hay un paciente esperando con el
	mismo codigo
	@param codigo El código del paciente
	@param nombre El nombre del paciente
	@param edad La edad del paciente
	@param sintomas Los sintomas del paciente
	*/
	void an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas);
	/**
	Recupera los datos de un paciente, dado su código.
	Levanta la excepción EPacienteNoExiste si el código no se corresponde con el
	de ningún paciente en espera
	@param codigo El código del paciente
	@param nombre El nombre del paciente
	@param edad La edad del paciente
	@param sintomas Los sintomas del paciente
	*/
	void info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const;
	/**
	Recupera el código del siguiente paciente que va a ser atendido.
	Levanta la excepción ENoHayPacientes en caso de que no haya pacientes en espera.
	@param codigo El código del paciente
	*/
	void siguiente(CodigoPaciente& codigo) const;
	/**
	Determina si hay pacientes en espera
	@return true si hay pacientes, false en otro caso.
	*/
	bool hay_pacientes() const;
	/**
	Elimina del sistema todo el rasto de un paciente, dado su código.
	Si el código no existe, la operación no tiene efecto.
	@param codigo El codigo del paciente a eliminar.
	*/
	void elimina(CodigoPaciente codigo);
private:
	// Debe elegirse la representación más adecuada para implementar
	// eficientemente este TAD
};

#endif