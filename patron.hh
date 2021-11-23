/** @file patron.hh
    @brief Especificación de la clase patron.hh
*/


#ifndef _PATRON_
#define _PATRON_

#ifndef NO_DIAGRAM
#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
#include "BinTree.hh"

#endif

using namespace std;

/** @class Patron
    @brief Representa un patrón
*/

class Patron {

    public:

	//Constructoras

	/** @brief Constructora por defecto. 
            \pre <em>Cierto<\em>
            \post El resultado es un patrón sin información
        */ 
	Patron();

	/** @brief Constructora con identificador asignado. 
            \pre «idp» es un entero mayor o igual que 0
            \post El resultado es un patrón con identificador
        */ 
	Patron(int idp);

	//Destrucoras

	/** @brief Destructora por defecto. 
            \pre <em>Cierto<\em>
            \post El resultado la destrucción del parámetro implícito
        */ 
	~Patron();

	//Modificadoras

	//Consultores

	//Leer y escribir

    private:

	BinTree<int> ctr_ptr;
};

#endif
