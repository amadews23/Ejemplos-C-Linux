/*******************************************************
Programa escribir.c
Descripcion:
  Usado para escribir texto en tuberia con nombre
  Comunicacion half-duplex
Forma de uso:
  $ ./escribir
  escribimos el texto a enviar
  para salir:
  $ exit
********************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


#define MAX 256

/*Macro para comparar dos cadenas de caracteres*/
#define EQ(str1, str2) (strcmp ((str1), (str2)) == 0)

char mensaje[MAX];

int main() {

  FILE *myfifo;
  char buffer[MAX];
  int i=0;

  /* Creamos la tuberia con nombre*/
  // S_IWUSR Usuario puede escribir 
  // S_IRUSR Usuario puede leer 
  // S_IRGRP Grupo puede leer   
  // S_IROTH Otros pueden leer   
  if (mkfifo("myfifo", S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH )!=0)

    printf ("La tuberia ya fue creada anteriormente\n");
  
  myfifo=fopen("myfifo", "w"); // Abrimos la tuberia

  do {

      scanf("%s", &mensaje); //solicitamos texto
      sprintf(buffer, "> %s\n", mensaje); //anyadimos el texto al bufer + /n
      fputs(buffer, myfifo); //insertamos el texto en la tuberia 

  } while (!EQ(mensaje, "exit")); //comparamos el texto del mensaje con exit (para dejar de "capturar")

  printf("FIN DE TRANSMISION.\n");

  fclose(myfifo);       //Cerramos la tuberia

}
