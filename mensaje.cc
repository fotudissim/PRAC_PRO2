/** @file mensaje.cc
    @brief Implementación de la clase «Mensaje»
*/

#include "mensaje.hh"

using namespace std;

//Constructores

Mensaje::Mensaje() { }

Mensaje::Mensaje(string idm, string cont) {

    id = idm;
    contenido = cont;

}

//Consultores

string Mensaje::ret_contenido() {

    return contenido;

}

string Mensaje::ret_idm() {

    return id;

}

int Mensaje::ret_longitud() {

    return contenido.size();

}
