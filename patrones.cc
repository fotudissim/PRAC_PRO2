/** @file patrones.cc
    @brief Implementación de la clase patrones
*/

#include "patrones.hh"

using namespace std;

//Constructora
Patrones::Patrones() { }

//Modificadoras

void Patrones::add_patron() {

    Patron ptr;
    ptr.inicializar_ptr();
    cjt_patrones.push_back(ptr);

}

//Consultoras
bool Patrones::existe_patron(int idp) {

  int n = cjt_patrones.size();
  if ( (( n - idp) < 0) or (idp == 0)) return false;
  return true;

}


int Patrones::num_ptr() {

  return cjt_patrones.size();

}

//Lectura y escritura


void Patrones::leer_patrones(int p) {

    for (int i = 0; i < p; i++) {

	add_patron();

    }

}

void Patrones::listar_patrones() {

    for(int i = 0; i < cjt_patrones.size(); i++) {

	cjt_patrones[i].escribir_patron();

    }

}

void Patrones::codificar_patron(int idp, int b) {

    string salt,msg;
    getline(cin,salt);
    getline(cin,msg);
  
    cjt_patrones[idp - 1].codificar_msg(b,msg);

}

void Patrones::codificar_patron_msg(int idp, int b, const string& msg) {

    cjt_patrones[idp - 1].codificar_msg(b,msg);

}

int Patrones::decod_patron(int idp, int b) {

    cjt_patrones[idp - 1].decod(b);

}
