This is a basic starting point for Harvard Extension [CSCIE-93 Computer Architecture](http://sites.fas.harvard.edu/~cscie287/) students to develop a MIPS-like assembler written in C. Input validation, error checking, labels, 
and support for labels, data blocks, etc are up to you to implement.

## Instruction Set

This assembler supports 16-bit MIPS-like instructions.

R-Type instructions
```
[   opcode   ][    rs    ][    rt    ][ funccode ]
[   4 bits   ][  4 bits  ][  4 bits  ][  4 bits  ]
```

I-Type instructions
```
[   opcode   ][    rs    ][       immediate      ]
[   4 bits   ][  4 bits  ][        8 bits        ]
```
Example:
```
li  $r1, 0x2
li  $r2, 0x3
add $r1, $r2
```

Instructions are output to a MIF file.

## Installation Instructions

To build the assembler:

```make```

To run the assembler:

```./assembler <input>.asm <output>.mif```

Unit testing is provided through [CUnit](http://cunit.sourceforge.net/doc/index.html). CUnit can be installed on Mac via Homebrew:

```brew install cunit```

To run tests:

```make test```

To clean up the directory:

```make clean```
