/** @file mensajes.hh
    @brief Especificación de la clase mensajes.hh
*/

#ifndef _MENSAJES_
#define _MENSAJES_
#include "mensaje.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#endif

using namespace std;

/** @class Mensajes
    @brief Representa el conjunto de mensajes
*/

class Mensajes {

    public:

	//Constructores
	/** @brief Constructora de la clase Mensajes
	    \pre <em>Cierto<\em>
	    \post El resultado es un conjunto de mensajes no inicializado
	*/
	Mensajes();

	//Modificadores

	/** @brief Añade un nuevo mensaje con identificador «idm» al conjunto de mensajes
	    \pre «idm» es un string
	    \post Se añade un nuevo mensaje al contenedor del parámetro implícito
	*/
	void add_msg(string idm);

	/** @brief Borra un mensaje existente con identificador «idm» del conjunto de mensajes
	    \pre «idm» es un string
	    \post Se borra un elemento con identificador «idm» del contenedor del parámetro implícito
	*/
	void borrar_msg(string idm);

	//Consultores

	/** @brief Comprueba si existe un mensaje según su id en el conjunto de mensajes
	    \pre «idm» es un string
	    \post Devuelve true/false si se halla el id del mensaje en el parámetro implícito
	*/
	bool existe_msg(string idm);

	/** @brief Devuelve la cantidad de mensajes que se hallan en el conjunto de mensajes
	    \pre <em>Cierto<\em>
	    \post Retorna la cantidad de elementos del contenedor del parámetro implícito
	*/
	int num_msg();

	/** @brief Devuelve un elemento del contenedor con el respectivo «idm»
	    \pre «idm» es un string de un elemento existente en el contenedor del p. implícito
	    \post Retorna un elemento del contenedor con identificador «idm»
	*/
	Mensaje ret_msg(string idm);



	//Lectura y escritura

	/** @brief Lee una secuencia de mensajes del parámetro implícito
	    \pre El entero «m» ha de ser superior a 0
	    \post El parámetro implícito registra los «m» mensajes
	*/

	void leer_mensajes(int m);

	/** @brief Imprime todos los mensajes en forma de lista en orden alfabético
	    \pre <em>Cierto<\em>
	    \post Se imprimen los mensajes en orden alfabético
	*/
	void listar_msg();

    private:

	map<string,Mensaje> cjt_mensajes;

};

#endif  
