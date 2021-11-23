/** @file mensaje.hh
    @brief Especificación de la clase mensaje.hh
*/


#ifndef _MENSAJE_
#define _MENSAJE_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <string>
//#include <algorithm>
//#include <map>
#endif

using namespace std;

/** @class Mensaje
    @brief Representa un mensaje
*/

class Mensaje {

    public:

    //Constructores

	/** @brief Constructora por defecto. 
            \pre <em>Cierto</em>
            \post El resultado es un mensaje sin información
        */ 
	Mensaje();

	/** @brief Constructora con identificador asignado. 
            \pre «idm» y «cont» es un string
            \post El resultado es un mensaje con identificador
        */ 
	Mensaje(string idm, string cont);

	//Destrucoras

	// /** @brief Destructora por defecto. 
        //     \pre <em>Cierto</em>
        //     \post El resultado la destrucción del parámetro implícito
        // */ 
	// ~Mensaje();

	//Modificadoras

	//Consultoras

	/** @brief Devuelve el contenido del mensaje
	    \pre <em>Cierto<\em>
	    \post Devuelve un string con el contenido del p.i.
	*/
	string ret_contenido();
  
	/** @brief Devuelve el identificador del mensaje
	    \pre <em>Cierto<\em>
	    \post Devuelve un string con el identificador del parámetro implícito.
	*/
	string ret_idm();


	/** @brief Devuelve la longitud del mensaje
	    \pre <em>Cierto<\em>
	    \post Devuelve un entero con la longitud del contenido del p.i.
	*/
	int ret_longitud();

	//Leer y escribir

    private:

	string id;
	string contenido;

};

#endif
