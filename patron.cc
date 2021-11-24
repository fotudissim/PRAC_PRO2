/** @file patron.cc
    @brief Implementación de la clase patron
*/

#include "patron.hh"

using namespace std;

//Constructora

Patron::Patron() { }

//Modificadoras

//Función inmersiva usada en escribir_patron, como no se usa fuera de la implementación de la clase, no la especificamos en los headers
void init_ptr_im(BinTree<int>& pb) {

    int val;
    cin >> val;

    if (val != -1) {

	BinTree<int> i; //rama izquierda
	BinTree<int> d; //rama derecha
	init_ptr_im(i);
	init_ptr_im(d);

	pb = BinTree<int>(val,i,d);

    }

}

void Patron::inicializar_ptr() {

    init_ptr_im(ctr_ptr);

}

//Lectura y escritura
//Función inmersiva usada en escribir_patron, como no se usa fuera de la implementación de la clase, no la especificamos en los headers
void out_im_patron(const BinTree<int>& ptr) {

  cout << "(";
  if ( not ptr.empty() ) cout << ptr.value();
  out_im_patron(ptr.left());
  out_im_patron(ptr.right());
  cout << ")";

}

void Patron::escribir_patron() {

    BinTree<int> aux = ctr_ptr;
    out_im_patron(aux);
    cout << endl;

}


