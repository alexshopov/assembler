#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "instructions.h"

int setRegister(char *reg) {
	char last = reg[strlen(reg) - 1];
	if (last == ',' || last == '\n') {
		reg[strlen(reg) - 1] = '\0';	// remove the comma or newline at the end of the token
	}
	
	if (strcmp(reg, "$r1") == 0) {
		return REG_1;
	} else if (strcmp(reg, "$r2") == 0) {
		return REG_2;
	}

	return -1;
}

int setImmediate(char *immediate) {
	return (int)strtol(immediate, NULL, 16);
}

int printRType(struct Instruction *instruction, char *buffer) {
	sprintf(buffer, "%04d : %d%d%d%d", instruction->address, instruction->opcode, instruction->r1, instruction->r2, instruction->funccode);
	return 0;
}

int printIType(struct Instruction *instruction, char *buffer) {
	sprintf(buffer, "%04d : %d%d%02d", instruction->address, instruction->opcode, instruction->r1, instruction->immediate);
	return 0;
}

int parseInstruction(char *line, struct Instruction *instruction) {
	char *token = strtok(line, " "); 

	if (strcmp(token, "add") == 0) {
		instruction->type = R_TYPE;
		instruction->opcode = OPCODE_ALU;
		instruction->r1 = setRegister(strtok(NULL, " "));
		instruction->r2 = setRegister(strtok(NULL, " "));
		instruction->funccode = FUNC_ADD;
	} else if (strcmp(token, "li") == 0) {
		instruction->type = I_TYPE;
		instruction->opcode = OPCODE_LI;
		instruction->r1 = setRegister(strtok(NULL, " "));
		instruction->immediate = setImmediate(strtok(NULL, " "));
	} else {
		return -1;
	}

	return 0;
}
