/** @file rejillas.hh
    @brief Especificación de la clase rejillas.hh
*/

#ifndef _REJILLAS_
#define _REJILLAS_
#include "rejilla.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <algorithm>
//#include <map>
#endif

using namespace std;

/** @class Rejillas
    @brief Representa el conjunto de rejillas
*/

class Rejillas {

    public:

	//Constructores
	/** @brief Constructora de la clase Rejillas
	    \pre <em>Cierto<\em>
	    \post El resultado es un conjunto de rejillas no inicializado
	*/
	Rejillas();

	//Modificadores
  
	/** @brief Comprueba que una rejilla es válida y la añade al conjunto de rejillas
	    \pre 0 < n,k
	    \post Retorna 0 si se ha podido añadir con exito la rejilla o 1/2 si ha habido un error
	*/
	int add_rejilla( int n, int k );

	//Consultores

	/** @brief Devuelve el tamaño del conjunto de rejillas
	    \pre <em>Cierto<\em>
	    \post Retorna la cantidad de elementos del contenedor del parámetro implícito
	*/
	int num_rejillas();

	/** @brief Devuelve true/false en función de la existencia de una rejilla «idr»
	    \pre «idr» es un string
	    \post Retorna "true" si existe una rejilla con identificador «idr» en el parámetro implícito
	*/
	bool existe_rejilla(int idr); 

	//Lectura y escritura

	/** @brief Lee una secuencia de mensajes del parámetro implícito
	    \pre El entero «r» ha de ser superior a 0
	    \post El parámetro implícito registra los «r» rejillas
	*/
	void leer_rejillas(int r);

	/** @brief Escribe una lista de las rejillas existentes en orden creciente por identificador
	    \pre <em>Cierto</em>
	    \post Se imprime un listado de los elementos del contenedor del p.impl. ordenador por identificador
	*/
	void listar_rejillas();

	/** @brief Codifica un mensaje (no existente) mediante el uso de una rejilla «idr»
	    \pre «idr» es una rejilla existente (siendo este un entero)
	    \post Se imprime el mensaje codificado
	*/
	void codificar_rejilla(int idr);

	/** @brief Codifica un mensaje existente mediante el uso de una rejilla «idr»
	    \pre «idr» es el id de una rejilla existente, y msg un string no inicializado («idr» es un entero)
	    \post Se imprime el mensaje codificado
	*/
	void codificar_rejilla_msg(int idr,const string& msg);

	/** @brief Decodifica un mensaje no existente mediante el uso de una rejilla «idr»
	    \pre «idr» es una rejilla existente (de tipo entero), y «dmsg» es un string no inicializado
	    \post Devuelve «1» si ha ocurrido algún error, en caso contrario, escribe el contenido del mensaje decodificado en «dmsg»
	*/
	int decod_rj(int idr, string& dmsg);


    private:

	/**@brief Vector que contiene las rejillas */
	vector<Rejilla> cjt_rejillas;
  
};

#endif  
