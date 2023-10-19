## Monty Intepreter

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. Monty Intepreter is a languange used to inteprete Byte code Files.


## Table of Contents

- [Project Title](#Monty-Intepreter)
- [Table of Contents](#table-of-contents)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
- [Opcodes](#opcodes)
- [ByteCodes](#Bytecode-File)
- [Running the Tests](#running-the-tests)
- [Built With](#built-with)
- [Authors](#authors)

## Getting Started

These instructions will help you set up the project locally, for development and testing purposes.

### Prerequisites

List down the things you need to install beforehand and how to install them.

i. Clone this repo

```
  git clone https://github.com/timmySpark/Playground.git
```

ii. Compile the codes 

```
  gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

iii. Run the script

```
  ./monty text
```

## Opcodes

Below are some of the opcodes that work with this Monty Intepreter:-

### Push 
This opcode pushes an element to the stack

```
  push <integer>
```
### Pall 
The opcode pall prints all the values on the stack, starting from the top of the stack.
```
  pall
```

### Pint 
The opcode pint prints the value at the top of the stack, followed by a new line.
```
  pint
```

### Pop
The opcode pop removes the top element of the stack.
```
  pop
```

### Swap 
The opcode swap swaps the top two elements of the stack.
```
  swap
```

### Add 
The opcode add adds the top two elements of the stack.
```
  Add
```


### nop 
The opcode nop doesn’t do anything.
```
  nop
```


### sub 
The opcode sub subtracts the top element of the stack from the second top element of the stack.
```
  sub
```

### Div 
The opcode div divides the second top element of the stack by the top element of the stack.
```
  div
```

### Mul 
The opcode mul multiplies the second top element of the stack with the top element of the stack.
```
  mul
```

### Mod 
The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.
```
  mod
```

## Bytecode File

Text file contains certain bytecodes the monty bytecode reads and intepretes, you can edit it to your taste

```
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
```

## Running the Tests

Explain how to run the automated tests for this system.

```
coming soon ...
```
 

## Built With

- C Programming Language.

## Authors

- **Timmy** - Developer - [timmySpark](https://github.com/timmySpark)
- **Wondahs** - Developer - [Wondahs](https://github.com/Wondahs)

