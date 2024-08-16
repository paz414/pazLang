# pazLang

pazLang is a simple virtual machine and lexer implementation. It includes a custom assembly language (pazasm) and a stack-based virtual machine.

## Components

1. **Lexer**: Tokenizes the input code.
2. **Compiler**: Compiles pazasm code into bytecode.
3. **Virtual Machine**: Executes the compiled bytecode.

## Project Structure

pazLang
* pazasm
    * pazasm.cpp > _**Main compiler for pazasm**_
    * lexer.cpp  > _**Lexer implementation**_
    * lexer.h   >  _**Lexer header file**_
* stack-vm
    * main.cpp  > _**Entry point for the virtual machine**_
    * vm.cpp   > _**Virtual machine implementation**_
    * vm.h  >  _**Virtual machine header file**_

### pazasm (Assembler/Lexer)

1. pazasm.cpp
   - Main compiler for pazasm
   - Includes functions for compiling, mapping instructions, and handling file I/O
   - Uses the Lexer class to tokenize input

2. lexer.cpp
   - Implements the Lexer class
   - Contains the lex() function to tokenize input strings
   - Handles various states like START, READCHAR, READBLOCK, etc.

3. lexer.h
   - Defines the Lexer class and its methods
   - Declares enums for lexer states
   - Defines type aliases like 'byte' and 'strings'

### stack-vm (Virtual Machine)

1. main.cpp
   - Entry point for the virtual machine
   - Reads bytecode from a file and loads it into the VM
   - Initializes and runs the StackVM

2. vm.cpp
   - Implements the StackVM class
   - Defines instruction format and execution logic
   - Includes methods for fetching, decoding, and executing instructions

3. vm.h (implied, not provided in the initial code)
   - Would contain the StackVM class declaration
   - Define necessary types and constants for the VM


## Building

To build the project, you'll need a C++ compiler that supports C++11 or later. Use the following commands:

```
# Build pazasm


# Build stack-vm

```

## Usage
Compiling pazasm code
```
./pazasm <input_file>
```

This will generate an ```a.out``` file containing the compiled bytecode.

## Running bytecode



## pazasm Language
pazasm is a simple stack-based assembly language. It supports the following operations:
```
 + > Addition
 - > Subtraction
 * > Multiplication
 / > Division
```

Numbers are pushed onto the stack, and operations are performed on the top elements of the stack.

##Example:
```
5
3
+
2
*
```
This program pushes 5 and 3 onto the stack, adds them, then multiplies the result by 2.

## Virtual Machine
The VM is stack-based and uses 32-bit instructions. The instruction format is:

* 2 bits for the type of operation
* 30 bits for the data

## Types of operations:

* 0: positive number
* 1: primitive instruction
* 2: negative number
* 3: undefined

## Future Improvements

* Add more operations to the VM
* Implement error handling and debugging features
* Extend the language with variables and control structures

## Contributing
Contributions are welcome! Please feel free to submit a Pull Request.
## License
MIT License
