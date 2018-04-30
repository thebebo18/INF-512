

	#ifndef Cliente_H
	#define Cliente_H
	
	class Cliente {
		
	 private:

	     unsigned long Codigo_C; 
	     char nombre[30];
	     char apellido[30];
	     char direccion[30];
	     unsigned long cedula;  //  4 bytes, rango  0 to 4294967295
	     char Email[30];
	     char sexo;   //1 byte

	  public:
	     void ingresarCliente();
	     void verCliente();
	     void BuscarCliente();

	};

	#endif
