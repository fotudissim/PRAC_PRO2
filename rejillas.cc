/** @file rejillas.cc
    @brief Implementación de la clase rejillas
*/

#include "rejillas.hh"

using namespace std;

//Constructores

Rejillas::Rejillas() { }

//Modificadores

int Rejillas::add_rejilla(int n, int k) {

    //Inicializamos una rejilla auxiliar
    Rejilla aux(n,k);
    aux.leer_huecos();

    //Comprobamos que los parámetros de la rejilla son válidos
    if ( k != ( (n * n) / 4 ) ) return 1;

    //Comprobamos que las posiciones de la rejilla son válidas
    
    //Si el valor de «n» es senar, el valor central se repetirá 4 veces, por ende
    if ( (n % 2) != 0 ) return 2; 

    // == Implementación de la función para ver si una matriz es válida == //

    //Esta implementación es mejor que esté en la propia clase de Rejilla
    // == LO SIGUIENTE HASTA LA MARCA CP_REJILLA_METODO SE HA DE COPIAR //
    /*
    for (int i = 0; i < k; i++) {

	int x = aux.ret_fila(i);
	int y = aux.ret_columna(i);
	int tempx; //valor auxiliar

	for (int j = 0; j < 3; j++) {

	    if (mat_rej[x][y].second) return 2;
	    mat_rej[ x ][ y ].first = j;
	    mat_rej[ x ][ y ].second = true;

	    tempx = x;
	    x = n - 1 - y;
	    y = tempx;

	} //Mirar las 3 rotaciones
    } //Mirar las K posiciones

    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {

	if (! mat_rej[i][j]) return 2;

      }
    } //Acaba la comprobación de espacios vacíos
    */
    // MARCA CP_REJILLA_METODO // 

    if (!aux.valida()) return 2;

    cjt_rejillas.push_back( aux );
    return 0;
} //Final de la función ADD_REJILLA

int Rejillas::num_rejillas() {

    return cjt_rejillas.size();

}


bool Rejillas::existe_rejilla(int idr) {

    int n = cjt_rejillas.size();
    if ( (( n - idr) < 0) or (idr == 0)) return false;
    return true;

}


void Rejillas::leer_rejillas(int r) {

  //    cjt_rejillas = vector<Rejilla>(r);

    for (int i = 0; i < r; i++) {

	int n,k;
	cin >> n >> k;

	add_rejilla(n,k);
	//cout << "Ha fet add_rejilla" << endl;
	//Rejilla aux(n,k);
	//aux.leer_huecos();

	//cjt_rejillas.push_back( aux );
	//cjt_rejillas[i] = aux;

    }
} //Final de leer rejillas

void Rejillas::listar_rejillas() {

  for ( int i = 0; i < cjt_rejillas.size(); i++ ) {

    cout << "Rejilla " << (i + 1) << ":" << endl; //Primera línea
    cout << cjt_rejillas[i].ret_dim() << " " << cjt_rejillas[i].ret_k() << endl; //Segunda Línea

    //Aqui tenemos que poner EN ORDEN los huecos de la matriz mat_rej
    cjt_rejillas[i].escribir_huecos();
  }


}

void Rejillas::codificar_rejilla(int idr) {

    string salto,msg;
    getline(cin,salto);
    getline(cin,msg);

    cjt_rejillas[idr - 1].codificar(msg);

}


void Rejillas::codificar_rejilla_msg(int idr,const string& msg) {

    cjt_rejillas[idr - 1].codificar(msg);

}

int Rejillas::decod_rj(int idr, string& dmsg) {

    int dim = cjt_rejillas[idr - 1].ret_dim();
    //if ( (dim * dim) % dmsg.size() != 0 ) return 1;
    if ( dmsg.size() % (dim*dim) != 0 ) return 1;
    cjt_rejillas[ idr - 1 ].decodificar(dmsg);

    return 0;

}


