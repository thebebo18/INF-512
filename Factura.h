
     #include <fstream>
     #include <iostream>
     #include <string>
     #include <iomanip>
     #include <conio.h>
     #include <ctime> 

     using namespace std;

     #include "Producto.h"

     Producto p;
     int cantidad = 0;
	 
	 int y =20, x, w = 32, z = 26;   //variables de posicionamiento
	 double importe_1 = 0.0, sub_total = 0.0;
	 
	 
     double total;
     float itbis, descuento, interes; 
     unsigned nfc = 127931098;
     char resp;
	 string condicion_1;
	 double sub_total_1;
	 
	 

     class Factura {

      private:
		 
         string nombre;
         string vendedor;
         string direccion;
         string condicion;
         unsigned int cedula;
         unsigned telef;

      public:
         Factura();
         Factura(string, string, string, string, unsigned int, unsigned);
         
         //void set_Datos();
         string getnombre();
         string getvendedor();
         string getdireccion();
         string getcondicion();
         unsigned int getcedula();
         unsigned getelefono();
         void BuscarProducto();    //Buscador de productos
         void CrearFactura();
     
  	 };
   
         Factura::Factura(){  }
            

  		Factura :: Factura(string nom, string ven, string dir, string con, unsigned int ced, unsigned tel)  
            {                                
      
          nombre = nom;
          vendedor = ven;
          direccion = dir;
          condicion = con; 
          cedula = ced;
          telef = tel;         
                          }

        void Factura::CrearFactura()                  
             {  Factura d;
	do {
             system("cls");
        time_t t;
        time(&t);
        struct tm* petm = localtime(&t);

       gotoxy(2,5);
       cout << " 4G-enious Smart Supply" << endl;
       gotoxy(2,6);
       cout << " Direccion:. C\ Proyecto 17 #3," ;
       gotoxy(2,7);
       cout << " Los Frayles. Santo Domingo. Rep Dom" << endl;
       gotoxy(2,8);
       cout << " Tel.: 809-681-7656, Celular.: 829-540-7855 " << endl;
       gotoxy(10,10);
       cout << " FACTURA A ";
       gotoxy(2,13);
       cout << " Facturado a:          ";
       gotoxy(2,15);
       cout << " Direccion de:         ";
       gotoxy(49,13);
       cout << " RNC/CED:";
       gotoxy(49,15);
       cout << " Telefono:            ";
       gotoxy(49,6);
       cout << " RNC: 2-50299-4" << endl;
       gotoxy(49,7);
       cout << " NFC: A01010102001773" << endl;
       gotoxy(49,5);
       cout << " Factura de consumidor Final" << endl;
       gotoxy(49,9);
       cout << " Numero: EA5698 " << endl;
       gotoxy(49,8);
       cout << " Fecha:" << asctime(petm) << endl;
       gotoxy(2,17);
       cout << " ******************************************************************************" << endl;
       gotoxy(2,19);
       cout << " ******************************************************************************" << endl;
       gotoxy(2,18);
       cout << " codigo" << endl;
       gotoxy(15,18);
       cout << " Referencia" << endl;
       gotoxy(45,18);
       cout << " Cant " << endl;
       gotoxy(54,18);
       cout << " Precio Unidad" << endl;
       gotoxy(72,18);
       cout << " Importe" << endl;

    	 int y = 28;
	 y++;
       gotoxy(10,y);
       cout << " Cliente:___________         Vendedor:          \n";                                    
      
      //  gotoxy(10,y);
       cout << " \n\t ******************************* FIN ******************************* \n"
            << "\n\t\t => Gracias por su compra, esperamos su visita... " << endl;
            

	   

             gotoxy(21,10);
             cin >> condicion_1;
			 
             gotoxy(15,13);
             getline (cin, nombre);

             gotoxy(16,15);
             getline (cin, direccion);
             
             gotoxy(59,13);
             cin >> cedula;
            
             gotoxy(59,15);
             cin >> telef;
	    
	     d.BuscarProducto();
	     
             gotoxy(48,29);
             cin >> vendedor;
             
             /*total = precio * cantidad;
               total0 = descuento * total;
               total1 = total - total0;
               total2 = itbis * total1;    */
               
            cout << "\n\n\t => Desea Imprimir la Factura y generar Otra? ";
	    cin >> resp;
	    
	     }while(resp == 'S' || resp == 'S');
               }
              

            string Factura :: getnombre()
               {

                 return nombre;
               }
            string Factura :: getvendedor()
               {
	         return vendedor;

               }
            string Factura :: getdireccion()
               {
                 return direccion;

               }
            unsigned int Factura :: getcedula()
               {
                  return cedula;

               }
            string Factura :: getcondicion()
               {
                  return condicion;

               }
            unsigned Factura :: getelefono()
               {
                  return telef;

               }
            
                          
                
         //void Factura::get_Datos() { }
         

	 void Factura :: BuscarProducto()
	    	{
	    	
	  do{
		int posicion;
			
	 fstream Lectura("PRODUCTOS.bin", ios::in | ios::binary);
	 
	 if(Lectura.fail()){
	   cerr << "ERROR!, Archivo no existe, termina proceso, Pulse <ENTER>" << endl;
	   system("pause");
	   exit(1);
	 }

	 unsigned long longarchivo;
	 Lectura.seekg(0, ios::end); 
	 longarchivo = Lectura.tellg(); 
	    
	 Lectura.seekg(0, ios::beg);

		   					
	 char respuesta;
	 unsigned numreg;
					
		
		
		//do{
			//textbackground(07);
			
			gotoxy(4,y);cin>>numreg;
				
			
			
	    if( numreg <= 200 || cin.fail()) { 
		cout << "\n\n=> Error en el dato, Termina ejecucion!!\n"
		     << "\n=> Pulse una tecla... ";
		getch();
		cout << endl;
		exit(1);
	    }
	      
	    else if( numreg > longarchivo/sizeof(Producto)+ 200 ){ 
		cout << "\n\n=> Error en el dato, Termina ejecucion!!\n"
		     << "\n=> Pulse una tecla... ";
		getch();
		cout << endl;
		exit(1);
	    }

	    
	     Lectura.seekg((numreg -  + 200)* sizeof(Producto));
	     
	     Producto t;
	     
	     if ( (unsigned long)Lectura.tellg() < longarchivo + 200) {
		  
		     Lectura.read( (char*)(&t), sizeof(Producto));

		  
	      gotoxy(12,y);cout<< t.nombre;
	      gotoxy(26,y);cout<< t.descripcion;
	      gotoxy(58,y);cout<< t.precio;
		 
	      gotoxy(47,y);cin >> cantidad; 
		   
		  importe_1 = cantidad * t.precio;
		  
		  gotoxy(74,y);cout<< fixed << setprecision(2) << importe_1;		  
		  
		  sub_total += importe_1;
		  		     
		   sub_total_1 = sub_total;
		   	
	     }
	     else { 
		 
	       cout << "\n\t No hay mas registro para mostrar. \n";
	       system("pause");
	       exit(1); 
	     }	 
	     
		gotoxy(31,33);cout << "\n Otro producto? [S/N]: ";
		cin >> re; 
		
              			          y++;
					  w++;
					  //z -=3;
		Lectura.close();
		
                }while( re == 'S'  ||  re == 's'  );
				
		if (condicion_1 == "contado")
       			 {  
		   
		   gotoxy(65,z);
		   cout <<"sub-total "<< setprecision(2) << sub_total;
		   
		   descuento =(sub_total * 0.05); 
		   sub_total_1-= descuento;
		   itbis = (sub_total * 0.18);
		   
		   total = sub_total_1 += itbis;
		   
		  
		   z++;
		   gotoxy(65,z);
		   cout <<"descuento " << setprecision(2) << descuento;
		   
		   z++;
		   gotoxy(65,z);
		   cout <<"itbis "<<  setprecision(2) << itbis;
		   
		   z++;
		   gotoxy(65,z);
		   cout <<"total "<<  setprecision(2) << total;
		  
		}else (condicion_1 == "credito");
			{
		   gotoxy(65,z);
		   cout <<"sub-total "<< setprecision(2) << sub_total;
		   
		   interes =(sub_total * 0.07); 
		   itbis = (sub_total * 0.18);
		   
		   total = sub_total_1 + itbis + interes;
		   
		  
		   z++;
		   gotoxy(65,z);
		   cout <<"interes " << setprecision(2) << interes;
		   
		   z++;
		   gotoxy(65,z);
		   cout <<"itbis "<<  setprecision(2) << itbis;
		   
		   z++;
		   gotoxy(65,z);
		   cout <<"total "<<  setprecision(2) << total;



			}
                
				 
	    }		   
				
    // int main () { 
			
         // f.set_Datos();
          
       // return 0;

   // };
