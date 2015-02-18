#include <stdio.h>
#include <stdlib.h>

#define MAX_PEOPLE 1001
#define MAX_CROSSING 2


void ordenar(int *array, int n);

int next_time(int personas[], int num_personas) {

	int A = personas[0];
	int B = personas[1];
	int C = personas[num_personas - 2];
	int D = personas[num_personas - 1];

	if(num_personas == 1) {
		return A;
	}

	if(num_personas == 2) {
		return B;
	}

	// -> A+D <- A -> A+B
	if(num_personas == 3) {
		return D + A + B;
	}

	// 2 possible strategies with 4 or more
	if( 2 * B < (A + C)) {
		return A + 2 * B + D + next_time(personas, num_personas - 2);
	} else {
		return 2 * A + C + D + next_time(personas, num_personas - 2);
	}
}

void print_movements(int personas[], int num_personas) {

	int A = personas[0];
	int B = personas[1];
	int C = personas[num_personas - 2];
	int D = personas[num_personas - 1];

	//printf("num:%d\n",num_personas);

	if(num_personas == 1) {
		printf("%d\n", A);
		return;
	}

	if(num_personas == 2) {
		printf("%d %d\n", A, B);
		return;
	}

	if(num_personas == 3) {
		printf("%d %d\n%d\n%d %d\n",A, D, A, A, B);
		return;
	}

	if( 2 * B < ( A + C )) {
		printf("%d %d\n%d\n%d %d\n%d\n", A, B, A, C, D, B);
	} else {
		printf("%d %d\n%d\n%d %d\n%d\n", A, D, A, A, C, A);
	}

	print_movements(personas, num_personas - 2);

}

int main (int argc, char* argv[]) {
	
	int personas[MAX_PEOPLE];
	int casos, tiempo_persona, num_personas;
	int i, j, total_time;
	
	char buf[100];

	scanf("%d", &casos);
	fgets(buf, 120, stdin);
	//printf("%d\n", casos);

	// loop cases
	while( casos-- ) {
		
		scanf("%d", &num_personas);
		//printf("num_personas:%d\n", num_personas);
		for(i = 0; i < num_personas; i++) {
			scanf("%d", &tiempo_persona);
			personas[i] = tiempo_persona;
		}
		
		ordenar(personas, num_personas);
		
		total_time = next_time(personas, num_personas);

		printf("%d\n", total_time);

		print_movements(personas, num_personas);

		if(casos) {
			printf("\n");
		}	
	}

	return 0;

}

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
	int count[MAX_PEOPLE];

	for(i = 0; i < range; i++) count[i] = 0;
	for(i = 0; i < n; i++) count[ array[i] - min ]++;

	for(i = min, z = 0; i <= max; i++) {
		for(j = 0; j < count[i - min]; j++) {
			array[z++] = i;
		}
	}

}