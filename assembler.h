#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "instructions.h"

int parseLine(char *line, int programcounter, struct Instruction *instruction);
int writeMIF(char *filename, struct Instruction *instruction);

#endif
