
	#ifndef REPARACIONES_H
	#define REPARACIONES_H

	using namespace std;

	class Reparaciones 
	{

		private:
			char tipo[30];
			char modelo[30];
			char problema[30];
			char solucion[30];
			double costo_de_reparacion;
		 
		public:
		    Reparaciones();

			void setDatos();
			void leerArchivos();
			string getTipo();
			string getModelo();
			string getProblema();       
		
	};
	

	Reparaciones :: Reparaciones(){}

	void Reparaciones :: setDatos()
		{
		    
		
			fstream reparacionEntrada("reparaciones.dat", ios::out|ios::binary|ios::ate);
	       		 Reparaciones rep;
		
			int y(10);
			MARCO();
			cin.ignore();
			gotoxy(20,++y);cout << "INGRESE LOS SIGUIENTES CAMPOS:";
				
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
			MARCO();
			char opcion;
			int y;

			Reparaciones c; 
			y=10;
					
			gotoxy(20,++y);cout<<"a) DESEA VER REGISTRO REPARACIONES. S/N";
			gotoxy(20,13);cout<<"";
			gotoxy(50,11);cout<<"[ ]";
			gotoxy(51,11);cin>>opcion;
		
			fstream Leer("reparaciones.dat", ios::in | ios::binary);

		    if(opcion=='s')

		    {
		        system("cls");

		        Leer.read(reinterpret_cast <char *> (&c), sizeof(Reparaciones));
		      
				while(! Leer.eof() )

		        {
				
		        cout << "\n\tDATOS DEL REPARACIONES";
			cout << "\n\t===============================";
			cout << "\n\t-TIPO: " << c.tipo << endl;
		        cout << "\n\t-MODELO: " << c.modelo << endl;
		        cout << "\n\t-PROBLEMA: " << c.problema << endl;
			cout << "\n\t-solucion: " << c.solucion << endl;
			cout << "\n\t===============================";
			cout << "\n\n " << endl;

			Leer.read(reinterpret_cast <char *> (&c), sizeof(Reparaciones));

		        }

				Leer.close();    

				system("\t pause");

				}
				else if(opcion!='a'){
			
						gotoxy(20,++y);cout<<"OPCION NO VALIDAD.";
						gotoxy(20,++y);system("pause");
					}
			
				}   
	#endif;
