This is a basic starting point for Harvard Extension [CSCIE-93 Computer Architecture](http://sites.fas.harvard.edu/~cscie287/) students to develop a MIPS-like assembler written in C. Input validation, error checking, and support for labels, data blocks, etc are up to you to implement.

## Instruction Set

This assembler supports 16-bit MIPS-like instructions.

R-Type instructions
```
[   opcode   ][    rs    ][    rt    ][ funccode ]
[   4 bits   ][  4 bits  ][  4 bits  ][  4 bits  ]
```
Included R-Type Instructions:
```
add: opcode 0x0, funccode 0x0
```

I-Type instructions
```
[   opcode   ][    rs    ][       immediate      ]
[   4 bits   ][  4 bits  ][        8 bits        ]
```
Included I-Type Instructions:
```
li:  opcode 0x1
```

Example:
```
li  $r0, 0x2
li  $r1, 0x3
add $r0, $r1

would output

0000 : 1002
0001 : 1103
0002 : 0010
```

Instructions are output to a MIF file.

## Installation Instructions

To build the assembler:

```make```

To run the assembler:

```./assembler <input>.asm <output>.mif```

To clean up the directory:

```make clean```

## Testing
Unit testing is provided through [CUnit](http://cunit.sourceforge.net/). Feel free to replace this with a different unit testing framework of your choice. 
CUnit can be installed on Mac via Homebrew:

```brew install cunit```

To run tests:

```make test```

