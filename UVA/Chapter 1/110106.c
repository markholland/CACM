#include <stdio.h>
#include <stdlib.h>

#define MAX_REGISTERS 15
#define MAX_RAM 1005
#define MAX_WORDS 3



int nthdigit(int x, int n)
{
    while (n--) {
        x /= 10;
    }
    return (x % 10);
}

int main() {

	int num_cases, num_instr, m, i, j, instr, d, n;
	int halt;
	int current_ram;
	int k;
	
	int registers[MAX_REGISTERS];
	int ram[MAX_RAM];

	memset(ram, 0, MAX_RAM*sizeof(int));

	if( scanf( "%d\n", &num_cases ) == 1 ) {
		scanf("\n");
		// Reserve and initialize registers
		registers = malloc(MAX_REGISTERS * sizeof *registers);

		ram = malloc(MAX_RAM * sizeof *ram);
		for (i=0; i<MAX_RAM; i++) {
			ram[i] = malloc(MAX_WORDS * sizeof *ram[i]);
		}

		newArray(registers);
		newMultiArray(ram);

		for( i = 0; i < num_cases; i++) {
			num_instr = 0;
			halt = 0;
			current_ram = 0;

			// New instructions
			while ( !halt && scanf( "%1d%1d%1d", &instr, &d, &n) == 3) {
				printf("%d",instr);
				if(instr == 1) {
					//halt = 1;
					//num_instr++;
				} else {
					ram[current_ram][0] = instr;
					ram[current_ram][1] = d;
					ram[current_ram][2] = n;
					current_ram++;
					printf("%d%d%d\n", instr, d, n);
					printf("%d",current_ram);
				} 
				printf("halt: %d", halt);
			}
			printf("here");

			j = 0;
			while (j < current_ram) {

				switch(ram[j][0]) {
					printf("%d%d%d", ram[j][0], ram[j][1], ram[j][2]);
					case 1:
						halt = 1;
						num_instr++;
						break;
					case 2:
						registers[ram[j][1]] = ram[j][2];
						num_instr++;
						break;
					case 3:
						registers[ram[j][1]] += ram[j][2];
						num_instr++;
						break;
					case 4:
						registers[ram[j][1]] *= ram[j][2];
						num_instr++;
						break;
					case 5:
						registers[ram[j][1]] = registers[ram[j][2]];
						num_instr++;
						break;
					case 6:
						registers[ram[j][1]] += registers[ram[j][2]];
						num_instr++;
						break;
					case 7:
						registers[ram[j][1]] *= registers[ram[j][2]];
						num_instr++;
						break;
					case 8:
						registers[ram[j][1]] += *ram[registers[ram[j][2]]];
						num_instr++;
						break;
					case 9:
						
						for( k=0; k<MAX_WORDS; k++) {
							ram[registers[ram[j][2]]][k] = nthdigit(registers[ram[j][1]], MAX_WORDS-k);
						}
						num_instr++;
						break;
					case 0:
						if(registers[ram[j][1]]) {

							j = registers[ram[j][1]];
						}
						num_instr++;
						break;

				}
				j++;
			}
			printf("%d\n\n", num_instr);

		}

	}

	//deallocate
	free(registers);

	//deallocate
	for(i=0; i<MAX_RAM; i++) {
		free(ram[i]);
	}
	free(ram);
}
