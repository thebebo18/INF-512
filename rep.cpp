
	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <iomanip>
	#include <iostream>
	#include <string>
	#include <fstream>
	#include <vector>
	#include <stdio.h>
	#include <stdlib.h>
	#include "marco.h"
	
	using namespace std;

	#include "reparaciones.h"
	
	//Reparaciones :: Reparaciones(){}

	void Reparaciones :: setDatos()
		{
		    
			int y;
			fstream reparacionEntrada("Reparaciones.bin", ios::out|ios::binary|ios::ate);
			Reparaciones rep;
			system("cls");
			y=10;
			//MARCO();
			cin.ignore();
			gotoxy(20,++y);          //cout << "INGRESE LOS SIGUIENTES CAMPOS:";
			cout << "\n\t<><><><><><><><><><><><><><><><><><><><><><><><><><><";
			gotoxy(20,++y);	
		        cout << "\n\t  ** INGRESE LOS REGISTROS DE LA REPARACION ";
		        gotoxy(20,++y);
			cout << "\n\t<><><><><><><><><><><><><><><><><><><><><><><><><><><";
				
			gotoxy(20,++y);cout << "ingrese tipo: ";
		        gotoxy(34,y);cin.getline(rep.tipo,30);
		
			gotoxy(20,++y);cout << "ingrese modelo: ";
			gotoxy(36,y);cin.getline(rep.modelo,30);
		
			gotoxy(20,++y);cout << "ingrese problema del equipo: ";
			gotoxy(49,y);cin.getline(rep.problema,30);
		
			gotoxy(20,++y);cout << "ingrese posible solucion del equipo: ";
			gotoxy(57,y);cin.getline(rep.solucion,30);
	
	   	        reparacionEntrada.write((char*)(&rep), sizeof(Reparaciones));  
		
			if(reparacionEntrada.fail()){

			gotoxy(20,++y);cout << "ERROR!, Archivo no existe, termina proceso, Pulse ENTER" << endl;
			system("pause");
			exit(1);
			}else;
			
			reparacionEntrada.close();
		
		}
	
	string  Reparaciones :: getTipo() {

		return tipo;
	}

	string Reparaciones :: getModelo() {

			return modelo;
	}

	string Reparaciones :: getProblema() {

			return problema;
	}

	void Reparaciones :: leerArchivos()
			{

			system("cls");
			//MARCO();
			char opcion;
			int y;

			Reparaciones c; 
			y=10;
					
			gotoxy(20,++y);cout<<"a) DESEA MOSTRAR REGISTRO DE REPARACIONES.";
			gotoxy(20,13);cout<<"";
			gotoxy(50,11);cout<<"[ ]";
			gotoxy(51,11);cin>>opcion;
		
			fstream Leer("Reparaciones.bin", ios::in | ios::binary);

		    if(opcion=='s')

		    {
		        system("cls");

		        Leer.read(reinterpret_cast <char *> (&c), sizeof(Reparaciones));
		      
				while(! Leer.eof() )

		        {
				
		        cout << "\n\t<><><><><><><><><><><><><><><><><><><><><><><><><><><";	
		        cout << "\n\t  ** MOSTRANDO LOS REGISTROS DE LA REPARACION ";
			cout << "\n\t<><><><><><><><><><><><><><><><><><><><><><><><><><><";
			
			cout << "\n\t===============================";
			cout << "\n\t-TIPO: " << c.tipo << endl;
		        cout << "\n\t-MODELO: " << c.modelo << endl;
		        cout << "\n\t-PROBLEMA: " << c.problema << endl;
			cout << "\n\t-SOLUCION: " << c.solucion << endl;
			cout << "\n\t===============================";

			Leer.read(reinterpret_cast <char *> (&c), sizeof(Reparaciones));

		        }

				Leer.close();    // Cerrando el Archivo

				system("pause");

				}
				else if(opcion!='a'){
			
						gotoxy(20,++y);cout<<"OPCION NO VALIDAD.";
						gotoxy(20,++y);system("pause");
					}
			
		}

	/*	 int main () { 

	Reparaciones  f;

	 f. setDatos();
         f.leerArchivos();
          
        return 0;

    	};     */

