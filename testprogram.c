#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "instructions.h"
#include "constants.h"

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

void add_instruction(char *buffer) {
    struct Instruction *instruction = (struct Instruction*) malloc(sizeof(struct Instruction));
	instruction->address = 0;

	parseInstruction(buffer, instruction);

    if (instruction->type == R_TYPE) {
        printRType(instruction, buffer);
    } else if (instruction->type == I_TYPE) {
        printIType(instruction, buffer);
    }
}

void test_r_type(void) {
    char buffer[15];
    sprintf(buffer, "add $r1, $r2");
    char *expected = "0000 : 0010";

    add_instruction(buffer);

    if (strcmp(buffer, expected) != 0) {
        printf("test_r_type failed: %s != %s\n", buffer, expected);
        CU_FAIL();
    } else {
        CU_PASS();
    }
}

void test_i_type(void) {
    char buffer[15];
    sprintf(buffer, "li $r2, 0x2");
    char *expected = "0000 : 1102";

    add_instruction(buffer);

    if (strcmp(buffer, expected) != 0) {
        printf("test_i_type failed: %s != %s\n", buffer, expected);
        CU_FAIL();
    } else {
        CU_PASS();
    }
}

int main (void)// Main function
{
    CU_pSuite pSuite1 = NULL;

    // Initialize CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Add suite1 to registry
    pSuite1 = CU_add_suite("Basic_Test_Suite1", init_suite, clean_suite);
    if (NULL == pSuite1) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    //add test_r_type to suite1
    if ((NULL == CU_add_test(pSuite1, "\n\n……… Testing instruction function……..\n\n", test_r_type))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    //add test_i_type to suite1
    if ((NULL == CU_add_test(pSuite1, "\n\n……… Testing instruction function……..\n\n", test_i_type))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_tests();// OUTPUT to the screen

    CU_cleanup_registry();//Cleaning the Registry
    return CU_get_error();
}
