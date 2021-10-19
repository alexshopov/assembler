#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assembler.h"
#include "constants.h"

int main(int argc, char **argv) {
	FILE *in, *out;
	char * line = NULL;
    size_t len = 0;
    int read;
	int programcounter = 0;

	in = fopen(argv[1], "r");

	struct Instruction *head = NULL;
	struct Instruction *current = NULL;
	while ((read = getline(&line, &len, in)) != -1) {
		if (head == NULL) {
			head = mallocInstruction();
			current = head;
		} else {
			current->next = mallocInstruction();
			current = current->next;
		}

		programcounter = parseLine(line, programcounter, current);
    }

	out = fopen(argv[2], "w");
	writeMIF(out, head);

	fclose(in);
	fclose(out);

	return 0;
}

int parseLine(char *line, int programcounter, struct Instruction *instruction) {
	instruction->address = programcounter;
	parseInstruction(line, instruction);

	return ++programcounter;
}

int writeMIF(FILE *fp, struct Instruction *instruction) {
	struct Instruction *current = instruction;
	char buffer[13];

	while (current != NULL) {

		if (current->type == R_TYPE) {
			sprintRType(current, buffer);
		} else if (current->type == I_TYPE) {
			sprintIType(current, buffer);
		}

		fprintf(fp, "%s\n", buffer);

		current = current->next;
	}

	return 0;
}
