
	#include "marco.h"
	#include "reparaciones.h"
	#include "Producto.h"
	#include "Cliente.h"
	#include "Cliente.cpp"
	#include "Factura.h"
	
	
	using namespace std;

	//prototipos de las funciones del menu.
	void ingrsearCliente();
	void mostraReparaciones();
	void mostraProductos();
	void mostraClientes();
	void BuscarCliente();
	void menuAlmacen();
	void menuFacturacion();
	void menuClientes();
	void MenuPrincipal();
	void buscadorProducto();
	void CrearFactura();

	//buscador producto.
	void buscadorProducto(){

	Producto p;
	p.consulta();

	}
	//ingrsar cliente.
	void ingresarClientes(){
	Cliente client;
	client.ingresarCliente();

	}
	//mostrar clientes
	void mostraClientes(){
	Cliente client;
	client.verCliente();
	}

	//Buscar Clientes
	void BuscarCliente(){
	Cliente client;
	client.BuscarCliente();
	}
	// mostrar productos
	void mostraProductos(){

	Producto pro;
	pro.VerProducto();

	}
	//crear factura
	void CrearFactura(){

	Factura f;
	f.CrearFactura();

	}
	int passwInput;
	int password = 1234;

	string username = "Smart";
        string userinput;

        //menu para ver todas las consultas delos modulos.
	void MenuConsultas(){
		
			char opc;

			do{
			
		    time_t t;
		     time(&t);
		     struct tm* petm = localtime(&t);
				int y;
				y=10;
				MARCO();
		    gotoxy(52,4);cout <<asctime(petm);    
				gotoxy(25,19);cout<<"ENTRE SU OPCION: ";
				gotoxy(30,10);cout<<"BUSCADORES-CONSULTAS";
				gotoxy(20,++y);cout<<"\n\t\ta) -> CONSULTAR CLIENTES       ";
				gotoxy(20,++y);cout<<"\n\t\tb) -> CONSULTAR ALMACEN        ";
				gotoxy(20,++y);cout<<"\n\t\tc) -> CONSULTAR REPARACIONES   ";
				gotoxy(20,++y);cout<<"\n\t\td) -> CONSULTAR FACTURA       ";
				gotoxy(20,++y);cout<<"\n\t\te) -> RETROCEDER              ";
				gotoxy(41,19);cout<<"[ ]";
				gotoxy(42,19);cin>>opc;
				switch(opc)
				{

					case 'a': mostraClientes(); break;
					case 'b': mostraProductos();  break;
					case 'c': mostraReparaciones();break;
					case 'd': menuFacturacion(); break;
					default :break;
				}

		}while(opc!='e');
		}
	//sub-meno de reparacion que ingresa una solicitud reparacion.
	void ingresarReparacion(){

		Reparaciones rep;
		rep.setDatos();
	
	}	//fin menu 

	//sub-meno de reparacion que muestra las solicitudes reparacion.
	void mostraReparaciones(){

		Reparaciones rep;
		rep.leerArchivos();
	
	}	//fin menu.

	void cPass(char *pass, int longitud){
	int cont=0;
	char password;

	do{
		password = getch();

		if(password!=13 && password!='\b'){
			printf("*");
			pass[cont] = password;
			cont++;
		}
		if(password=='\b' && cont !=0){
			printf("\b");
			printf(" ");
			printf("\b");
			cont--;
			pass[cont] = NULL;
		}
		
	}while(password!=13 && cont<longitud);

	pass[cont] = NULL;

        }

	//menu clientes.
	void menuClientes(){

	Cliente client;
	char opc;

			do{
			
		    time_t t;
		     time(&t);
		     struct tm* petm = localtime(&t);
				int y;
				y=10;
				MARCO();
		    gotoxy(52,4);cout <<asctime(petm);
				gotoxy(25,20);cout<<"ENTRE SU OPCION:"; 
				gotoxy(33,10);cout<<"CLIENTES ";              
				gotoxy(20,++y);cout<<"\n\t\ta) -> AGREGAR CLIENTES  ";
				gotoxy(20,++y);cout<<"\n\t\tb) -> MOSTRAR CLIENTES  ";
				gotoxy(20,++y);cout<<"\n\t\tc) -> BUSCAR CLIENTES   ";
				gotoxy(20,++y);cout<<"\n\t\td) -> RETROCEDER        ";
				gotoxy(41,20);cout<<"[ ]";
				gotoxy(42,20);cin>>opc;
			
				switch(opc)
				{
					case 'a': ingresarClientes(); break;
					case 'b': mostraClientes(); break;
					case 'c': BuscarCliente(); break;
					default :break;
				}

		}while(opc!='d');

	}

	//menu almacen.
	void menuAlmacen(){
	char opc;
	Producto pro;
			do{
			
		    time_t t;
		     time(&t);
		     struct tm* petm = localtime(&t);
				int y;
				y=10;
				MARCO();
		    gotoxy(52,4);cout <<asctime(petm);
				gotoxy(25,19);cout<<"ENTRE SU OPCION: ";
				gotoxy(33,10);cout<<"ALMACEN-PRODUCTOS";
				gotoxy(20,++y);cout<<"\n\t\ta) -> INGRESAR PRODUCTO    ";
				gotoxy(20,++y);cout<<"\n\t\tb) -> BUSCAR PRODUCTO      ";
				gotoxy(20,++y);cout<<"\n\t\tc) -> RETROCEDER          ";
				gotoxy(41,19);cout<<"[ ]";
				gotoxy(42,19);cin>>opc;
			
				switch(opc)
				{
					case 'a': pro.IngresarProducto(); break;
					case 'b': pro.BuscarProducto(); break;
					default :break;
				}

		}while(opc!='c');
	
		}

	//menu reparaciones.
	void menuReparacion(){
		
			char opc;

			do{
			
		    time_t t;
		     time(&t);
		     struct tm* petm = localtime(&t);
				int y;
				y=11;
				MARCO();
		    gotoxy(52,4);cout <<asctime(petm);
				gotoxy(25,18);cout<<"ENTRE SU OPCION: ";
				gotoxy(33,10);cout<<"REPARACIONES";
				gotoxy(21,++y);cout<<"a)   REGISTRAR REPARACIONES :   *****              ";
				gotoxy(21,++y);cout<<"b)   RETROCEDER                 **   *              ";
				gotoxy(21,++y);cout<<"                                **   *             ";
				gotoxy(21,++y);cout<<"                                *****               ";
				gotoxy(21,++y);cout<<"                                **   *              ";
				gotoxy(21,++y);cout<<"                                **   *             ";
				gotoxy(41,18);cout<<"[ ]";
				gotoxy(42,18);cin>>opc;
				switch(opc)
				{

					case 'a': ingresarReparacion(); break;
					default :break;
				}

		}while(opc!='b');

	}

	//menu  facturacion
	void menuFacturacion(){

			char opc;

			do{
			
		    time_t t;
		     time(&t);
		     struct tm* petm = localtime(&t);
				int y;
				y=11;
				MARCO();
		    gotoxy(52,4);cout <<asctime(petm);
				gotoxy(25,20);cout<<"ENTRE SU OPCION: ";
				gotoxy(33,10);cout<<"FACTUTACIONES";
				gotoxy(20,++y);cout<<"a)   REGISTRAR UNA FACTURA :     *******            ";
				gotoxy(20,++y);cout<<"b)   RETROCEDER                  *******          ";
				gotoxy(20,++y);cout<<"                                 **               ";
				gotoxy(20,++y);cout<<"                                 ****              ";
				gotoxy(20,++y);cout<<"                                 **             ";
				gotoxy(20,++y);cout<<"                                 **             ";
				gotoxy(41,20);cout<<"[ ]";
				gotoxy(42,20);cin>>opc;
				switch(opc)
				{

					case 'a': CrearFactura(); break;
					default :break;
				}

		}while(opc!='b');

	}

	//funcion ejecutar para realizar la erjecucion del programa
	void MenuPrincipal(){
	
			char opc;

			
				do { 
	      		    
	             time_t t;
		     time(&t);
		     struct tm* petm = localtime(&t);
				int y;
				y=10;
				MARCO();
				gotoxy(6,4);cout << "Enter username:";	
				gotoxy(6,5);cout << "Enter password:";
		   		gotoxy(57,7);cout << "Access Granted...";
				gotoxy(52,4);cout <<asctime(petm);
				gotoxy(25,20);cout<<"ENTRE SU OPCION: ";
				gotoxy(20,++y);cout<<"\n\t\ta) -> Modulo Clientes             **   ****     ";
				gotoxy(20,++y);cout<<"\n\t\tb) -> Modulo Almacen             * *  *    * - enous   ";
				gotoxy(20,++y);cout<<"\n\t\tc) -> Modulo Reparacion         *  *  *        SMART  ";
				gotoxy(20,++y);cout<<"\n\t\td) -> Modulo Facturacion       ****** *  ***   DEVICE";
				gotoxy(20,++y);cout<<"\n\t\te) -> Modulo Consultas             *  *    *   SUPPLY. ";
				gotoxy(20,++y);cout<<"\n\t\tf) -> Salir                        *   ****    ";
				gotoxy(41,20);cout<<"[ ]";
				gotoxy(42,20);cin>>opc;		   
				
				switch(opc)
				{

					case 'a': menuClientes(); break;
					case 'b': menuAlmacen();  break;
					case 'c': menuReparacion();break;
					case 'd': menuFacturacion(); break;
					case 'e': MenuConsultas(); break;
					default :break;	
				}
							     	
			    
			}while(opc!='f');	
					    			
		 } 

	void Security(){

		void cPass(char *pass, int longitud);
			char contra[10];

				do{

 			do {
		     time_t t;
		     time(&t);
		     struct tm* petm = localtime(&t);
				int y;
				y=10;
				MARCO();			        

		          	gotoxy(6,4);cout << "Enter username:";
		        			        	
		    		gotoxy(52,4);cout <<asctime(petm);
		                gotoxy(25,20);cout<<"ENTRE SU OPCION: ";
				gotoxy(20,++y);cout<<"\n\t\ta) -> Modulo Clientes             **   ****     ";
				gotoxy(20,++y);cout<<"\n\t\tb) -> Modulo Almacen             * *  *    * - enous   ";
				gotoxy(20,++y);cout<<"\n\t\tc) -> Modulo Reparacion         *  *  *        SMART  ";
				gotoxy(20,++y);cout<<"\n\t\td) -> Modulo Facturacion       ****** *  ***   DEVICE";
				gotoxy(20,++y);cout<<"\n\t\te) -> Modulo Consultas             *  *    *   SUPPLY. ";
				gotoxy(20,++y);cout<<"\n\t\tf) -> Salir                        *   ****    ";    
				gotoxy(41,20);cout<<"[ ]";
				gotoxy(21,4);cin >> userinput;
				
				}while(userinput != username); 		 	
				cout <<"\n";		
				gotoxy(6,4);cout << "Enter username:";	
				gotoxy(6,5);cout << "Enter password:";
				gotoxy(21,5);cPass(contra, 10); 
				 		
				system("cls");
				}while(strcmp(contra,"Smart01") != 0 ); 

				MenuPrincipal();

	}
	
	
	int main(){    // funcion principal

			Security();
			MARCO();
		
			gotoxy(25,13);cout << "QUE TENGA UN BUEN RESTO DEL DIA";
			gotoxy(25,15);system("pause");

			system("cls");
			return 0;
		}
