/********************************************************
* NOMBRE: #Bartolome#
* PRIMER APELLIDO: #Vich#
* SEGUNDO APELLIDO: #Lozano#
* EMAIL: #amadews23@hotmail.com#
********************************************************/
/*******************************************************
Programa leer.c
Descripcion:
  Usado para escribir texto en tuberia con nombre
  Comunicacion half-duplex
Forma de uso:
  $ ./leer
  leera el mensaje completo cuando desde el otro programa
  pulse exit. 
********************************************************/


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX 256

int main() {

  FILE *myfifo;
  char buffer[MAX];

  myfifo=fopen("myfifo", "r"); //Abrimos la tuberia 

  /* Leemos la tubería */
  while (!feof(myfifo))      
    {
      if (fgets(buffer, MAX, myfifo))
      printf ("RECIBIDO: %s", buffer);

    }

  fclose(myfifo); 
}
