#include <iostream.h>

void main(){

	int matrizA[3][3];
	int matrizB[3][3];
	int i,j;

	// Recolectamos los datos de la matriz A
	for(i=0; i < 3; i++)
		for(j=0; j < 3; j++) {
			cout<< "\nDigite el elemento A " << i << "," << j << ": \t";
			cin>> matrizA[i][j];
		}

	// Recolectamos los datos de la matriz B
	for(i=0; i < 3; i++)
		for(j=0; j < 3; j++) {
			cout<< "\nDigite el elemento B " << i << "," << j << ": \t";
			cin>> matrizB[i][j];
		}

	cout<< "\n\nLa suma de las matrices es:" << endl;
	
	// Sumamos las matrices A y B
	for(i=0; i < 3; i++) {
		for(j=0; j < 3; j++) {
			cout<< matrizA[i][j] + matrizB[i][j] << "\t";
		}
		cout<< endl;
	}

}