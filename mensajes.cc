/** @file mensajes.cc
    @brief Implementación de la clase mensajes
*/

#include "mensajes.hh"

using namespace std;

//Constructora

/**@brief Implementación: Inicialización estándar */
Mensajes::Mensajes() { }

//Modificadoras

/**@brief Implementación: función add_msg */
void Mensajes::add_msg(string idm) {

    string salto,cont;
    getline(cin,salto);
    getline(cin,cont);

    Mensaje aux(idm,cont);
    cjt_mensajes.insert( make_pair(idm,aux) );


}

/**@brief Implementación: función borrar_msg */
void Mensajes::borrar_msg(string idm) {

  cjt_mensajes.erase( cjt_mensajes.find(idm) );

}

//Consultoras


/**@brief Implementación: función ret_msg */
Mensaje Mensajes::ret_msg(string idm) {


    map<string,Mensaje>::iterator it = cjt_mensajes.find(idm);
    return it->second;


}

/**@brief Implementación: función existe_msg */
bool Mensajes::existe_msg(string idm) {

    if ( cjt_mensajes.find(idm) == cjt_mensajes.end() ) return false;
    return true;

}


/**@brief Implementación: función num_msg */
int Mensajes::num_msg() {

    return cjt_mensajes.size();

}

/*
    Para poder efectuar la función listar_msg(), hemos de tener hecha ya una función que devuelva un booleano que se llame
    «cmp», con la cual podremos hacer el «sort» del vector auxiliar que más adelante hemos hecho.

    Al ser una función que solo se accederá en esta clase y no fuera de ella.
*/

/**@brief Implementación: función cmp */
bool cmp ( Mensaje a, Mensaje b ) {
//bool Mensajes::cmp ( Mensaje a, Mensaje b ) {

    return ( a.ret_idm() < b.ret_idm() );

}

/**@brief Implementación: función leer_mensajes */
void Mensajes::leer_mensajes(int m) {


    for (int i = 0; i < m; i++) {

	string idm;
	cin >> idm;

	string salto,cont;
	getline(cin,salto); //este getline se hace para el salto entre identificador y mensaje
	getline(cin,cont); //la función getline guarda hasta que se registra "\n"

	Mensaje aux(idm,cont);
	cjt_mensajes.insert( make_pair(idm,aux) );

    }

}


/**@brief Implementación: función listar_msg */
void Mensajes::listar_msg() {

    //Declaramos un vector auxiliar con el cual podremos ordenarlo e imprimirlo en pantalla
    vector< Mensaje > aux( cjt_mensajes.size() );

    /* Hacemos un bucle para pasar los elementos del map al vector
	Se ha de inicializar un iterador con el cual poder recorrer el map elemento por elemento
    */

    int i = 0;
    for ( map<string,Mensaje>::iterator it = cjt_mensajes.begin(); it != cjt_mensajes.end(); it++  ) {

	aux[i] = it->second;
	i++;

    }

    //Ahora se ordenará el vector auxiliar
    sort( aux.begin(), aux.end(), cmp );

    for (i = 0; i < aux.size(); i++) cout << aux[i].ret_idm() << endl << "\"" << aux[i].ret_contenido() << "\"" << endl;
    
}
