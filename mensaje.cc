/** @file mensaje.cc
    @brief Implementación de la clase «Mensaje»
*/

#include "mensaje.hh"

using namespace std;

//Constructores

/**@brief Implementación: inicializadora estándar */
Mensaje::Mensaje() { }

/**@brief Implementación: Inicializadora con parámentros */
Mensaje::Mensaje(string idm, string cont) {

    id = idm;
    contenido = cont;

}

//Consultores

/**@brief Implementación: función ret_contenido */
string Mensaje::ret_contenido() {

    return contenido;

}

/**@brief Implementación: función ret_idm */
string Mensaje::ret_idm() {

    return id;

}

/**@brief Implementación: función ret_longitud */
int Mensaje::ret_longitud() {

    return contenido.size();

}
