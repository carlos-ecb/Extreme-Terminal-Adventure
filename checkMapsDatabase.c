/* Author: ETA Team *
 * Last Modification: 02/28/2015 by Foo*/

#include <stdio.h>
#include <stdlib.h>
#include "init.h"


int main (){

	int i, j;
	Nivel niveis;
	FILE *arq;

	arq = fopen("maps.bin", "r");

	if(arq == NULL)
		return 0;


	while(fread(&niveis, sizeof(Nivel), 1, arq)){

		printf("\n\nMapa de nivel: %d\nNumero de inimigos no mapa: %d\nIndice: %d\n\n", niveis.nivel, niveis.inimigos, niveis.indice);

		for(i = 0; i < niveis.tamI; i++){
			for(j = 0; j < niveis.tamJ; j++){
				if(niveis.mapa[i][j].player)
					printf("P ");

				else if(niveis.mapa[i][j].wall)
					printf("X ");

				else if(niveis.mapa[i][j].stairs < 0)
					printf("< ");

				else if(niveis.mapa[i][j].stairs > 0)
					printf("> ");

				else if(niveis.mapa[i][j].enemyIndice >= 0)
					printf("E ");

				else if(niveis.mapa[i][j].itemIndice >= 0)
					printf("I ");


				else
					printf("  ");
			}

			printf("\n");
		}
	}

	fclose(arq);

	return 0;

}