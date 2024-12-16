#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */


int eliminate(Matrix *mat, Matrix *b){
	/**
	   * Tutaj należy umieścić właściwą implemntację.
		 */

	int n = mat->r; // Liczba wierszy macierzy A

	for (int k = 0; k < n - 1; k++) {
		// Sprawdzenie czy element główny (pivot) jest różny od 0
		if ((mat->data[k][k])==0) {
			return 1;
		}

		// Zerowanie elementów poniżej pivotu w kolumnie k
		for (int i = k + 1; i < n; i++) {
			double mnoznik = mat->data[i][k] / mat->data[k][k];
			for (int j = k; j < n; j++) {
				mat->data[i][j] -= mnoznik * mat->data[k][j];
			}
			b->data[i][0] -= mnoznik * b->data[k][0];
		}
	}

	return 0;
}


