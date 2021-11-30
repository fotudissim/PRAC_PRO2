/**@mainpage ENCRIPTACIÓN DE MENSAJES: Plataforma para la encriptación de mensajes
*/

/** @file program.cc
    @brief Programa principal de la práctica
*/

#include <iostream>
#include <string>
#include "mensajes.hh"
#include "rejillas.hh"
#include "patrones.hh"

using namespace std;

int main() {

//Primero declaramos los diferentes conjuntos iniciales
    Mensajes msgs0;
    Rejillas rjs0;

    //Descomentar para cuando la entrega final
    Patrones ptrs0;

    int m,r,p; //afegir el p

    cin >> m;
    msgs0.leer_mensajes(m);

    cin >> r;
    rjs0.leer_rejillas(r);

    cin >> p;
    //Descomentar para cuando la entrega final
    ptrs0.leer_patrones(p);


    //«cmd» es la variable de tipo String la cual nos permite ejecutar el comando en cuestión
    string cmd;

    cin >> cmd;

    while (cmd != "fin") {

	if (cmd == "nuevo_mensaje" or cmd == "nm") {

	    string idm;
	    cin >> idm;

	    cout << "#" << cmd << " " << idm << endl;

	    if ( msgs0.existe_msg(idm) ) cout << "error: ya existe un mensaje con ese identificador" << endl;
	    else {
		msgs0.add_msg(idm);
		cout << msgs0.num_msg() << endl;

	    }

	}//final de función 1

	else if (cmd == "nueva_rejilla" or cmd == "nr") {

	    int n,k; //Dimensión «n», Tamaño/Longitud «k»
	    cin >> n >> k;

	    cout << "#" << cmd << endl;
	    switch ( rjs0.add_rejilla(n,k) ) {

		case 0:
		    cout << rjs0.num_rejillas() << endl;
		    break;
		case 1:
		    cout << "error: dimensiones incorrectas de la rejilla" << endl;
		    break;
		case 2:
		    cout << "error: la rejilla con sus giros no cubre todas las posiciones N x N" << endl;
		    break;
	    }
	
	}//final de función 2

	//Descomentar para cuando la entrega final
        else if (cmd == "nuevo_patron" or cmd == "np") {

            cout << "#" << cmd << endl;
            ptrs0.add_patron();
            cout << ptrs0.num_ptr() << endl;

        }//final de función 3

	else if (cmd == "borra_mensaje" or cmd == "bm") {

	    string idm;
	    cin >> idm;
	    cout << "#" << cmd << " " << idm << endl;

	    if (not msgs0.existe_msg(idm)) cout << "error: el mensaje no existe" << endl;
	    else {
		msgs0.borrar_msg(idm);
		cout << msgs0.num_msg() << endl;
	    }
	  
	}//final de función 4

	else if (cmd == "listar_mensajes" or cmd == "lm") {

	    cout << "#" << cmd << endl;
	    msgs0.listar_msg();

	}//final de función 5

	else if (cmd == "listar_rejillas" or cmd == "lr") {
	    cout << "#" << cmd << endl;
	    rjs0.listar_rejillas();
	}//final de función 6

	//Descomentar para cuando la entrega final
        else if (cmd == "listar_patrones" or cmd == "lp") {
            cout << "#" << cmd << endl;
            ptrs0.listar_patrones();
        }//final de función 7

	else if (cmd == "codificar_rejilla" or cmd == "cr") {

	    int idr;
	    cin >> idr;
	    cout << "#" << cmd << " " << idr << endl;

	    if (not rjs0.existe_rejilla(idr)) cout << "error: la rejilla no existe" << endl;
	    else {
		rjs0.codificar_rejilla(idr);
	    }

	}//final de función 8

	else if (cmd == "codificar_guardado_rejilla" or cmd == "cgr") {
	    string idm;
	    int idr;
	    cin >> idm >> idr;

	    cout << "#" << cmd << " " << idm << " " << idr << endl;
	    if (not msgs0.existe_msg(idm)) cout << "error: el mensaje no existe" << endl;
	    else if (not rjs0.existe_rejilla(idr)) cout << "error: la rejilla no existe" << endl;
	    else {
	      rjs0.codificar_rejilla_msg(idr, msgs0.ret_msg(idm).ret_contenido() );
	    }

	}//final de función 9

	else if (cmd == "decodificar_rejilla" or cmd == "dr") {
	    int idr;
	    string salto,dmsg; //donde «dmsg» es el mensaje decodificado
	    cin >> idr;
	    getline(cin,salto);
	    getline(cin,dmsg);
	    
	    cout << "#" << cmd << " " << idr << endl;
	    if (not rjs0.existe_rejilla(idr)) cout << "error: la rejilla no existe" << endl;
	    else {

		if ( rjs0.decod_rj(idr,dmsg) == 1 ) cout << "error: la dimension del mensaje es inadecuada para la rejilla" << endl;
		else cout << "\"" << dmsg << "\"" << endl; 

	    }
	    
	}//final de función 10

	//Descomentar para cuando la entrega final
        else if (cmd == "codificar_patron" or cmd == "cp") {
            int idp;
            cin >> idp;
            int b; //tamaño de los bloques
            cin >> b;

            cout << "#" << cmd << " " << idp  << " " << b << endl;

            if (not ptrs0.existe_patron(idp)) cout << "El patrón no existe" << endl;
            else ptrs0.codificar_patron(idp,b); 
        }//final de función 11

	//Descomentar para cuando la entrega final
        else if (cmd == "codificar_guardado_patron" or cmd == "cgp") {
	  //return 0;
            int idp, b; //«b» es el tamaño de los bloques
            string idm;
            cin >> idm;
            cin >> idp;
            cin >> b;
	    
            cout << "#" << cmd << " " << idm << " " << idp << " " << b << endl;

            if (not msgs0.existe_msg(idm)) cout << "error: el mensaje no existe" << endl;
            else if (not ptrs0.existe_patron(idp)) cout << "error: el patron no existe" << endl;
            else {
		string msg = msgs0.ret_msg(idm).ret_contenido();
        	ptrs0.codificar_patron_msg(idp,b,msg);
            }

        }//final de función 12

	//Descomentar para cuando la entrega final
        else if (cmd == "decodificar_patron" or cmd == "dp") {

            int idp,b;
            cin >> idp >> b;

            cout << "#" << cmd << " " << idp << " " << b << endl;
            if (not ptrs0.existe_patron(idp)) cout << "error: el patron no existe" << endl;
            else {

        	ptrs0.decod_patron(idp,b);

            }
          
        }//final de función 13
	cin >> cmd;
    } //final del while


} //final del programa
