#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_P	30

int	pila[ MAX_P+2 ], pila_original[ MAX_P+2 ];
int	tamanyo;

void procesa_linea( char *s )
{
	int		i;
	char	*p;
	tamanyo=0;

	while( *s != '\0' ) {
		
		while( *s != '\0'  &&  !isdigit( *s ) ) s++;
		p=s;
		while( *s != '\0'  &&  isdigit( *s ) ) s++;
		*s='\0';
		if ( p < s ) pila[tamanyo++] = atoi( p );
		s++;
	}

	for( i=0; i < tamanyo; i++ ) pila_original[tamanyo-1-i] = pila[i];
	for( i=0; i < tamanyo; i++ ) pila[i] = pila_original[i];
}

void guarda_original()
{
	int	i;

	for( i=tamanyo-1; i >= 0; i-- ) fprintf( stdout, " %d", pila[i] );
	fprintf( stdout, "\n" );
}

void flipa( int n )
{
/* Se puede invocar dentro de ordena() para simplificar */
	int i,j, aux;
	for(i=n, j=0; j<(tamanyo-n)/2;i++,j++) {
		aux = pila[i];
		pila[i] = pila[tamanyo-1-j];
		pila[tamanyo-1-j] = aux;
	}
}


void ordena()
{
/* Debe mostrar la secuencia de cambiazos */
/* Es casi un ordenación por selección directa */
	int i, j, Imax, halt = 0;
	if(tamanyo > 1) {
		for(i=0; i<tamanyo-1 && !halt; i++) {

			for(j=i, Imax=i; j<tamanyo; j++) {
				//printf("%d",pila[j]);
				if(pila[j] > pila[Imax]) {

					Imax = j;
				}
			}
			//printf("Imax:%d",Imax);
			//printf("tamanyo:%d",tamanyo);
			if(Imax == tamanyo-1) {
				printf(" %d", i+1);
				flipa(i);
			} else if(Imax != i) {
				printf(" %d", Imax+1);
				flipa (Imax);
				printf(" %d", i+1);
				flipa (i);
			}

		}
	}

}

int main( int arc, char *argv[] )
{
	char	buffer[1024];

	while( fgets( buffer, 1020, stdin ) != NULL ) {
		procesa_linea( buffer );
		guarda_original();
		ordena();
		fprintf( stdout, " 0\n" );
	}

	return 0;
}