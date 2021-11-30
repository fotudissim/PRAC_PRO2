/** @file rejilla.cc
    @brief Implementació de la clase rejilla.cc
*/

#include "rejilla.hh"

using namespace std;

//Constructores

Rejilla::Rejilla() { }


Rejilla::Rejilla(int n, int npos) {

    dim = n;
    k = npos;
}

//Consultoras

int Rejilla::ret_dim() {

    return dim;
}

int Rejilla::ret_k() {

    return k;

}

int Rejilla::ret_fila(int i) {

    return huecos[i].first; 

}

int Rejilla::ret_columna(int i) {

    return huecos[i].second; 

}

//Leer y escribir
void Rejilla::leer_huecos() {

    for (int i = 0; i < k ; i++) {

	int x,y;
	cin >> x >> y;
	huecos.push_back(make_pair(x,y));

    }

}

int Rejilla::dim_mat() {

  return mat_rej.size();

}

bool Rejilla::valida() {

    vector < vector< pair <int,bool> > > aux = vector < vector< pair <int,bool> > >(dim , vector< pair<int,bool> >(dim, make_pair(0,false)));
    for (int i = 0; i < k; i++) {

	int x = huecos[i].first  - 1;
	int y = huecos[i].second - 1;
	int tempx; //valor auxiliar

	for (int j = 0; j < 4; j++) {

	    if (aux[x][y].second) return false;
	    aux[ x ][ y ].first = j + 1;
	    aux[ x ][ y ].second = true;

	    tempx = x;
	    x = dim - 1 - y;
	    y = tempx;

	} //Mirar las 4 rotaciones
    } //Mirar las K posiciones

    for (int i = 0; i < dim; i++) {
	for (int j = 0; j < dim; j++) {

	if (! aux[i][j].second) return false;

      }
    } //Acaba la comprobación de espacios vacíos

    mat_rej = aux;
    return true;

} //Final de la función «valida()»

void Rejilla::escribir_huecos() {

    for (int rot = 1; rot <= 4; rot++) {
	int c = 0;
	for (int i = 0; i < dim; i++) {
	    for (int j = 0; j < dim; j++) {
	      
		if (mat_rej[i][j].first == rot) {
		    cout << "(" << i + 1 << "," << j + 1 << ")";
		    ++c;
		    if (c < k) cout << " ";
		}
	    }

	}
	cout << endl;
	c = 0;
    }

}


void Rejilla::codificar(string msg) {

    /* Se ha de hacer una matriz para cada (long_texto/dim²)
       Es decir, debemos primero hacer un «int box = ceil (msg.size() / (dim * dim))»
       La variable box nos va a decir cuantas matrices auxiliares necesitaremos
       Por ende, tendremos que hacer otro bucle «for» para cada

    */
    double calc = (msg.size() * 1.0) / ((dim * dim) * 1.0 ) ;
    int nbox = ceil(calc);

    int m = 0; //Con esta variable iteraremos por todo el mensaje

    vector< vector<char> > aux;
    bool exit = false;
    for ( int b = 0; b < nbox; b++) {

	aux = vector< vector<char> >( dim , vector<char>(dim, ' ') );
	//Declaramos e inicializamos una matriz con espacios en blanco para cada bloque
	//Iteramos por cada rotación
	for(int rot = 1; rot <= 4; rot++) { 
	    //Iteramos por «mat_rej»
	    if (exit) break;
	    for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {

		    if (exit) break;
		    if ( mat_rej[i][j].first == rot ) {
			aux[i][j] = msg[ m ];
			if (m == msg.size()-1) {
			    exit = true;
			}
			else m++;
		    }
		}
	    } // Final de la iteración de mat_rej
	} // Final iteración por cada rotación
	//Imprimimos el contenido de «aux»
	if (b == 0) cout << "\"";
	for (int i = 0; i < dim; i++) {

	    for (int j = 0; j < dim; j++) {

	    cout << aux[i][j];
	    }

	}
	if (b == nbox - 1) cout << "\"" << endl;

    } //Final del for nbox
}


void Rejilla::decodificar(string dmsg) {


    /* Se ha de hacer una matriz para cada (long_texto/dim²)
       Es decir, debemos primero hacer un «int box = ceil (msg.size() / (dim * dim))»
       La variable box nos va a decir cuantas matrices auxiliares necesitaremos
       Por ende, tendremos que hacer otro bucle «for» para cada

    */
    double calc = (dmsg.size() * 1.0) / ((dim * dim) * 1.0 ) ;
    int nbox = ceil(calc);
    int m = 0; //Con este entero navegaremos por el string «dmsg»

    vector< vector<char> > aux;
    bool exit = false;

    for (int b = 0; b < nbox; b++) {
	aux = vector< vector<char> >( dim , vector<char>(dim, ' ') );

	for(int i = 0; i < dim; i++) {
	    for(int j = 0; j < dim; j++) {
		if(exit) break;
		aux[i][j] = dmsg[m];
		if (m == dmsg.size()-1) exit = true;
		m++;
	    }
	} //final del for para pasar de una parte del dmsg -> aux[][]

	if (b == 0) cout << "\"";
	for(int rot = 1; rot <= 4; rot++) {
	    for(int i = 0; i < dim; i++) {
		for(int j = 0; j < dim; j++) {

		    if(mat_rej[i][j].first == rot) {
			cout << aux[i][j];
		    }
		  
		}
	    }
	}
	if (b == nbox - 1) cout << "\"" << endl;
    }

} //final de la funció general

