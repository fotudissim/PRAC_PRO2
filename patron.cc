/** @file patron.cc
    @brief Implementación de la clase patron
*/

#include "patron.hh"

using namespace std;

//Constructora

Patron::Patron() { }

Patron::~Patron() { }

//Modificadoras

//Función inmersiva usada en escribir_patron, como no se usa fuera de la implementación de la clase, no la especificamos en los headers
void Patron::init_ptr_im(BinTree<int>& pb) {

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
void Patron::out_im_patron(const BinTree<int>& ptr) {

    cout << "(";
    if ( not ptr.empty() ) cout << ptr.value();
    if ( not ptr.left().empty() ) out_im_patron(ptr.left());
    else cout << "()";
    if ( not ptr.right().empty() ) out_im_patron(ptr.right());
    else cout << "()";
    cout << ")";

}

void Patron::escribir_patron() {

    BinTree<int> aux = ctr_ptr;
    out_im_patron(aux);
    cout << endl;

}

//Función usada dentro de la implementación la cual no necesita de su especificación en los headers
/* 
   Esta función está inspirada en el funcionamiento de los heaps binarios. Si no lo requiriera la entrega,
   podriamos trabajar con vectores en vez de árboles binarios interpretandolos como heaps binarios.
*/
//Crida inicial: arrel = msg_arbol(missatge,1)
BinTree<char> Patron::msg_arbol(const string& msg, int i) {

  BinTree<char> izq = BinTree<char>();
  BinTree<char> der = BinTree<char>();
  int i_izq = 2*i;
  int i_der = (2*i)+1;

  if ( msg.size() > i_izq - 1 ) izq = msg_arbol(msg,i_izq);
  if ( msg.size() > i_der - 1 ) der = msg_arbol(msg,i_der);

  return BinTree<char>(msg[i-1],izq,der);

}

//Crida inicial: nodo_arbol,raiz_patron,offsets,1
void Patron::pintaPatron(const BinTree<char>& arb, const BinTree<int>& ptr,vector<int>& offsets,int ind) {


    offsets[ind-1] = ptr.value();
    if ( (not arb.left().empty()) and (not ptr.left().empty())) pintaPatron(arb.left(),ptr.left(),offsets,2*ind);
    if ( (not arb.right().empty()) and (not ptr.right().empty())) pintaPatron(arb.right(),ptr.right(),offsets,2*ind+1);
    
}

//Crida inicial: raiz_arbol,offsets,1
void Patron::recorreArb(const BinTree<char>& arb,vector<int>& offsets,int ind) {

    BinTree<int> ptr = ctr_ptr;
    if (offsets[ind-1] == -1) pintaPatron(arb,ptr,offsets,ind);
    if ( (not arb.left().empty()) ) recorreArb(arb.left(),offsets,2*ind);
    if ( (not arb.right().empty()) ) recorreArb(arb.right(),offsets,2*ind+1);

}

void Patron::codificar_msg(int b,const string& msg) {


    int sizemsg = msg.size();
    int mod = sizemsg%b;
    //ceiling vago
    int num_arb = ( sizemsg/b ) + ( mod != 0);

    cout << "\"";
    for (int i = 0; i < num_arb; i++) {

      int sizess = b;
      if ( (i == num_arb - 1) and (mod != 0) ) sizess = mod; 

      string substring(sizess,'*');
      for (int j = 0; ( j < b ) and ( j + (i*b) < sizemsg ) ;j++) {

	substring[j] = msg[i*b + j];

      }
      BinTree<char> am;
      am = msg_arbol(substring,1);
      //Codificamos el mensaje a partir del patrón
      //sizess és la variable del tamany del string substring
      vector<int> offsets(sizess,-1); //offsets de los carácteres

      recorreArb(am,offsets,1);

      for (int k = 0; k < sizess; k++) {
	
	cout << char(32 + (substring[k] - 32 + offsets[k])%95 );
      }

    } //final del for inicial
    cout << "\"";

}

void Patron::decod(int b,const string& msg) {

    int sizemsg = msg.size();
    int mod = sizemsg%b;
    //ceiling vago
    int num_arb = ( sizemsg/b ) + ( mod != 0);
    cout << "\"";
    for (int i = 0; i < num_arb; i++) {

      int sizess = b;
      if ( (i == num_arb - 1) and (mod != 0) ) sizess = mod; 

      string substring(sizess,'*');
      for (int j = 0; ( j < b ) and ( j + (i*b) < sizemsg ) ;j++) {

	substring[j] = msg[i*b + j];

      }
      BinTree<char> am;
      am = msg_arbol(substring,1);
      //Codificamos el mensaje a partir del patrón
      //sizess és la variable del tamany del string substring
      vector<int> offsets(sizess,-1); //offsets de los carácteres
      recorreArb(am,offsets,1);
      
      for (int k = 0; k < sizess; k++) {

	char c = substring[k] - offsets[k];
	while(c < 32) c += 95;
	  
      	cout << c;

      }

    } //final del for inicial
    cout << "\"";
  

}


