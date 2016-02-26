# Language Processors 2015 CW - bak14

--- 

## Description

This is a work-in-progress C90 to MIPS32 compiler. Currently only the tokeniser and parser have been completed.

## Usage

Use the makefile to create the parser and input C code into stdin, this will produce a stream of output, indicating the functions and variables that have been declared as well as the current scope.

For instance, if the following C code is the input:

    int main() {
		int x;
		return 0;
	}
	int f(int a, int b) {
		return a+b;
	}

The output will be:

	FUNCTION : main
	SCOPE
	    VARIABLE : x
	FUNCTION : f
	    PARAMETER : a
	    PARAMETER : b
	SCOPE


## Tests

Run the shell script in the test folder to view the output of all C files in that folder.