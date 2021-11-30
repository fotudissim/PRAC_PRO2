/** @file patron.hh
    @brief Especificación de la clase patron.hh
*/


#ifndef _PATRON_
#define _PATRON_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

	///** @brief Constructora con identificador asignado. 
        //    \pre «idp» es un entero mayor o igual que 0
        //    \post El resultado es un patrón con identificador
        //*/ 
	//Patron(int idp);

	//Destrucoras

 	/** @brief Destructora por defecto. 
             \pre <em>Cierto</em>
             \post El resultado la destrucción del parámetro implícito
        */ 
	~Patron();

	//Modificadoras

	/** @brief Inicializa un patrón
	    \pre <em>Cierto</em>
	    \post El resultado es la inicialización del arbol binario de enteros «ctr_ptr»
	*/
	void inicializar_ptr();

	//Consultores

	//Leer y escribir

	/** @brief Escribe el patrón con paréntesis
	    \pre <em>Cierto</em>
	    \post El resultado es la impresión en pantalla de los patrones
	*/
	void escribir_patron();

	/** @brief Escribe la codificación de un mensaje
	    \pre «b» es un entero mayor que 0 y msg es un string
	    \post El resultado es la impresión en pantalla de la codificación 
	*/
	void codificar_msg(int b,const string& msg);

	/** @brief Escribe la decodificación de un mensaje 
	    \pre «b» es un entero mayor que 0, «msg» es un string
	    \post El resultado es la impresión en pantalla de la decodificación 
	*/
	void decod(int b,const string& msg);
  
    private:
	BinTree<int> ctr_ptr;

	/** @brief Función inmersiva para iniciaizar el árbol binario de enteros «pb»
	    \pre «ptr» es un arbol binario de enteros vacío
	    \post El resultado es la incialización del árbol binario «pb»
	*/
	void init_ptr_im(BinTree<int>& pb);

	/** @brief Función usada para pasar de string a arbol binario
	    \pre «msg» es un string y i == 1
	    \post La función devuelve un árbol binario de caracteres
	*/
	BinTree<char> msg_arbol(const string& msg, int i);

	/** @brief Escribe el patrón de forma recursiva
	    \pre «ptr» es un arbol binario de enteros inicializado
	    \post El resultado es la impresión del valor del nodo del arbol
	*/
	void out_im_patron(const BinTree<int>& ptr);

	/** @brief Inicializa el vector<int> offsets
	    \pre «arb» es un arbol binario de chars inicializado, ptr es un arbol binario de enteros inicializado, ind es un entero == 1
	    \post El resultado es la inicializacion de «offsets»
	*/
	void pintaPatron(const BinTree<char>& arb, const BinTree<int>& ptr,vector<int>& offsets,int ind);

	/** @brief Función que llama a <pintaPatron> y recorre de forma recursiva el arbol arb
	    \pre «arb» es un arbol binario de chars inicializado, ptr es un arbol binario de enteros inicializado, ind es un entero >= 1
	    \post El resultado es la inicializacion de «offsets» mediante el uso de <pintaPatron>
	*/
	void recorreArb(const BinTree<char>& arb,vector<int>& offsets,int ind);


};

#endif
