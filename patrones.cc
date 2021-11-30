/** @file patrones.cc
    @brief Implementación de la clase patrones
*/

#include "patrones.hh"

using namespace std;

//Constructora
/** @brief Implementación: Inicializadora estándar */
Patrones::Patrones() { }

//Modificadoras

/** @brief Implementación: función add_patron */
void Patrones::add_patron() {

    Patron ptr;
    ptr.inicializar_ptr();
    cjt_patrones.push_back(ptr);

}

//Consultoras

/** @brief Implementación: función existe_patron */
bool Patrones::existe_patron(int idp) {

  int n = cjt_patrones.size();
  if ( (( n - idp) < 0) or (idp == 0)) return false;
  return true;

}


/** @brief Implementación: función num_ptr */
int Patrones::num_ptr() {

  return cjt_patrones.size();

}

//Lectura y escritura


/** @brief Implementación: función leer_patrones */
void Patrones::leer_patrones(int p) {

    for (int i = 0; i < p; i++) {

	add_patron();

    }

}

/** @brief Implementación: función listar_patrones */
void Patrones::listar_patrones() {

    for(int i = 0; i < cjt_patrones.size(); i++) {

	cout << "Patron " << i + 1 << ":" << endl;
	cjt_patrones[i].escribir_patron();

    }

}

/** @brief Implementación: función codificar_patron */
void Patrones::codificar_patron(int idp, int b) {

    string salt,msg;
    getline(cin,salt);
    getline(cin,msg);
  
    cjt_patrones[idp - 1].codificar_msg(b,msg);
    cout << endl;

}

/** @brief Implementación: función codificar_patron_msg */
void Patrones::codificar_patron_msg(int idp, int b, const string& msg) {

    cjt_patrones[idp - 1].codificar_msg(b,msg);
    cout << endl;

}

/** @brief Implementación: función decod_patron */
void Patrones::decod_patron(int idp, int b) {

    string salt,msg;
    getline(cin,salt);
    getline(cin,msg);
    cjt_patrones[idp - 1].decod(b,msg);
    cout << endl;

}
