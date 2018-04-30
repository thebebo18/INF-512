
	#ifndef MARCO_H
	#define MARCO_H
	
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
	
	using namespace std;
	
	//*****************MARCO PRINCIPAL**********
	
	void MARCO()
	{

	int I;
	clrscr();
	textcolor(128);
	gotoxy(34,5);cputs(" Bienvenido a ");
	textcolor(05);
	gotoxy(28,6);cputs("*************************");
	textcolor(03);
	gotoxy(28,7);cputs("* 4G-enius Smart Supply *");
	textcolor(02);
	gotoxy(28,8);cputs("* 4G-enius Smart Supply *");
	textcolor(05);
	gotoxy(28,9);cputs("*************************");
	
	for(I=2;I<=76;I++)
	{
	textcolor(14);
	gotoxy(I,2);cprintf("**");
	gotoxy(I,24);cprintf("**");
	} //CIERRA FOR
	for(I=2;I<=77;I++)
	{
	gotoxy(I,3);cprintf("**");
	gotoxy(I,25);cprintf("**");
	} //CIERRA FOR */
	
	for(I=2;I<=25;I++)
	{
	
	gotoxy(2,I);cprintf("<**>");
	gotoxy(76,I);cprintf("<**>");
	}//CIERRA FOR
	
   }//CIERRA FUN MARCO

	#endif
