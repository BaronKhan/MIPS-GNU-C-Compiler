#!/bin/bash

NAME=bin/c_codegen

LEXER=${NAME}.l;
CPP=${NAME}.cpp;
EXE=${NAME}

cd ../..
bison -d src/c_parser.y -o src/c_parser.tab.cpp
flex -o src/c_lexer.yy.cpp src/c_lexer.l
g++ src/c_parser.tab.cpp src/c_lexer.yy.cpp src/c_ast.cpp src/c_codegen.cpp -o ${NAME}


for TEST in test/c_codegen/*.c
do
	echo "Processing $TEST file.."
	cat $TEST | ./${EXE} > test/c_codegen_results/$TEST.s
done
