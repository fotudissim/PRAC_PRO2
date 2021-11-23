/** @file patrones.hh
    @brief Especificación de la clase patrones.hh
*/

#ifndef _PATRONES_
#define _PATRONES_
#include "patron.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <algorithm>
//#include <map>
#endif

using namespace std;

/** @class Patrones
    @brief Representa el conjunto de patrones
*/

class Patrones {

    public:

	//Constructores
	/** @brief Constructora de la clase Patrones
	    \pre <em>Cierto<\em>
	    \post El resultado es un conjunto de patrones no inicializado
	*/
	Patrones();

	//Modificadores


	/** @brief Añade un patrón al conjunto de patrones
	    \pre <em>Cierto<\em>
	    \post Añade un elemento al contenedor del parámetro implícito
	*/
	void add_patron();

	//Consultores


	/** @brief Devuelve true/false en función de si existe o no un elemento con identificador «idr»
	    \pre «idr» es un entero: idr >= 0
	    \post Devuelve true en caso de hallar el elemento en el contenedor, en caso contrario, devuelve false
	*/
	bool existe_patron(int idp);
 
	/** @brief Devuelve la cantidad de patrones que existen en el conjunto de patrones
	    \pre <em>Cierto<\em>
	    \post Devuelve cuantos elementos se hallan en el contenedor del parámetro implícito
	*/
	int num_ptr();

	//Lectura y escritura

	/** @brief Lee una secuencia de mensajes del parámetro implícito
	    \pre El entero «p» ha de ser superior a 0
	    \post El parámetro implícito registra los «p» patrones
	*/
	void leer_patrones(int p);


	/** @brief Escribe en forma de lista los patrones en orden creciente de su identificador
	    \pre <em>Cierto<\em>
	    \post Imprime en orden creciente respecto al identificador de cada elemento del contenedor del p.i.
	*/
	void listar_patrones();

	/** @brief Codifica un mensaje (no existente) mediante el uso de un patrón «idp»
	    \pre «idp» es un patrón existente (siendo este un entero)
	    \post Se imprime el mensaje codificado
	*/
	void codificar_patron(int idp, int b);

	/** @brief Codifica un mensaje existente mediante el uso de un patrón «idp»
	    \pre «idp» es el id de un patrón existente (entero), «b» es un entero mayor que 0, «msg» es un string sin inicializar
	    \post Se imprime el mensaje codificado
	*/
	void codificar_patron_msg(int idp, int b, const string& msg);

	/** @brief Decodifica un mensaje no existente mediante el uso de un patrón «idp»
	    \pre «idp» es un patrón existente (de tipo entero) y «b» un entero mayor que 0 
	    \post Devuelve «1» si ha ocurrido algún error, en caso contrario, escribe el contenido del mensaje decodificado en «dmsg»
	*/
	int decod_patron(int idp, int b);

    private:

	vector<Patron> cjt_patrones;

};

#endif  
