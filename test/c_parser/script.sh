#!/bin/bash

NAME=c_parser

LEXER=${NAME}.l;
CPP=${NAME}.cpp;
EXE=${NAME}

cd ..
cd ..
make bin/c_parser


for TEST in test/c_parser/*.c
do
	echo "Processing $TEST file.."
	cat $TEST | ./bin/${EXE}
done
