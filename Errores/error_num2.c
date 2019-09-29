/********************************************************
* NOMBRE: #Bartolome#
* PRIMER APELLIDO: #Vich#
* SEGUNDO APELLIDO: #Lozano#
* EMAIL: #amadews23@hotmail.com#
********************************************************/
/*******************************************************
Programa error_num2.c
Descripcion:
	Imprime lista de errores
********************************************************/


#include <stdio.h>
#include <string.h>

int main(void) {

    int i;

    for (i=0 ; i < 135; i++) {

    	printf("%s\n",strerror(i));
	}

}
