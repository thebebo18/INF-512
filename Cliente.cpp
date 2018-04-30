
	#include <iostream>
	#include <fstream>
	#include<vector>
	#include <ctype.h>
	#include<conio.h>

	using namespace std;

	#include "Cliente.h"
	   
	char r;
	unsigned long Cdo;
		
	void Cliente::ingresarCliente()
	{
		system("cls");
		Cliente g;			

		fstream Escribir("CLIENTES.bin", ios::out | ios::binary | ios::ate);

		if (Escribir.fail()) {
			cerr << "\n=> ERROR 504!, ARCHIVO NO SE HA CREADO...."
			     << "\n\n=> Pulse una tecla para continuar... ";
			getch();  
			cout << "\n\n";
			exit(1);
            }
		else
		{
			do
               		 {
		 
		cout << "\n\t<><><><><><><><><><><><><><><><><><><><><><><><><><><";	
		cout << "\n\t  ** INGRESE LOS REGISTROS DE LOS CLIENTES ";
		cout << "\n\t<><><><><><><><><><><><><><><><><><><><><><><><><><>< \n";
				cin.ignore();
		cout << "\n\t- NOMBRE DEL CLIENTE: ";
		cin.getline(g.nombre,30);
		
		cout << "\n\t- APELLIDO DEL CLIENTE: ";
		cin.getline(g.apellido,30);		
		
		cout << "\n\t- DIRECCION DEL CLIENTE: ";
               	cin.getline(g.direccion,30);	
						
		cout << "\n\t- SEXO DEL CLIENTE [M/F]: ";
		cin >> g.sexo;
			
		cout << "\n\t- CEDULA DEL CLIENTE: ";
		cin >> g.cedula;
		                				
               	cout << "\n\t- E-MAIL DEL CLIENTE: ";
		cin >> g.Email;
				
		cout << "\n\t><><><><><><><><><><><><><><><><><><><><><><><><><><"<<endl;

		 Escribir.seekg(0, ios::end); // Posiciona el puntero al final
         	  Cdo = Escribir.tellg(); /* Obtiene la posicion actual, que no es
                              mas que la longitud de archivo hasta ese momento. */
        	  Escribir.seekg(0, ios::beg); 
		  g.Codigo_C = (Cdo/sizeof(Cliente)) + 100;
		  
		 
         	Escribir.write(reinterpret_cast <char *> (&g), sizeof(Cliente));
			
		//Escribir.write((char*)(&g), sizeof(Cliente));
		
		cout << "\n\n\t DESEA  INGRESAR OTRO CLIENTE ? S/N:   \n";
		cin >> r;
		cin.ignore();

                }while( r == 'S'  ||  r == 's'  );
			Escribir.close();
		}
		
	}   //Fin del metodo ingresar cliente.

	void Cliente :: verCliente()  
        		{
		system("cls");
		char opcion;

		Cliente c; 
		
		cout << "\n\t   ><><><><><><><><><><><><><><><><><><><><><><><><><><><";
		cout << "\n\t   ** DESEA VER TODOS LOS REGISTROS DE LOS CLIENTES S/N [ ] ";
		cout << "\n\t   ><><><><><><><><><><><><><><><><><><><><><><><><><><><";
		gotoxy(66, 3);
		cin>>opcion;

		fstream Leer("CLIENTES.bin", ios::in | ios::binary);
            if(opcion=='s' || opcion == 'S')
            			{

                system("cls");
                Leer.read(reinterpret_cast <char *> (&c), sizeof(Cliente));


			while(! Leer.eof() )
                {
                
		cout << "\n\t***********************************";
		cout << "\n\t  MOSTRANDO DATOS DEL CLIENTE";
		cout << "\n\t*************************************";
		cout << "\n\t-NOMBRE: " << c.nombre << "\n" ;
		cout << "\n\t-APELLIDO: " << c.apellido << "\n";
		cout << "\n\t-DIRECCION: " << c.direccion << "\n";
		cout << "\n\t-CEDULA: " << c.cedula << "\n";
		cout << "\n\t-E-mail: " << c.Email << "\n ";
		cout << "\n\t-Sexo: " <<  c.sexo ;
		cout << "\n\t-codigo: " << c.Codigo_C ;
		cout << "\n\t*************************************" << endl;

		Leer.read(reinterpret_cast <char *> (&c), sizeof(Cliente));
                }

			Leer.close();    
			system("pause");

          	  }

		do{

		cout << "\n\t =>DESEA INGRESAR OTRO CLIENTE: ? ";
		cin >> r;

		if(r == 's') {
		c.ingresarCliente();
                } else {
             
	        cout << "\n\t *>SEGURO QUE NO LO DESEA INGRESAR ? ";
                cin >> r;
 
               }
        	}while(r == 'S'|| r == 's');
            
         } //Fin de la funcion verCliente

          void Cliente :: BuscarCliente()
   		 	{

		int posicion;

	 system("cls");

	 cout << "\n\t   ><><><><><><><><><><><><><><><><><><><><><><><";
	 cout << "\n\t      ***BUSCADOR DE CLIENTES EN EL ARCHIVO*** ";
	 cout << "\n\t   ><><><><><><><><><><><><><><><><><><><><><><><";
	 
	 fstream Lectura("CLIENTES.bin", ios::in | ios::binary);    
	 
	 if(Lectura.fail()){
	   cerr << "ERROR en la busqueda!, Archivo no existe, Pulse <ENTER> para salir " << endl;
	   system("pause");
	   exit(1);
	 }

	
	 unsigned long longarchivo;
	 Lectura.seekg(0, ios::end); 
	 longarchivo = Lectura.tellg(); 
	    
	 Lectura.seekg(0, ios::beg);		    

	 char respuesta;
	 unsigned long numreg;
	 
	    do{ 

	     cout <<"\n\n\t => El tamano del archivo es: " 
	      << longarchivo << " bytes" << endl;	    

	    cout << "\n\t => Existen " << longarchivo/sizeof(Cliente)
	         << " Registros almacenados." << endl; 
	    cout << " \n\t => Entre el numero del registro a leer: [   ]";
	    gotoxy(51, 10);	    
	    cin >> numreg;

	
	    if( numreg <= 100 || cin.fail()) { 
		cout << "\n\n=> Error en el dato1, Termina ejecucion!!\n\n"
		     << "\n=> Pulse una tecla... ";
		getch();
		cout << endl;
		exit(1);
	    }
	      
	    else if( numreg > longarchivo/sizeof(Cliente) + 100 ){ 
		cout << "\n\n=> Error en el dato2, Termina ejecucion!!\n\n"
		     << "\n=> Pulse una tecla... ";
		getch();
		cout << endl;
		exit(1);
	    }

	    else ; 
	     
	     Lectura.seekg((numreg - 100)* sizeof(Cliente));
	     
	     Cliente x;
	     
	     if ( (unsigned long)Lectura.tellg() < longarchivo  + 100) {
		  
		     Lectura.read( (char*)(&x), sizeof(Cliente) );
		
	       
	       cout << "\n\t***********************************";
	       cout << "\n\t  MOSTRANDO DATOS DEL CLIENTE";
	       cout << "\n\t*************************************" << endl;
	       cout << "\n \t - Codigo: " << x.Codigo_C ;
	       cout << "\n \t - Nombre: " <<  x.nombre ;
	       cout << "\n \t - Apellido: " <<  x.apellido ;
	       cout << "\n \t - Direccion: " <<  x.direccion ;
	       cout << "\n \t - Cedula: " << x.cedula ;
	       cout << "\n \t - E-mail: " << x.Email ;
	       cout << "\n \t - Sexo: " <<  x.sexo ;
	       cout << "\n\t***********************************" << endl;
		    
	     }
	     else { 
	       cout << "\n\t REVISION DEL ARCHIVO TERMINADA";
	       system("pause");
	       exit(1); 
	     }
	     cout << "\n\t=> DESEA CONSULTAR OTRO REGISTRO ?, S/N:  ";
	     cin >> respuesta;
		system("cls");
	   
	     		
	 }while( !Lectura.eof() && respuesta == 'S' || respuesta == 's' ); 

	 Lectura.close();
	 
    	

    }   // Fin de la funcion BuscarCliente().

  /*  // funcion principal
	int main()
	{

	Cliente c;

		c.ingresarCliente(); // Ingresar un cliente al menu
		c.verCliente();  //Mostrar Cliente
		c.BuscarCliente();  // Buscar cliente por posicion
		//ejecutar();
		system("\t pause");
		return 0;
	}  */

