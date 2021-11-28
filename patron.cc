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


    //Tenemos que decidir si partimos el mensaje en bloques
    if ( b >= msg.size() ) {

	//Generamos un arbol binario a partir de un mensaje.
	BinTree<char> am;
	am = msg_arbol(msg,1);
	//Codificamos el mensaje a partir del patrón
	vector<int> offsets(msg.size(),-1); //offsets de los carácteres

	recorreArb(am,offsets,1);
	cout << "\"";
	for (int i = 0; i < msg.size(); i++) {
	    //msg[i] += offsets[i]; 
	    cout << msg[i] + offsets[i];
	}
	cout << "\"";
    }

    if ( b < msg.size() ) {

	int mb = msg.size() / b;

	for ( int i = 0; i < mb; i++ ) {
	    string aux; //String auxiliar
	    if (i == 0) {
		copy(msg.begin(),msg.begin() + b,aux.begin());
		//codigo para encriptar

		BinTree<char> am;
		am = msg_arbol(aux,1);
		//Codificamos el mensaje a partir del patrón
		vector<int> offsets(aux.size(),-1); //offsets de los carácteres

		recorreArb(am,offsets,1);
		cout << "\"";
		for (int i = 0; i < aux.size(); i++) {
		    cout << aux[i] + offsets[i];
		}
		cout << "\"";


	    }
	    else if (i == mb - 1) {
		copy(msg.begin() + (b*(mb-1)), msg.end(), aux.begin());
		//codigo para encriptar

		BinTree<char> am;
		am = msg_arbol(aux,1);
		//Codificamos el mensaje a partir del patrón
		vector<int> offsets(aux.size(),-1); //offsets de los carácteres

		recorreArb(am,offsets,1);
		cout << "\"";
		for (int i = 0; i < aux.size(); i++) {
		    cout << aux[i] + offsets[i];
		}
		cout << "\"";

	    }
	    else {
		copy(msg.begin() + b*i,(msg.begin() + b*i)+b,aux.begin());
		//codigo para encriptar

		BinTree<char> am;
		am = msg_arbol(aux,1);
		//Codificamos el mensaje a partir del patrón
		vector<int> offsets(aux.size(),-1); //offsets de los carácteres

		recorreArb(am,offsets,1);
		cout << "\"";
		for (int i = 0; i < aux.size(); i++) {
		    cout << aux[i] + offsets[i];
		}
		cout << "\"";

	    }

	    }

    }
    


}

void Patron::decod(int b,const string& msg) {

  
    //Tenemos que decidir si partimos el mensaje en bloques
    if ( b >= msg.size() ) {

	//Generamos un arbol binario a partir de un mensaje.
	BinTree<char> am;
	am = msg_arbol(msg,1);
	//Codificamos el mensaje a partir del patrón
	vector<int> offsets(msg.size(),-1); //offsets de los carácteres

	recorreArb(am,offsets,1);
	cout << "\"";
	for (int i = 0; i < msg.size(); i++) {
	    //msg[i] += offsets[i]; 
	    cout << msg[i] - offsets[i];
	}
	cout << "\"";
    }

    if ( b < msg.size() ) {

	int size = msg.size();
	int mb = size / b;

	for ( int i = 0; i < mb; i++ ) {
	  string aux; //String auxiliar
	  if (i == 0) {
	    copy(msg.begin(),msg.begin() + b,aux.begin());
	    //codigo para encriptar

	    BinTree<char> am;
	    am = msg_arbol(aux,1);
	    //Codificamos el mensaje a partir del patrón
	    vector<int> offsets(aux.size(),-1); //offsets de los carácteres

	    recorreArb(am,offsets,1);
	    cout << "\"";
	    for (int i = 0; i < aux.size(); i++) {
		cout << aux[i] - offsets[i];
	    }
	    cout << "\"";


	  }
	  else if (i == mb - 1) {
	    copy(msg.begin() + (b*(mb-1)), msg.end(), aux.begin());
	    //codigo para encriptar

	    BinTree<char> am;
	    am = msg_arbol(aux,1);
	    //Codificamos el mensaje a partir del patrón
	    vector<int> offsets(aux.size(),-1); //offsets de los carácteres

	    recorreArb(am,offsets,1);
	    cout << "\"";
	    for (int i = 0; i < aux.size(); i++) {
		cout << aux[i] - offsets[i];
	    }
	    cout << "\"";

	  }
	  else {
	    copy(msg.begin() + b*i,(msg.begin() + b*i) + b,aux.begin());
	    //codigo para encriptar

	    BinTree<char> am;
	    am = msg_arbol(aux,1);
	    //Codificamos el mensaje a partir del patrón
	    vector<int> offsets(aux.size(),-1); //offsets de los carácteres

	    recorreArb(am,offsets,1);
	    cout << "\"";
	    for (int i = 0; i < aux.size(); i++) {
		cout << aux[i] - offsets[i];
	    }
	    cout << "\"";

	  }

	}

    }

}


