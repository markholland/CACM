#include <stdio.h>
#include <stdlib.h>

#define MAX_PEOPLE 1000
#define MAX_CROSSING 2


void ordenar(int *array, int n) {

	int i, j, z, min, max;

	min = max = array[0];
	for(i=1; i<n; i++) {
		if(array[i] < min) {
			min = array[i];
		} else if( array[i] > max ) {
			max = array[i];
		}
	}

	int range = max - min + 1;
	int *count = malloc(range * sizeof(*array));

	for(i = 0; i < range; i++) count[i] = 0;
	for(i = 0; i < n; i++) count[ array[i] - min ]++;

	for(i = min, z = 0; i <= max; i++) {
		for(j = 0; j < count[i - min]; j++) {
			array[z++] = i;
		}
	}

	free(count);

}

int main (int argc, char* argv[]) {
	
	int personas[MAX_PEOPLE];
	int movimientos[MAX_PEOPLE+1][MAX_CROSSING];
	int casos, tiempo_persona, num_personas;
	int i, j, n, A, B, C, D;
	int count_movimientos, cost;
	char buf[100];

	scanf("%d", &casos);
	fgets(buf, 120, stdin);
	//printf("%d\n", casos);

	// loop cases
	while( --casos >= 0 ) {
		num_personas = 0;
		// while( scanf("%d", &tiempo_persona) == 1 ) {
		// 	personas[num_personas++] = tiempo_persona;
		// 	hayPersonas=1;		
		// }
		//printf("iCasos: %d\n",iCasos);
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d", &tiempo_persona);
			personas[num_personas++] = tiempo_persona;
		}
		
		ordenar(personas, num_personas);
		// for(i=0;i<num_personas;i++) {
		//  	printf("%d\n", personas[i]);
		// }

		for(i=0;i<MAX_PEOPLE+1;i++) {
			for(j=0;j<MAX_CROSSING;j++) {
				movimientos[i][j]=0;
			}
		}
	
		A = 0;
		B = A + 1;
		D = num_personas - 1;
		C = D - 1;
		count_movimientos = 0;

		while(num_personas > 0) {
			//printf("p:%d\n",num_personas);
			//printf("m:%d\n",count_movimientos);
			// if not 4 left
			if(num_personas == 1) {
					movimientos[count_movimientos++][0]	= personas[A]; // -> A
					num_personas--;
			}
			else if(num_personas == 2) {
			 	movimientos[count_movimientos][0]   = personas[A];	// -> A+D
			 	movimientos[count_movimientos++][1]	= personas[D];
			 	num_personas-=2;
			} 
			else if(num_personas == 3) {
				movimientos[count_movimientos][0]   = personas[A];	// -> A+D
				movimientos[count_movimientos++][1]	= personas[D];  
				movimientos[count_movimientos++][0] = personas[A];	// <- A
				movimientos[count_movimientos][0]   = personas[A];	// -> A+B
				movimientos[count_movimientos++][1] = personas[B];
				num_personas = 0;
			}
			else if(personas[C] + personas[A] >= 2*personas[B]) {
				movimientos[count_movimientos][0]   = personas[A]; // -> A+B
				movimientos[count_movimientos++][1] = personas[B];
				movimientos[count_movimientos++][0] = personas[A]; // <- A
				movimientos[count_movimientos][0]   = personas[C]; // -> C+D
				movimientos[count_movimientos++][1] = personas[D];
				movimientos[count_movimientos++][0] = personas[B]; // <- B
				movimientos[count_movimientos][0]   = personas[A]; // -> A+B
				movimientos[count_movimientos++][1]	= personas[B];
				num_personas -= 4;
				if(num_personas !=0) {
					movimientos[count_movimientos++][0]	= personas[A]; // <- A
				}
				
				C -= 2;
				D -= 2;
			}
			//} 
			// else if(num_personas == 2) {
			// 	movimientos[count_movimientos][0]   = personas[A];	// -> A+B
			// 	movimientos[count_movimientos++][1] = personas[B];
			// 	num_personas = 0;
			// } else if(num_personas == 1) {
			// 	movimientos[count_movimientos++][0]	= personas[A]; // -> A
			// 	num_personas = 0;
			else {
				movimientos[count_movimientos][0]   = personas[A];	// -> A+D
				movimientos[count_movimientos++][1]	= personas[D];  
				movimientos[count_movimientos++][0] = personas[A];	// <- A
				movimientos[count_movimientos][0]   = personas[A];	// -> A+C
				movimientos[count_movimientos++][1] = personas[C];
				movimientos[count_movimientos++][0] = personas[A];	// <- A
				movimientos[count_movimientos][0]   = personas[A];  // -> A+B
				movimientos[count_movimientos++][1] = personas[B];
				num_personas -= 4;
				if(num_personas !=0) {
					movimientos[count_movimientos++][1]	= personas[A]; // <- A
				}
				C -= 2;
				D -= 2;
			}
		}

		//if(hayPersonas)
		cost = 0;

		//printf("count: %d\n",count_movimientos);
		
		for(i=0; i<count_movimientos; i++) {
			//printf("%d\n", cost);
			if(movimientos[i][0] > movimientos[i][1]) {
				cost += movimientos[i][0];
			} else {
				cost += movimientos[i][1];
			}
		}

		printf("%d\n", cost);
		//printf("count: %d\n",count_movimientos);
		for(i=0;i<count_movimientos;i++) {
			for(j=0;j<2;j++) {
				if(movimientos[i][j] != 0) {
					printf("%d ",movimientos[i][j]);
				}
			}
			printf("\n");
		}
		if(casos>0)
		 	printf("\n");
	}

}