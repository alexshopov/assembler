#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assembler.h"
#include "constants.h"

int main(int argc, char **argv) {
	FILE *in;
	char *line = NULL;
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

	fclose(in);

	writeMIF(argv[2], head);

	return 0;
}

int parseLine(char *line, int programcounter, struct Instruction *instruction) {
	instruction->address = programcounter;
	parseInstruction(line, instruction);

	return ++programcounter;
}

int writeMIF(char *filename, struct Instruction *instruction) {
	FILE *fp = fopen(filename, "w");
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

	fclose(fp);

	return 0;
}
