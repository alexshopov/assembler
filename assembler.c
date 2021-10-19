#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assembler.h"
#include "constants.h"

struct Instruction *head = NULL;
struct Instruction *current = NULL;

int main(int argc, char **argv) {
	FILE *in, *out;
	char * line = NULL;
    size_t len = 0;
    int read;
	int programcounter = 0;

	in = fopen(argv[1], "r");

	head = (struct Instruction*) malloc(sizeof(struct Instruction));
	current = head;
	while ((read = getline(&line, &len, in)) != -1) {
		programcounter = parseLine(line, programcounter, current);
		current = current->next;
    }

	out = fopen(argv[2], "w");

	current = head;
	char buffer[13];
	int i = 0;
	while (current != NULL) {

		if (current->type == R_TYPE) {
			printRType(current, buffer);
		} else if (current->type == I_TYPE) {
			printIType(current, buffer);
		}

		if (current->address != -1) {
			fprintf(out, "%s\n", buffer);
		}

		current = current->next;
	}

	fclose(in);
	fclose(out);

	return 0;
}

int parseLine(char *line, int programcounter, struct Instruction *instruction) {
	if (instruction == NULL) {
		instruction = (struct Instruction*) malloc(sizeof(struct Instruction));
	}

	instruction->address = programcounter;
	parseInstruction(line, instruction);

	instruction->next = (struct Instruction*) malloc(sizeof(struct Instruction));
	instruction->next->address = -1;

	programcounter++;

	return programcounter;
}

