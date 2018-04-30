	#include <iostream>
	#include <fstream>
	#include<vector>
	#include <ctype.h>
	#include<conio.h>
	#include<ctime.h>
	
	using namespace std;

	#include "Producto.h"

		int main()
		{

		Producto u;

			u.IngresarProducto(); // Ingresar un cliente al menu
			u.VerProducto();  //Mostrar Cliente
			u.BuscarProducto();  // Buscar cliente por posicion
			//u.consulta();//ejecutar();
			system("pause");
			return 0;
		}

