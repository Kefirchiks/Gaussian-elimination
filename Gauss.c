#pragma hdrstop
#pragma argsused
#pragma package(smart_init)
/****************/
#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <stdlib.h>
/*******************************************************************
*	Gaussian-Jordan elimination script                             *
*   Written in C                                                   *
*          by Klāvs Ceicāns                                        *
*         	(Github - Kefirchiks | https://github.com/Kefirchiks ) *
********************************************************************
*	SHARING IS CARING											   *
********************************************************************
*/
int n;
float a[3][4]; // [3] - line count ; [4] - number of elements in line

void Izvade();
void Reizinasana();
void Izslegsana();
void Gauss();

int main() {
	int i, j;

	FILE *fin = fopen("gauss.in", "r"); // Execute 'gauss.in' file

	fscanf(fin, "%d", &n);
	for (i = 0; i < n; ++i)
		for (j = 0; j < n + 1; ++j)
			fscanf(fin, "%f", &a[i][j]);

	fclose(fin);

	printf("\t Klavs Ceicans P2-4");
	printf("\n\t Patstavigais darbs nr.2");
	printf("\n\t Gausa metode\n\n");

	Izvade();
	Gauss();

	return EXIT_SUCCESS;
}
void Izvade() {
	int i,j;

	for (i = 0; i < n; ++i) {
		if (i != 1)
			printf("	|	");
		else
			printf("	#	");

	for (j = 0; j < n + 1; ++j){
		if(j == 3) printf("= "); // 3 elements + 4th after = sign
								 /*******************************
								 For example:
								 0.48 + 0.23 + 0.37 = 1.44 <- 4th element
								 ********************************/
	printf("%.4f\t", a[i][j]);
	}
	printf("\n");
	}
	printf("\n");
	getch();
}
void Dalisana() {
	int i, j, k, max;
	float t;
	for (i = 0; i < n; ++i){
		max = i;
		for (j = i + 1; j < n; ++j)
			if (a[j][i] > a[max][i])
				max = j;
		for (j = 0; j < n + 1; ++j) {
			t = a[max][j];
			a[max][j] = a[i][j];
			a[i][j] = t;
		}
		for (j = n; j >= i; --j)
			for (k = i + 1; k < n; ++k) {
			a[k][j] -= a[k][i]/a[i][i] * a[i][j];
						Izvade();
		}
	}
}
void Izslegsana() {
	int i, j;
	for (i = n - 1; i >= 0; --i) {
		a[i][n] = a[i][n] / a[i][i];
		a[i][i] = 1;

		Izvade();

		for (j = i - 1; j >= 0; --j) {
			a[j][n] -= a[j][i] * a[i][n];
			a[j][i] = 0;
		}
		if (i == 0)
			printf("	Atbilde:\n\n");
			Izvade();
	}
}
void Gauss(){
	Dalisana();
	Izslegsana();
}

