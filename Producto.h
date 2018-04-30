

		#ifndef Producto_h
		#define Producto_h
		#include "marco.h"		

		class Producto
		{
			public: 
				char nombre[30];
				char descripcion[30];
				int cod_Prod;
				double precio;

			public:
				void IngresarProducto();
				void VerProducto();
				void BuscarProducto();
				void consulta();
		};
	char re;
	unsigned long Prod;
	
	void Producto::IngresarProducto()
	{
		system("cls");
		Producto po;		
		
		fstream Escribir("PRODUCTOS.bin", ios::out | ios::binary | ios::ate);

		if (Escribir.fail()) {
		
			cout << "\n=> ERROR !, El Archivo no exite aun"
			<< "\n\n=> Pulse una tecla para continuar... ";
			getch();  
			cout << "\n\n";
			exit(1);
			
            }
		else
		{
			do
                {     
                         
             		 
				cout << "\n===============================";
				
				cout<<"\n- NOMBRE DEL PRODUCTO: "<<">>";
				cin >> po.nombre;
				
                		cout<<"\n- DESCRIPCION DEL PRODUCTO: "<<">>";
				cin >> po.descripcion;
				
               			//cout<<"\n- CODIGO DEL PRODUCTO: "<<">>";
				//cin >> po.cod_Prod;
				
				cout<<"\n- PRECIO DEL PRODUCTO: "<<">>";
				cin >> po.precio;

				Escribir.seekg(0, ios::end); // Posiciona el puntero al final
         	  		Prod = Escribir.tellg(); /* Obtiene la posicion actual, que no es
                                mas que la longitud de archivo hasta ese momento. */
        	  		Escribir.seekg(0, ios::beg); 
		 		po.cod_Prod = (Prod/sizeof(Producto)) + 200;
		  
		 
         			  // ESCRIBIMOS EN EL ARCHIVO EL REGISTRO CAPTURADO 
         			Escribir.write(reinterpret_cast <char *> (&po), sizeof(Producto)); 
         	
				//Escribir.write((char*)(&po), sizeof(Producto));

				cout << "\n\n DESEA  INGRESAR OTRO PRODUCTO ? S/N:   \n";
				cin >> re;

                }while( re == 'S'  ||  re == 's'  );
			Escribir.close();
		}
	
	}   

	void Producto :: VerProducto()  
        {
		system("cls");
		char opcion;
		Producto p; 
		
		cout <<"\n\t\t**********************************************";
		cout <<"\n\t\t ==>> DESEA VER TODOS LOS Productos. ?     <== ";
		cout <<"\n\t\t**********************************************";
		gotoxy(54,3);
		cout << "[ ]";
		gotoxy(55,3);
		cin>>opcion;

		fstream Leer("PRODUCTOS.bin", ios::in | ios::binary);
            if(opcion=='s' || opcion =='S')
            {

                system("cls");
                Leer.read(reinterpret_cast <char *> (&p), sizeof(Producto));

			while(! Leer.eof() )
                {
	                               
                cout<<"\n\n\t\t DATOS DEL PRODUCTO";
		cout<< "\n\t=====================================";
		cout<< "\n\t=> NOMBRE: " << p.nombre << "\n" ;
                cout<< "\n\t=> DESCRIPCION: " << p.descripcion  << "\n" ;
                cout<< "\n\t=> CODIGO: " << p.cod_Prod  << "\n" ;
		cout<<"\n\t=> PRECIO: " << p.precio  << "\n" ;
                cout<< "\n\t-FECHA : "; system("date/t");                     
		cout<< "\n\t====================================\n";
		
		Leer.read(reinterpret_cast <char *> (&p), sizeof(Producto));
                }

			Leer.close();    
			system("pause");

            }
			
	    } 

	    void Producto :: BuscarProducto()
	    	{
			do{
		int posicion;
		MARCO();		
			    
	
	 fstream Lectura("PRODUCTOS.bin", ios::in | ios::binary);
	 
	 if(Lectura.fail()){
	   cerr << "ERROR!, Archivo no existe, termina proceso, Pulse <ENTER>" << endl;
	   system("pause");
	   exit(1);
	 }

	MARCO();
	 unsigned long longarchivo;
	 Lectura.seekg(0, ios::end); 
	 longarchivo = Lectura.tellg(); 
	    
	 Lectura.seekg(0, ios::beg);
		   					
			   gotoxy(20,10);cout<< "total de registros : " 
			   << longarchivo/sizeof(Producto) << endl;


	 char respuesta;
	 unsigned numreg;
					
		int y(10);
					
			gotoxy(20,++y);cout<<"a) DIGITE EL CODIGO DEL PRODUCTO QUE DESEA VER.";
			gotoxy(67,11);cout<<"[   ]";
			gotoxy(68,11);cin>>numreg;
		
	    
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

	    //else cout << "      " << endl; 

	     Lectura.seekg((numreg -  + 200)* sizeof(Producto));
	     
	     Producto t;
	     
	     if ( (unsigned long)Lectura.tellg() < longarchivo + 200) {
		  
		     Lectura.read( (char*)(&t), sizeof(Producto));
		 
	       cout << "\n\t=====================================";
	       cout << "\n\t\t MOSTRANDO PRODUCTO ";
	       cout << "\n\t=====================================";
	       cout << "\n\t Nombre: " << t.nombre
		    << "\n\t descripcion: " << t.descripcion
		    << "\n\t codigo: " << t.cod_Prod 
		    << "\n\t Precio: " << t.precio 
		    << "\n\t=====================================" << endl;
		    
	     }
	     else { 
		 
	       cout << "\n\t No hay mas registro para mostrar. \n";
	       system("pause");
	       exit(1); 
	     }
	     
		cout << "\n\t DESEA  INGRESAR OTRO PRODUCTO ? S/N: ";
		cin >> re;

		Lectura.close();
		
                }while( re == 'S'  ||  re == 's'  );
                
			system("pause");
	   
			
	 
	    }
	
		/*void Producto :: consulta()
	  {
	  
	  Producto p;
	  char C;
	  int F,codigo;
	  
	  ifstream DATOS("PRODUCTOS.bin");
	  if (DATOS.fail())
	    {
	    gotoxy(26,12); cout << "\n Este archivo no existe.\n"; 
		getch();
	    }
		DATOS.close();
	       
		    MARCO();
			do{
		    gotoxy(30,6); cout << "CONSULTA POR CODIGO";
		    gotoxy(40,9); cin >> codigo;
		
		    while (! DATOS.eof() )
		       {
			   ifstream DATOS("PRODUCTOS.bin");
		       DATOS.read((char *) &p, sizeof(Producto));
			   
		       if (codigo == p.cod_Prod)
			  {
			   
			   gotoxy(13,10); cout << "codigo: " << p.cod_Prod;                           
			   gotoxy(40,11); cout << "nombre: " << p.nombre;
			   gotoxy(40,12); cout << "descripcion: " << p.descripcion;
			   gotoxy(40,13); cout << "precio: " << p.precio;
			   
			  }
			  
			if (DATOS.eof())
			   {
				gotoxy(16,12); cout <<"\n\t EL PRODUCTO NO EXISTE!!\n";
				getch();
			   }
			   
			   DATOS.close();
		      }
			  cout << "\ndesea buscar otro articulo\n";
			  cin >> re;
			 }while(re=='s'||re=='S');
			 
	      }	     */
		  
			#endif;
