#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

void 
deal_in(int op, int *opcode, int *d, int *s) 
{ 
	*s = op%10; 
	op /= 10; 
	*d = op%10; 
	op /= 10; 
	*opcode = op%10; 
} 

int 
main(void) { 
	int ram[1005]; 
	int reg[15]; 
	char line[256]; 
	int num_instr, flag, pos; 
	int opcode, d, s; 
	int sum; 

	memset(ram, 0, 1005*sizeof(int));

	fgets(line, 256, stdin); 
	sscanf(line, "%d", &num_instr); 
	fgets(line, 256, stdin); 

	while (num_instr > 0) { 
		num_instr--;
		pos = 0; 
		do { 
			if (! fgets(line, 256, stdin)) 
				break; 
			line[strlen(line)-1] = '\0'; 

			ram[pos++] = atoi(line); 
		} while (strlen(line) > 0); 

		memset(reg, 0, 15*sizeof(int)); 
		pos = flag = sum = 0; 
		while ( !flag ) { 
			sum++; 

			deal_in(ram[pos], &opcode, &d, &s); 

			switch(opcode) { 
				case 1: 
					flag = 1; 
					break; 
				case 2: 
					reg[d] = s; 
					pos++; 
					break; 
				case 3: 
					reg[d] = (reg[d]+s)%1000; 
					pos++; 
					break; 
				case 4: 
					reg[d] = (reg[d]*s)%1000; 
					pos++; 
					break; 
				case 5: 
					reg[d] = reg[s]; 
					pos++; 
					break; 
				case 6: 
					reg[d] = (reg[s]+reg[d])%1000; 
					pos++; 
					break; 
				case 7: 
					reg[d] = (reg[s]*reg[d])%1000; 
					pos++; 
					break; 
				case 8: 
					reg[d] = ram[reg[s]]; 
					pos++; 
					break; 
				case 9: 
					ram[reg[s]] = reg[d]; 
					pos++; 
					break; 
				case 0: 
					if (reg[s] != 0) 
						pos = reg[d]; 
					else 
						pos++; 
					break; 
			} 
		} 
	printf("%d\n%s", sum, (num_instr)?"\n":""); 
	
	} 

return 0; 
} 