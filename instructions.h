#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

struct Instruction {
	int address;
	int type;
	int opcode;
	int r1;
	int r2;
	int immediate;
	int funccode;

	struct Instruction *next;
};

int setRegister(char *reg);
int setImmediate(char *immediate);
int printRType(struct Instruction *instruction, char *buffer);
int printIType(struct Instruction *instruction, char *buffer);
int parseInstruction(char *line, struct Instruction *instruction);

#endif
