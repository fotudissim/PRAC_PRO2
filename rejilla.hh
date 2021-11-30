/** @file rejilla.hh
    @brief Especificación de la clase rejilla.hh
*/


#ifndef _REJILLA_
#define _REJILLA_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
//#include <map>
#endif

using namespace std;

/** @class Rejilla
    @brief Representa una rejilla
*/

class Rejilla {

    public:

	//Constructores


	/** @brief Constructora por defecto. 
            \pre <em>Cierto</em>
            \post El resultado es una rejilla sin información
        */ 
	Rejilla();

	/** @brief Constructora con identificador asignado. 
            \pre «idp» es un entero igual o mayor que 0
            \post El resultado es una rejilla con identificador
        */ 
	//Rejilla(int idp);


	/** @brief Constructora con parámetros 
            \pre n,npos > 0
            \post El resultado es una rejilla con información
        */ 
	Rejilla(int n, int npos); //n == dim; npos == k

	//Destrucoras

	// /** @brief Destructora por defecto. 
        //     \pre <em>Cierto<\em>
        //     \post El resultado la destrucción del parámetro implícito
        // */ 
	// ~Rejilla();

	//Modificadoras

	//Consultoras


	int dim_mat();
  
	/** @brief Devuelve la dimensión de la rejilla
	    \pre <em>Cierto<\em>
	    \post Devuelve el entero «dim»
	*/
	int ret_dim();
  
	/** @brief Devuelve el tamaño de la rejilla
	    \pre <em>Cierto<\em>
	    \post Devuelve el entero «k»
	*/
	int ret_k();

	//ret_fila y ret_columna lo usaremos para navegar por el vector de pairs

	/** @brief Devuelve el valor fila del hueco especificado
	    \pre «i» es un entero mayor o igual que 0
	    \post Devuelve el un entero que referencia al primer valor del "pair" en la posición «i»
	*/
	int ret_fila(int i);

	/** @brief Devuelve el valor columna del hueco especificado
	    \pre «i» es un entero mayor o igual que 0
	    \post Devuelve el un entero que referencia al segundo valor del "pair" en la posición «i»
	*/
	int ret_columna(int i);


	//Leer y escribir

	/** @brief Inicializa los huecos de la rejilla
	    \pre <em>cert</em>
	    \post Inicializa el valor de «huecos»
	*/
	void leer_huecos();

	/** @brief Inicializa la matriz «mat_rej», en caso que la matriz no sea válida, devuelve "FALSE"
	    \pre <em>Cierto</em>
	    \post Retorna <cierto/falso> en caso que la rejilla con sus K huecos son válidos o no
	*/
	bool valida();

	/** @brief Imprime por pantalla los huecos en sus diferentes posiciones y giros
	    \pre <em>Cierto</em>
	    \post Imprime por pantalla las posiciones de los huecos en sus 4 formas
	*/
	void escribir_huecos();

  //	/** @brief Inicializa la matriz (matriz)
  //	    \pre <em>Cierto<\em>
  //	    \post Inicializa la matriz «mat_rej», en caso que se repita alguna posición al rotar, devuelve «-1», en caso contrario, «0»
  //	*/
  //	int rellenar_matriz();


	/** @brief Imprime por pantalla la codificación del mensage pasado como parámetro
	    \pre «msg» es un string
	    \post Imprime por pantalla la codificación del mensaje pasado como parámetro
	*/
	void codificar(string msg);

	/** @brief Decodifica el mensaje pasado como parámetro
	    \pre «dmsg» es un string
	    \post «dmsg» se ve editado por la decodificación
	*/
	void decodificar(string dmsg);
  
    private:

	/**@brief Dimensión de la rejilla */
	int dim;

	/**@brief Número de huecos */
	int k; //número de huecos

	/**@brief Vector que almacena los huecos en pairs de enteros */
	vector < pair<int,int> > huecos; //el primer entero es: fila, el segundo entero es: columna

	/**@brief Matriz que guarda pairs de enteros y booleanos, mostrando orden de rotación y si está lleno o no */
	vector < vector< pair<int,bool> > > mat_rej;

};

#endif
