#include <stdio.h>
#include <stdlib.h>



void newArray(int n, int m, char** array) {

	int i, j;

	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			array[i][j] = '0';
		}
	}
}

int main() {

	int n, m, i, j, fields = 0;
	
	char **tablero;

	char current;

	while( scanf( "%d%d\n", &n, &m ) == 2 ) {
		fields++;
		tablero = malloc(n * sizeof *tablero);
		for (i=0; i<n; i++) {
			tablero[i] = malloc(m * sizeof *tablero[i]);
		}

		newArray(n, m, tablero);

		//printf("%d %d\n", n,m);

		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				scanf("%c", &current);
				if(current == '*') {
									 tablero[i][j] = current;
					if(i > 0) {
									 if(tablero[i-1][j] != '*')    tablero[i-1][j]++;
						if( j > 0)   if(tablero[i-1][j-1] != '*') tablero[i-1][j-1]++;
						if( j < m-1) if(tablero[i-1][j+1] != '*') tablero[i-1][j+1]++; 
					}
					if(j > 0)        if(tablero[i][j-1] != '*')    tablero[i][j-1]++;
					if(j < m-1)      if(tablero[i][j+1] != '*')    tablero[i][j+1]++;
					if(i < n-1) {
						             if(tablero[i+1][j] != '*')   tablero[i+1][j]++;
						if( j > 0)   if(tablero[i+1][j-1] != '*')  tablero[i+1][j-1]++;
						if( j < m-1) if(tablero[i+1][j+1] != '*')  tablero[i+1][j+1]++;
					}

				}
				//printf("%c ", tablero[i][j]);
			}
			scanf("\n");
			//printf("\n");
		}

		if(n>0 && m>0) {
			if(fields > 1) printf("\n");
			printf("Field #%d:\n", fields);
			// A table is in memory
			for(i=0; i<n; i++) {
				for(j=0; j<m; j++) {
					printf("%c", tablero[i][j]);
				}
				printf("\n");
			}	
		}


		//deallocate
		for(i=0; i<n; i++) {
			free(tablero[i]);
		}
		free(tablero);
	}
}