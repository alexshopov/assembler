This is a basic starting point for a MIPS-like assembler written in C.

##Instruction Set

This assembler supports 16-bit MIPS-like instructions.

R-Type instructions
[   opcode   ][    r1    ][    r2    ][ funccode ]
[   4 bits   ][  4 bits  ][  4 bits  ][  4 bits  ]

I-Type instructions
[   opcode   ][    r1    ][       immediate      ]
[   4 bits   ][  4 bits  ][        8 bits        ]


Instructions are output to a MIF file.


##Installation Instructions

To build the assembler:
```make```

To run the assembler:
```./assembler <input>.asm <output>.mif```

Unit testing is provided through CUnit. CUnit can be installed on Mac via Homebrew
```brew install cunit```

To run tests:
```make test```

To clean up the directory:
```make clean```