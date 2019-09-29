/*******************************************************
Programa error_num.c
Descripcion:
	Imprime lista de errores
********************************************************/

#include <stdio.h>

//extern char *sys_errlist []; No compila
extern __const char *__const sys_errlist[];
extern int sys_nerr;


//Al compilar muestra la salida:
//aviso: `sys_errlist' is deprecated; use `strerror' or `strerror_r' instead
//aviso: `sys_nerr' is deprecated; use `strerror' or `strerror_r' instead

int main () {

	int i;
	
	for (i=0; i < sys_nerr; i++) {

		printf("%d: %s\n", i, sys_errlist[i] );

  }

}
