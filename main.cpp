#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

int main() {
	int tamano;
   char ruta[20];

   system("cls");
	cout<< "Bienvenido\n" << endl;
   cout<< "Digite el nombre del archivo:\t";
   cin>> ruta;
   cout<< "Usted eligio " << ruta << endl;

   FILE *entrada;

   if((entrada = fopen(ruta, "r")) == NULL) {
   	cout<< "Archivo incorrecto...";
      return 0;
   }

   // Tomamos el tamaño de la matriz
   //archivo.getline(tamano, 1, '\n');

	// Leemos el tamaño de la matriz dispersa, suponemos cuadrada
	fscanf(entrada, "%d", &tamano);

   cout<< "Tamaño de la matriz " << tamano << endl;

	float **matriz, *contenido;

	/* memoria para el contenido */
	contenido = (float *) malloc(tamano * tamano * sizeof(float));
	if(!contenido)
   	exit(1);

    // memoria para los punteros a las filas
	matriz = (float **) malloc(tamano * sizeof(float *));
	if(!matriz)
   	exit(1);

	// los punteros apuntan a las filas
	for(int i=0; i<tamano; i++)
   	matriz[i] = contenido + i*tamano;

	// uso como array y como puntero
	for(int i=0; i<tamano; i++)
  		for(int j=0; j<tamano; j++)
      	matriz[i][j] = 0;

   // Leemos los datos
   int h, k, dat;
   while(!feof(entrada)) {
	   // Leemos la primera posicion
  		fscanf(entrada, "%d", &h);
	   // Leemos la segunda posicion
  		fscanf(entrada, "%d", &k);
      // Leemos el dato
		fscanf(entrada, "%d", &dat);
	   matriz[h][k] = dat;
   }

   // Devolvemos el apuntador al principio del archivo
   rewind(entrada);

   // Imprimimos la matriz
	for(int i=0; i<tamano; i++) {
  		for(int j=0; j<tamano; j++)
      	cout<< " " << matriz[i][j];
      cout<< endl;
   }
}
