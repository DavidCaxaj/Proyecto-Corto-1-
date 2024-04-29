#include <iostream>
#include <string>
using namespace std;

//JONATHAN ROGELIO JOCOL MARROQUIN * 202407035 * INGENIERIA EN ELECTRONICA 
//JOSUÉ DAVID VELÁSQUEZ CAXAJ * 202407031 * INGENIERIA EN ELECTRONICA

string nombre_jugador1,nombre_jugador2; // CADENA DE CARACTERES PARA LOS NOMBRES
int puntosJugador1=0; // VARIABLES LAS CUALES NOS SERVIRAN PARA GUARDAR EL DATO DE LA SUMA TOTAL DE CADA JUGADOR 
int puntosJugador2=0;
int i=0;  // VARIABLE QUE SERVIRA DENTRO DE LOS CICLOS FOR 
bool jugar=true; // VARIABLE BOOLEANA #1

//FUNCION #1 * AQUI DESIGNAMOS LA CANTIDAD DE FILAS Y OBJETOS QUE DEBE IMPRIMIR EN PANTALLA 
void menu(int fila1,int fila2,int fila3){
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	for(i=0;i<fila1; i++){
		cout<<"&";
	}
	cout<<endl;
	for(i=0;i<fila2; i++){
		cout<<"&";
	}
	cout<<endl;
	for(i=0;i<fila3; i++){
		cout<<"&";
	}
	cout<<endl;
	cout<<endl;
	
}
	//FUNCION #2, LOOP DEL JUEGO
	void juego_iniciado(){
		int fila1=3;  //VARIABLES DONDE DECLARAMOS EL VALOR INICIAL DE CADA FILA 
		int fila2=5;
		int fila3=7;
		int fila=0; // VARIABLE QUE SERVIRA PARA HACER COMPARACIONES CON LAS OTRAS DE FILAS
		int objetos=0; // VARIABLE QUE SERVIRA PARA HACER RESTAS DE ACUERDO A LA CANTIDAD DE OBJETOS EN CADA FILA
		
		bool turnoJugador1=true; // VARIABLE BOOLEANA #2
		while (true) {
			
			//MOSTRAMOS EL MENU 
			menu(fila1, fila2, fila3);
			
			// AQUI DESIGNAMOS TURNOS 
			if (turnoJugador1) {
				cout<<"TURNO DE "<<nombre_jugador1<<":"<<endl;
			} else {
				cout<<"TURNO DE "<<nombre_jugador2<<":"<<endl;
			}
			
			//SELECIONAMOS LA FILA Y LA CANTIDAD DE OBJETOS QUE TENEMOS QUE ELIMINAR
			cout <<"INGRESE EL NUMERO DE FILA (1, 2 o 3) :"<<endl;
			cin >> fila;
			cout <<"INGRESE LA CANTIDAD DE OBJETOS A RETIRAR :"<<endl;
			cin >> objetos;
			
			//AQUI DESIGNAMOS QUE NO PUEDEN SELECIONAR OTRAS FILAS ADICIONAL A LAS EXISTENTES 
			if (fila<1 || fila>3) {
				cout << "FILA INVALIDA!!! INGRESE UNA FILA VALIDA DEL 1 AL 3 :"<< endl;
				continue;
			}
			
			// AQUI DESIGNAMOS QUE HALLA LOS SUFICIENTES OBJETOS EN LAS FILAS PARA RETIRAR 
			if (fila==1 && objetos<=fila1) {
				fila1-=objetos;
			} else if (fila==2 && objetos<=fila2) {
				fila2-=objetos;
			} else if (fila==3 && objetos<=fila3) {
				fila3-= objetos;
			} else {
				cout << "CANTIDAD INVALIDA!!! PORFAVOR SELECCIONE UNA CANTIDAD EXISTENTE EN LAS FILAS :"<< endl;
				continue;
			}
			// VERIFICAMOS QUIEN RETIRO EL ULTIMO OBJETO
			if (fila1==0 && fila2==0 && fila3==0) {
				cout<< nombre_jugador1 <<" Y" << nombre_jugador2 <<" ESTAN EN EMPATE"<<endl;
				puntosJugador1++;
				puntosJugador2++;
				break;
			}else if(turnoJugador1 || !turnoJugador1){
				if(fila1==0 && fila2==1 && fila3==0){
					if (turnoJugador1) {
						cout<< nombre_jugador1 <<" GANOOO!!!"<< endl;
						puntosJugador1+=3;
					} else {
						cout<< nombre_jugador2 <<" GANOOO!!!"<< endl;
						puntosJugador2+=3;
					}
					break;
				}else if(fila1==1 && fila2==0 && fila3==0){
					if (turnoJugador1) {
						cout<< nombre_jugador1 <<" GANOOO !!!"<< endl;
						puntosJugador1 += 3;
					}else {
						cout<< nombre_jugador2 <<" GANOOO !!!"<< endl;
						puntosJugador2+=3;
					}
					break;
				}else if(fila1==0 && fila2==0 && fila3==1){
					if (turnoJugador1) {
						cout<< nombre_jugador1 << " GANOOO !!!"<<endl;
						puntosJugador1+=3;
					} else {
						cout<< nombre_jugador2 << " GANOOO !!!"<<endl;
						puntosJugador2+=3;
					}
					break;
				}
			}
			// CAMBIAMOS EL TURNO DEL JUGADOR
			turnoJugador1=!turnoJugador1;
		}
		//SE MUESTRAN EL PUNTEO TOTAL DE AMBOS JUGADORES 
		cout<<"Puntos de " <<nombre_jugador1<<" : "<<puntosJugador1<<endl;
		cout<<"Puntos de " <<nombre_jugador2<<" : "<<puntosJugador2<<endl;
		
	}
		//FUNCION #3
		bool jugar_nuevamente() {
			char respuesta;  // VARIABLE QUE NOS SERVIRARA PARA GUARDAR UN CARACTER Y USARLO PARA SEGUIR JUNGANDO O NO 
			do {
				cout<<"PRESIONE 'a' SI DESEA SEGUIR JUGANDO O 'b' SI DESEA TERMINAR EL JUEGO :("<<endl;
				cin>>respuesta;
			} while(respuesta!='a'&& respuesta!='b');
			
			return respuesta == 'a';
		}
		
		int main() {
			cout<<"BIENVENIDOS AL JUEGO DE NIM :D"<<endl<<endl<<endl;
			cout << "INGRESE EL NOMBRE DEL JUGADOR #1 :"<<endl;
			cin >> nombre_jugador1;
			cout << "INGRESE EL NOMBRE DEL JUGADOR #2 :"<<endl;
			cin >> nombre_jugador2;
			
			while(jugar){
				juego_iniciado();
				jugar=jugar_nuevamente();
				
			}
			cout<<"GRACIAS POR JUGAR :)"<<endl;
			return 0;
		}

